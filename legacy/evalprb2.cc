
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
	Mechanics to estimate level of puzzle
 */
#include <string.h>
#include <stdlib.h>
#include "3type.h"
#include "evalprob.h"

const int FIXVAL  = 90;
const int ZEROVAL = 50;
const int MINSCORE = -400;
const int BASEVAL = 420;

// Evaluate number of digits in problem, remember less than 7 digits reduces
// the problem to an algebraic system!
//                   0   1,2,3,4,5,6,  7, 8,  9, 10
const int ndval[11]={0,  1,2,3,4,5,6, 50,80,100,100};

int ndig;

int eval2(int a, char o, int b, int c, int used[])
{
	int w = 0;
	char sa[10], sb[10], sc[10]; int lb, lc, la;
	switch(o)
	{
	 // First standardize the problem, then evaluate
	 case	'-' : return eval2(b,'+',c,a,used);
	 case	'/' : return eval2(b,'x',c,a,used);
	 case	'+' : if (a > b) swap(a,b);
		lb = strlen(_itoa(b, sb, 10));
		lc = strlen(_itoa(c, sc, 10));
		la = strlen(_itoa(a, sa, 10));
		if (lodig(a)==0 || lodig(b)==0) 	w -=200;
		if (lb < lc)				w -=200;
		if (lb < lc && la < lb) 		w -=200;
		if (lb == lc && sb[0] < sc[0] 
		 && sb[1] == sc[1])			w -=200;
		if (a < 10) 				w -= 90;
		// Was <= 10, but 10 is evaluated to often to be so easy!
		if (sc[0] == '2')			w -= 60;
		if (lodig(a)==5 && lodig(b)==5)	w -= 60;
		if (la < lb)				w -= 43;
		if (a == b)				w -= 43;
		if (lb == lc && sb[0] < sc[0]) 	w -= 39;
		if (la == lb && sa[0] == sb[0]) 	w -= 39;
		if (lodig(a)==lodig(b))		w -= 27;
		if (sc[0] == '3')			w -= 21;
		if (lodig(c)==0)			w += 21;
	        if (lodig(a)+lodig(b) > 9)		w += 20;
		if (dig2(a)==dig2(b) 
		 && dig2(b)==dig2(c) )			w -= 15;
		if (lodig(a) > 5 || lodig(b) > 5)	w += 10;
	        break;
	 case	'x' : if (a > b) swap(a,b);
		lb = strlen(_itoa(b, sb, 10));
		lc = strlen(_itoa(c, sc, 10));
		la = strlen(_itoa(a, sa, 10));
		if (a ==  0)				w -=200;
		if (dig2(a)==1 && dig2(b)==1
		    && a < 100 && b < 100 && c < 1000
		    && dig3(c) ==1)			w -=119;
	 	if (a <= 10)				w -=115;
		if (sb[0] == sc[0] || sa[0] == sc[0])	w -= 80;
		if (c > 100000 && b < 1000 && a > 800)	w -= 69;
		if (c > 10000 && b < 1000 && a > 80)	w -= 69;
		if (lodig(a)< 2 || lodig(b) <2) 	w -= 50;
		if (dig2(a)==dig2(b) && b < 100)	w -= 50;
		if (a == b)				w -= 35;
		if (dig2(a)==1 && dig2(b)==1
		  && a < 100 && b < 100)        	w -= 35;
		if (a % 11 == 0 || b % 11 == 0) 	w -= 35;
		if (lodig(a)==lodig(c) 
		 || lodig(b)==lodig(c))		w -= 30;
		if (lodig(a)==0 || lodig(b)==0)	w -= 30;
		if (used[lodig(a)]==1
		 || used[lodig(b)]==1
		 || used[lodig(c)]==1)			w += 25;
		if (lodig(a)==lodig(b))		w -= 15;
		if (lodig(a)==5 || lodig(b)==5) 	w -= 10;
		if (lodig(a)==7 || lodig(b)==7) 	w +=  8;
		if (lodig(a)==3 || lodig(b)==3) 	w +=  5;
		if (lodig(a)==2 || lodig(b)==2) 	w -=  4;
		if (lodig(a)==6 || lodig(b)==6)	w -=  3;
	}
	if (w < MINSCORE)
		return MINSCORE;
	else
		return w;
}

int evaluate(int a[], char ops[])
{
	int used[10], len[10], i, j, h, hm, h2;
	int dif = 0;
	char tmp[10], *p;

	ndig = 0;
	for (j=0; j< 10; j++) used[j] = len[j] = 0;
	for (i=1; i < 10; i++) {
		p = _itoa(a[i], tmp, 10);
		j = strlen(tmp);
		len[j]++;
		while(*p) {
			h = ctod(*p++);
			if(!used[h]) ndig++;
			used[h]++;
		}
	}
	// Evaluate lengthiest numbers
	// This was rather a matter of beauty not of difficulty!
	// ??? if (len[6]+len[7]+len[8]+len[9]) dif -=  999; // To ugly
	if (h = len[5]+len[6]+len[7]+len[8]+len[9]) dif -= 31 - 5 * h;
	if (h = len[4]+len[5]+len[6]+len[7]+len[8]+len[9]) dif -= 10;
	// Evaluate existence and distribution of numbers
	dif += ndval[ndig];              	// How many different digits used
	if (used[0]) dif += 5 + 2*used[0]; 	// Lots of zeroes
	dif += 11 * used[7] + 9 * used[3];  	// Lots of sevens and three's
	dif -= 11 * used[1] + 4 * used[2];	// Few 1's and 2's
	for (j=1; j < 10; j++) {
		if (used[j] == 1) dif += 57;
		if (used[j] >  2) dif -= 10*(used[j]-2);
	}
	// Evaluate each equation by itself
	h = eval2(a[1], ops[0], a[2], a[3], used);
	dif += h;	      hm = h;        h2 = h;
	h = eval2(a[4], ops[4], a[5], a[6], used);
	dif += h; if (h > hm) hm = h; if (h < h2) h2 = h;
	h = eval2(a[7], ops[5], a[8], a[9], used);
	dif += h; if (h > hm) hm = h; if (h < h2) h2 = h;
	h = eval2(a[1], ops[1], a[4], a[7], used);
	dif += h; if (h > hm) hm = h; if (h < h2) h2 = h;
	h = eval2(a[2], ops[2], a[5], a[8], used);
	dif += h; if (h > hm) hm = h; if (h < h2) h2 = h;
	h = eval2(a[3], ops[3], a[6], a[9], used);
	dif += h; if (h > hm) hm = h; if (h < h2) h2 = h;
	// Special consideration:
	dif -= hm;   // Do not count the most difficult equation
	dif -= h2/2; // And count the easiest one only half!
	//
	dif += BASEVAL;
        // Finally truncate and norm the result between 0 and 100 incl.
	return ZEROVAL + 2 * (FIXVAL-ZEROVAL) * dif / ( (FIXVAL-ZEROVAL)*10 + abs(dif));
}

