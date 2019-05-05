
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

const int TOPVAL  = 100; // Maximaler Wert der zurueckgegeben wird
const int ZEROVAL =  37; // Welcher Wert wird der primaeren Wertung 0 zugeordnet?
const int SMEAR   =  9; // Zusammenfassen von Wertungen < 0 oder > TOPVAL
const int TOPALPHA = 160 - ZEROVAL;
const int BOTALPHA = ZEROVAL + 80;
const int SUBVAL  = 240;
const int HARDMAX = 4;
const int BASEVAL = 500 + SUBVAL/HARDMAX;

// Evaluate number of digits in problem, remember less than 7 digits reduces
// the problem to an algebraic system!
//                   0   1,2,3,4,5,6,  7,  8,  9, 10
const int ndval[11]={0,  1,2,3,4,5,6,100,150,220,220};

int ndig;

int min(int a, int b)  { return a < b ? a : b; }
int max(int a, int b)  { return a > b ? a : b; }
int rdiv(int a, int b) { return (a + b/2) / b; }
#define HARD(nr, lv) { if (hard[nr] > lv) hard[nr] = lv; }
#define COUPLE(d1,d2) { int q = min(hard[d1],hard[d2]); \
			HARD(d2, min(q, 2)); \
			HARD(d1, min(q, 2)); \
		      }
#define SA(x) (sa[x] - '0')
#define SB(x) (sb[x] - '0')
#define SC(x) (sc[x] - '0')

int eval2(int a, char o, int b, int c, 
	  char sa[10], char sb[10], char sc[10], int hard[], int used[])
{
	int w = 0;
	int la, lb, lc;
	switch(o)
	{
	 case	'+' : 
		if (a > b) {
			swap(a,b);
			swap(sa,sb);
		}
		la = strlen(sa);
		lb = strlen(sb);
		lc = strlen(sc);
		if (lodig(a)==0 || lodig(b)==0) 	{ hard[0] = 0; w-= 50; }
		if (lb < lc)				{ hard[1] = 0; w-= 50; }
		if (lb < lc && la < lb) 		{ hard[9] = hard[0] = 0; w-= 50; }
		if (lb == lc && sb[0] < sc[0]
		 && (sb[1] == sc[1] || sa[1] == sc[1])) { COUPLE(9,0); w-= 25; }
		if (la < lb && lb==lc && sb[0] < sc[0]) { COUPLE(SB(0), SC(0)); w-=25; }
		if (lodig(a)==5 && lodig(b)==5)	{ COUPLE(5,0); w -= 25; }
		if (lodig(a)==lodig(b))		{ COUPLE(lodig(a), lodig(c)); w-=25; }
		if (lodig(a)==lodig(b))		{ COUPLE(lodig(a), lodig(c)); w-=25; }
		if (sc[0] == '2')			w -= 50;
		if (sa[0] == sb[0])			{ COUPLE(SA(0), SC(0)); w -= 25;}
		if (a == b)				w -= 43;
		if (lb == lc && sb[0] < sc[0]) 	w -= 39;
		if (la == lb && sa[0] == sb[0]) 	w -= 39;
		if (la < lb)				w -= 23;
		if (a < 10) 				w -= 23;
		if (sc[0] == '3')			w -= 20;
	        if (lodig(a)+lodig(b) > 9)		w += 20;
		if (dig2(a)==dig2(b) 
		 && dig2(b)==dig2(c) )			w -= 17;
		if (lodig(a) > 5 || lodig(b) > 5)	w +=  9;
	        break;
	 case	'x' : 
		if (a > b) {
			swap(a,b);
			swap(sa,sb);
		}
		la = strlen(sa);
		lb = strlen(sb);
		lc = strlen(sc);
		if (a ==  0 || a == 1)			{ hard[a] = 0; w -=50; }
		if (dig2(a)==1 && dig2(b)==1 
		    && a < 100 && b < 100 && c < 1000
		    && dig3(c) ==1)			{ HARD(1,2); w -=25; }
		if (lodig(c) == 0)			{ COUPLE(lodig(a),lodig(b)); w-=25; }
		if (la < lb -1 && lb == lc)		{ COUPLE(SB(1), SC(1)); w-=25; }
		if (a == 10 || b == 10 || a == 100
			|| b == 100 || b == 1000)	{ hard[0] = hard[1] = 0; w -= 100; };
		if (a < 10)				{ HARD(a,2); w -=25; }
		if (lodig(a)==lodig(b))		{ COUPLE(lodig(a), lodig(c)); w-=25; }
		if (sb[0] == sc[0] || sa[0] == sc[0])	{
			if (sb[0]==sa[0])
							{ HARD(SA(0),1); w-= 25; }
				else
							w -= 70;
		}
		if (c > 100000 && b < 1000 && a > 800)	w -= 59;
		if (c > 10000 && b < 1000 && a > 80)	w -= 59;
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
		if (lodig(a)==5 || lodig(b)==5) 	w -= 10;
		if (lodig(a)==7 || lodig(b)==7) 	w +=  8;
		if (lodig(a)==3 || lodig(b)==3) 	w +=  5;
		if (lodig(a)==2 || lodig(b)==2) 	w -=  4;
		if (lodig(a)==6 || lodig(b)==6)	w -=  3;
		break;
	 // In the other cases
	 // 	first standardize the problem, then evaluate
	 case	'-' : return eval2(b,'+',c,a,sb,sc,sa,hard,used) + 3;
	 case	'/' : return eval2(b,'x',c,a,sb,sc,sa,hard,used) + 9;
	}
	return w;
}

