
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


#define INCL_DOSSEMAPHORES
#include <os2.h>

#include <stdlib.h>
#include <time.h>
#include "3type.h"
#include "genprob.h"
#include "evalprob.h"
extern int ndig;
#define TYPEMASK ((1 << NTYPES) - 1)

#ifndef __GNUC__
enum bool {true, false};
#define random rand
#define srandom srand
#endif

#include "pmgenprb.h"
#include "mixtool.h"

// Characteristics of an equator, this is the global version!!
int anr[10], coded[10], thelevel;
char ops[6], set[11];

int level, level2;

void genprob(void * dummy)
{
    int i, r = 0, w;
    long int seed;
    int anr2[10];    char ops2[6];
	
    seed = time(NULL) % 1000000;
    srandom(3*seed+1);

    do {
	// Generate one legal equator
	do {
    	    // Which type of puzzle to generate:
    	    i = RAND(0,NTYPES - 1);
	    switch (i) 
	    {
		case 0:
			r = genprob1(RAND(100,999),RAND(-49,49),RAND(-49,49),anr2,ops2);
			break;
		case 1:
			r = genprob2(RAND(12,99), RAND(-49,97), RAND(12,349),anr2,ops2);
			break;
		case 2:
			r = genprob3(RAND(12,99), RAND(12,99), RAND(1,9), anr2,ops2);
			break;
		case 3: 
			r = genprob4(RAND(12,999), RAND(12,49), RAND(1,49), anr2,ops2);
			break;
	    }
    	    if (r) w = evaluate(anr2, ops2) / 2; // To adjust range!
        } while (!r || w < level2 || w > level || ndig < 10
		 || anr2[1] > 9999 || anr2[2] > 9999 || anr2[3] > 9999
		 || anr2[4] > 9999 || anr2[5] > 9999 || anr2[6] > 9999
		 || anr2[7] > 9999 || anr2[8] > 9999 || anr2[9] > 9999
		);
	
	// Shuffle the numbers arround a bit

        swappy(anr2, ops2);

	ULONG d1;
	DosWaitEventSem(hev2, SEM_INDEFINITE_WAIT); // Shall we proceed?
	DosResetEventSem(hev2, &d1);

        // Store new puzzle
	DosRequestMutexSem(hmtx, SEM_INDEFINITE_WAIT);
	rset(RAND(0,499), set);
	thelevel = w;
        for (i=0; i <10; i++) {
                coded[i] = 1;
		anr[i] = anr2[i];
		if (i < 6) ops[i] = ops2[i];
	}
	DosReleaseMutexSem(hmtx);
	DosPostEventSem(hev);  // We are done
    } while (true);
}

