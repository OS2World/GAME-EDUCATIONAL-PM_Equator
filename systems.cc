
/*
 PMEQUATOR -- a set of programs to generate, evaluate and solve number puzzles
 Copyright (C) 1995-2001 Frank Sven Nestel

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License as
 published by the Free Software Foundation; either version 2 of
 the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty
 of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 PURPOSE. See the GNU General Public License for more
 details.

 You should have received a copy of the GNU General Public
 License along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

 The license is in gpl-license.html

 To contact the author use on of those:

    Frank Sven Nestel,
    Wolfsstaudenring 32
    91056 Erlangen
    Germany

    dorisnfrank@bigfoot.com

    http://doris-frank.de

 Please look into the read.me file and ignore the old.* files!

 Enjoy.

*/


/*

	Equator - Generator

	(c) 1995 Frank Sven Nestel

	This program generates number puzzles of the form

		A1 . A2 = A3
		 .    .    .
		A4 . A5 = A6
		 .    .    .
		A7 . A8 = A9

	where each dot . represents one of the operations +,-,*,/
	and A1,..,A9 are appropriate integers. The digits in theese
	numbers are replaced by letters, and so on...

*/

#include <stdio.h> 
#include <stdlib.h>
#ifdef DJGPP
# include <bios.h>   // only for random seed
# include <dos.h>
#else
# include <getopt.h>
#endif
#include <time.h>

#include "systems.h"
#include "genprob.h"
#include "mixtool.h"
#define TYPEMASK ((1 << NTYPES) - 1)

#ifndef __GNUC__
enum bool {true, false};
#define random rand
#define srandom srand
#endif

#define INDEX(x) ((x) >= 'a' ? (x)-'a'+10 : (x)-'0')

int strict(int a[], int system)
{
	int used[MAXSYSTEM+1], j, misses=0;
	char *p, s[10][9];
	for (j=0; j < system; j++) used[j] = 0;
	for (j=1; j<10; j++) {
		p = _itoa(a[j], s[j], system);
		if (strlen(p) > 4) return 0;
		while(*p) { used[INDEX(*p)]++; p++; }
	}
	for (j=0; j < system; j++)
		if (!used[j]) misses++; 
	return misses <= system/10;
}

/*
	Routines for printing a puzzle nicely
 */

void printprob(FILE* f, int a[], char ops[], char set[], int system)
{
	char s[10][9], *p;
	int j;
	for (j=1; j<10; j++) {
		p = _itoa(a[j], s[j], system);
		while(*p) { *p = set[INDEX(*p)]; p++; }
	}
	fprintf(f, "\t\t\t%6s %c%6s = %6s\n", s[1], ops[0], s[2], s[3]);
	fprintf(f, "\t\t\t%6c  %6c   %6c\n", ops[1], ops[2], ops[3]);
	fprintf(f, "\t\t\t%6s %c%6s = %6s\n", s[4], ops[4], s[5], s[6]);
	fprintf(f, "\t\t\t%6s  %6s   %6s\n", "=", "=", "=");
	fprintf(f, "\t\t\t%6s %c%6s = %6s\n", s[7], ops[5], s[8], s[9]);
}


void Usage(char * argv0)
{
	fprintf(stderr, 
	"\n\n"
	"\n FSN equator generator (c) extra Version 5.95 Frank Sven Nestel"
	"\n"
	"\n The legal options are:"
	"\n"
	"\n	-h -?	This help message."
	"\n	-t n*	set type of equator, 0,..,%d."
	"\n	-s n	seed the random number generator (default = time)."
	"\n	-a	show the answer not the problem."
	"\n	-b 	both: answer and problem."
	"\n	-n	no swapping, show basic problem generated."
	"\n"
	"\n example:"
	"\n"
	"\n   %s -l 50 -t 02 -s 4711 -a"
	"\n"
	"\n Generate a level 50 problem of type 0 or 2 with seed 4711"
	"\n and show the answer."
	"\n"
	"\n Have fun !"
	"\n"
	, NTYPES-1, argv0
	);
}

/*
	 Dirty old main routine
 */

#define RAND(from, to) (from + (random()/2) % (to+1-from))
int main(int argc, char **argv)
{
	int a[10], i, r = 0;
	char set[MAXSYSTEM + 1], ops[6];
	int c;

	// Parameters may be changed by commandline
	long int seed = 0;
	int type = 0, SolMode = 0;
	bool SwapFlag=true;
	int system;

	printf(__FILE__ " compiled "__DATE__" "__TIME__ ", (c) by FSN 1995.\n");

	// Process the command line
	opterr = 0;
	while((c=getopt(argc, argv, "ht:l:L:s:anbD:")) != -1)
	{
		switch (c) 
		{
		 case '?' :
		 case 'h' : 
		 	Usage(argv[0]);
			return 0;
		 case 'n' :
		 	SwapFlag = false;
			break;
		 case 'a' : 
		 	SolMode = 2;
		 	break;
		 case 'b' :
		 	SolMode = 1;
			break;
		 case 't':
		 	for (i=0; i < strlen(optarg); i++)
		  		type |= 1 << (optarg[i]-'0');
			break;
		 case 's' :
			seed = atol(optarg);
			break;
		}
	}
	type &= TYPEMASK;
	if (!type) type = TYPEMASK;
	if (!seed) seed = time(NULL) % 100000;
	srandom(3*seed+1);


	// Which number system
	system = RAND(6, MAXSYSTEM);

	printf("Seed = %6ld, typemask = %2X, Base=%d\n", seed, type, system);

	// Prepare some shuffled letters
	rset(RAND(0,999), set, system);
	for (i=0; i < system; i++) set[i] += 'A';

	do {
	    // Which type of puzzle to generate:
	    do { i = RAND(0,NTYPES - 1); } while( !(type & (1 << i)) );
	    switch (i) 
	    {
		case 0:
			r = genprob1(RAND(100,999),RAND(-49,49),RAND(-49,49),a,ops);
			break;
		case 1:
			r = genprob2(RAND(12,99), RAND(-49,99), RAND(12,399),a,ops);
			break;
		case 2:
			r = genprob3(RAND(12,99), RAND(12,99), RAND(1,9), a,ops);
			break;
		case 3: 
			r = genprob4(RAND(12,999), RAND(12,49), RAND(1,49), a,ops);
			break;
	    }
        } while (!r || !strict(a, system));

	// Shuffle the numbers arround a bit
        if (SwapFlag) swappy(a, ops);

	// Print out problem and/or solution
	if (SolMode  > 0) {
		printprob(stdout, a, ops, "0123456789", 10);
		printf("\n");
		printprob(stdout, a, ops, "0123456789ABCDEF", system);
	}
	if (SolMode == 1) printf("\n");
	if (SolMode  < 2) {
		printprob(stdout, a, ops, set, system);
	}
	return 1;
}