int evaluate(int a[], char ops[])
{
	int used[10], len[10], hard[10], sumlen, i, j, h, hm, h2;
	int dif = 0;
	char as[10][10], *p;

	ndig = sumlen = 0;
	for (j=0; j< 10; j++) { used[j] = len[j] = 0; hard[j] = HARDMAX; }
	for (i=1; i < 10; i++) {
		p = _itoa(a[i], as[i], 10);
		j = strlen(p);
		sumlen += j;
		len[j]++;
		while(*p) {
			h = ctod(*p++);
			if(!used[h]) ndig++;
			used[h]++;
		}
	}
	// Evaluate lengthiest numbers
	// This was rather a matter of beauty not of difficulty!
	if (h = len[5]+len[6]+len[7]+len[8]+len[9]) dif -= 41 + 6 * h;
	if (h = len[4]+len[5]+len[6]+len[7]+len[8]+len[9]) dif -= 16 + 4 * h;
	// Evaluate existence and distribution of numbers
	dif += ndval[ndig];              	// How many different digits used
	if (used[0]) dif += 7 + 3*used[0]; 	// Lots of zeroes
	dif += 13 * used[7] + 11 * used[3];  	// Lots of sevens and three's
	dif -=  4 * used[1] +  5 * used[2];	// Few 1's and 2's
	// Evaluate each equation by itself
	// This is now done iterative!
	eval2(a[1], ops[0], a[2], a[3], as[1], as[2], as[3], hard, used);
	eval2(a[4], ops[4], a[5], a[6], as[4], as[5], as[6], hard, used);
	eval2(a[7], ops[5], a[8], a[9], as[7], as[8], as[9], hard, used);
	eval2(a[1], ops[1], a[4], a[7], as[1], as[4], as[7], hard, used);
	eval2(a[2], ops[2], a[5], a[8], as[2], as[5], as[8], hard, used);
	eval2(a[3], ops[3], a[6], a[9], as[3], as[6], as[9], hard, used);
	// Second iteration
	h = eval2(a[1], ops[0], a[2], a[3], as[1], as[2], as[3], hard, used);
	dif += h;	      hm = h;        h2 = h;
	h = eval2(a[4], ops[4], a[5], a[6], as[4], as[5], as[6], hard, used);
	dif += h; if (h > hm) hm = h; if (h < h2) h2 = h;
	h = eval2(a[7], ops[5], a[8], a[9], as[7], as[8], as[9], hard, used);
	dif += h; if (h > hm) hm = h; if (h < h2) h2 = h;
	h = eval2(a[1], ops[1], a[4], a[7], as[1], as[4], as[7], hard, used);
	dif += h; if (h > hm) hm = h; if (h < h2) h2 = h;
	h = eval2(a[2], ops[2], a[5], a[8], as[2], as[5], as[8], hard, used);
	dif += h; if (h > hm) hm = h; if (h < h2) h2 = h;
	h = eval2(a[3], ops[3], a[6], a[9], as[3], as[6], as[9], hard, used);
	dif += h; if (h > hm) hm = h; if (h < h2) h2 = h;
	// Special consideration:
	dif -= hm;   // Do not count the most difficult equation
	// dif -= h2/2; // and the easiest one only half
	// Evaluate the Digits
	h2 = i = 0;
	for (j=0; j < 10; j++) if (used[j]) {
#ifdef TEST
		printf("%d(%d)%d ", j, used[j], hard[j]);
#endif
		h2  += hard[j] * (used[j] + 1);
		if (hard[j] > hard[i] || (hard[j] == hard[i] && used[j] > used[i]) ) {
			i  = j;
		}
		if (hard[j] == HARDMAX && used[j] == 1)
			dif += 80;
	}
	hm = hard[i] * (used[i] + 1);
	dif = dif/3 + ( (h2-hm) * (BASEVAL / 2) )/ (sumlen + ndig - used[i] - 1) - SUBVAL;
#ifdef TEST
	printf("%5.2f %d [%d] %d\n", 
		1.0*(h2-hm)/(sumlen + ndig - used[i] - 1),
		( (h2-hm) * (BASEVAL / 2) )/ (sumlen + ndig - used[i] - 1) - SUBVAL,
		i, dif);
#endif
        // Finally truncate and norm the result between 0 and 100 incl.
	if (dif >= 0) {
	    return min(TOPVAL, ZEROVAL + rdiv((TOPVAL - ZEROVAL + SMEAR) * dif, TOPALPHA + dif));
	} else {
	    return max(     0, ZEROVAL + rdiv((ZEROVAL + SMEAR) * dif,  BOTALPHA - dif));
	}
}

