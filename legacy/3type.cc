
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

#include "3type.h"
#include "genprob.h"
#include "evalprob.h"
#include "mixtool.h"
#define TYPEMASK ((1 << NTYPES) - 1)

#ifndef __GNUC__
enum bool {true, false};
#define random rand
#define srandom srand
#endif

/*
	Routines for printing a puzzle nicely
 */

void printprob(FILE* f, int a[], char ops[], char set[])
{
	char s[10][9], *p;
	int j;
	for (j=1; j<10; j++) {
		p = _itoa(a[j], s[j], 10);
		while(*p) { *p = set[ctod(*p)]; p++; }
	}
	fprintf(f, "\t\t\t%6s %c%6s = %6s\n", s[1], ops[0], s[2], s[3]);
	fprintf(f, "\t\t\t%6c  %6c   %6c\n", ops[1], ops[2], ops[3]);
	fprintf(f, "\t\t\t%6s %c%6s = %6s\n", s[4], ops[4], s[5], s[6]);
	fprintf(f, "\t\t\t%6s  %6s   %6s\n", "=", "=", "=");
	fprintf(f, "\t\t\t%6s %c%6s = %6s\n", s[7], ops[5], s[8], s[9]);
}

void TeXprob(FILE* f, int a[], char ops[], char set[])
{
	char s[10][9], *p;
	int j;
	for (j=1; j<10; j++) {
		p = _itoa(a[j], s[j], 10);
		while(*p) { *p = set[ctod(*p)]; p++; }
	}
	fprintf(f, "\\eqtable{");
	fprintf(f, "\t& %6s&%c& %6s  &=& %6s\\cr\n", s[1], ops[0], s[2], s[3]);
	fprintf(f, "\t\t& %6c& & %6c  & & %6c\\cr\n", ops[1], ops[2], ops[3]);
	fprintf(f, "\t\t& %6s&%c& %6s  &=& %6s\\cr\nhrule\n", s[4], ops[4], s[5], s[6]);
	fprintf(f, "\t\t& %6s&%c& %6s  &=& %6s\\cr}\n\n", s[7], ops[5], s[8], s[9]);
}


#define LOGFILE "equator.lgf"
#define LOGMASK "%9ld %6d %2d %3d..%d:%d %1d" \
			" %c%c%c%c%c%c%c%c%c%c %s:\n" \
		        "  %c%c%c%c%c%c" \
			" : %6d %6d=%6d : %6d %6d=%6d : %6d %6d=%6d :\n"
#define LOGRMASK1 "%9ld %6d %2d %3d..%d:%d %1d %c%c%c%c%c%c%c%c%c%c %[^:]:"
#define LOGRMASK2 "  %c%c%c%c%c%c : %6d %6d=%6d : %6d %6d=%6d : %6d %6d=%6d :"

void logfile(char *dfield, char ops[], char set[], int a[], 
		int w, int seed, int type, int level, int leveL, bool SwapFlag)
{
	FILE * f = fopen(LOGFILE, "a");
	time_t dr;
	if (f) {
		dr = time(NULL);
		fprintf(f,LOGMASK, dr,
			seed, type, level, leveL, w, SwapFlag, 
			set[0],set[1], set[2], set[3], set[4], 
			set[5], set[6], set[7], set[8], set[9],
			dfield,
			ops[0], ops[1], ops[2], ops[3], ops[4], ops[5], 
			a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]
			);
		fclose(f);
	} else {
		fprintf(stderr, "Error, can't access logfile <%s>.\n", LOGFILE);
	}
}

#define MAXL 127

bool logscan(char *dfield2, char ops2[], char set2[], int a2[],
		int w2, int seed2, int type2, int level2, int leveL2, bool SwapFlag2, bool talk=false)
{
        char dfield[MAXL], ops[7], set[10];
        int a[10], w, seed, type, level, leveL, entry = 0, SwapFlag;
        char inl1[MAXL], inl2[MAXL];

	FILE * f = fopen(LOGFILE, "r");
	time_t dr;
	if (f) {
	    while( fgets(inl1, MAXL, f) )
            {   
                if (!fgets(inl2, MAXL, f) ) {
                        fprintf(stderr,"Logfile `%sÔ ist bîse kaputt!!!\n", LOGFILE);
                        exit(0);
                }
                entry++;
                sscanf(inl1,LOGRMASK1, &dr,
			&seed, &type, &level, &leveL, &w, &SwapFlag,
			&set[0], &set[1], &set[2], &set[3], &set[4],
			&set[5], &set[6], &set[7], &set[8], &set[9],
			dfield);
                sscanf(inl2,LOGRMASK2,
			&ops[0], &ops[1], &ops[2], &ops[3], &ops[4], &ops[5],
			&a[1], &a[2], &a[3], &a[4], 
			&a[5], &a[6], &a[7], &a[8], &a[9]
			);
                if ( ops[0]==ops2[0] && ops[1]==ops2[1] && ops[2]==ops2[2]
                  && ops[3]==ops2[3] && ops[4]==ops2[4] && ops[5]==ops2[5]
                  && a[1] == a2[1] && a[2] == a2[2] && a[3] == a2[3]
                  && a[4] == a2[4] && a[5] == a2[5] && a[6] == a2[6]
                  && a[7] == a2[7] && a[8] == a2[8] && a[9] == a2[9]
                    )
                {
                        printf("\nKollision: Aufgabe schon einmal erzeugt (line %d) fÅr %s mit <%c%c%c%c%c%c%c%c%c%c>.\n",
				2*entry-1, dfield,
				set[0], set[1], set[2], set[3], set[4],
				set[5], set[6], set[7], set[8], set[9]);
	            	printf(LOGMASK, dr,
				seed, type, level, leveL, w, SwapFlag,
				set2[0], set2[1], set2[2], set2[3], set2[4],
				set2[5], set2[6], set2[7], set2[8], set2[9],
				dfield2,
				ops[0], ops[1], ops[2], ops[3], ops[4], ops[5],
				a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
                        return true;
                }
            }
	    fclose(f);
	} else {
		fprintf(stderr, "Error, can't access logfile <%s>.\n", LOGFILE);
	}
        return false;
}

void Usage(char * argv0)
{
	fprintf(stderr, 
	"\n\n"
	"\n FSN equator generator (c) 2.95 Frank Sven Nestel"
	"\n"
	"\n The legal options are:"
	"\n"
	"\n	-h -?	This help message."
	"\n	-l n	set min level (default = 50, range 0..100)."
	"\n	-L n    set max level (default = 95, range l..100)."
	"\n	-t n*	set type of equator, 0,..,%d."
	"\n	-s n	seed the random number generator (default = time)."
	"\n	-a	show the answer not the problem."
	"\n	-b 	both: answer and problem."
	"\n	-n	no swapping, show basic problem generated."
	"\n	-D a	generate a logfile entry with Dfield a."
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
	int a[10], i, r = 0, w = 0;
	char set[11], ops[6], *dfield = NULL;
	int c;

	// Parameters may be changed by commandline
	long int seed = 0;
	int type = 0, level = 80, leveL=95, SolMode = 0;
	bool SwapFlag=true;

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
		 case 'D' :
		  	dfield = strdup(optarg);	
			break;
		 case 'l':
		  	level = atoi(optarg);
			if (level > 100) level = 100;
			else if (level < 0) level = 0;
			if (leveL < level) leveL = level;
			break;
		 case 'L':
		  	leveL = atoi(optarg);
			if (leveL > 100) leveL = 100;
			else if (leveL < 0) leveL = 0;
			if (leveL < level) level = leveL;
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
	printf("Seed = %6ld, typemask = %2X, level = %+3d..%3d\n", 
		seed, type, level, leveL);
	srandom(3*seed+1);

	// Prepare some shuffled letters
	rset(RAND(0,999), set);
	for (i=0; i < 10; i++) set[i] += 'A';

	// Generate one legal equator
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
    	    if (r) w = evaluate(a, ops);
        } while (!r || w < level || w > leveL 
              || (dfield && logscan(dfield, ops, set, a, w, seed, type, level, leveL, SwapFlag) )
           );

	if (dfield) {
		printf("Destination is: %s\n", dfield);
		logfile(dfield, ops, set, a, w, 
			seed, type, level, leveL, SwapFlag);
	}

	// Shuffle the numbers arround a bit
        if (SwapFlag) swappy(a, ops);

	// Print out problem and/or solution
	if (SolMode  > 0) printprob(stdout, a, ops,"0123456789");
	if (SolMode == 1) printf("\n");
	if (SolMode  < 2) {
		printprob(stdout, a, ops, set);
	}
	if (dfield) {
		FILE *f = fopen("equator.tex", "w");
		TeXprob(f, a, ops, set);
		TeXprob(f, a, ops, "0123456789");
		fclose(f);
	}
	printf("Estimated level = %3d.\n", w);
	return 1;
}
