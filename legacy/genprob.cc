
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
	genprob.cc
	
	Generate various types of equator problems
	
	General form of a problem:
	
		a1 o0 a2 = a3
		o1    o2   o3
		a4 o4 a5 = a6
	       ---------------
		a7 o5 a8 = a9
	
	where o0,..,o5 represent one of the operations +,-,*,/
	and a1,..,a9 are appropriate integers, the operands.
	
	The general structure of the problem generating functions
	"genprobx" is: Input 3 random parameters and pointers to
	arrays, where to store a[] and o[].
	Warning: All routines may give up and return false, if they fail
	to produce a puzzle with a certain parameter set. This has to
	be treated by the calling program!
*/
#include <string.h>
#include "3type.h"
#include "genprob.h"

int gcd(int a, int b) // Greates common divisor
{	int h;	
	do {
		h = a % b;
		a = b; 
		b = h;
	} while (h!=0);
	return a;
}

//
// INVOP converts + to - and x to / and vice versa
//	This is only legal in certain cases. I'm not sure I found all of them!
//
// If "right" term of sum is negative, swap the sign
#define SIGNCHECK(c,n) if (c < 0) { c = -c; INVOP(ops[n]); };
// If one factor of product is negative, swap two signs!
#define SIGNCHECK2(c,n,m) if (c < 0) { c = -c; INVOP(ops[n]); INVOP(ops[m]); };

// Type 1:
//      called eg. via
//	  r = genprob1(RAND(100,999),RAND(-49,49),RAND(-49,49), a,ops);
//      note that this program may also produce problems of different
//	type in this case it adjusts the operations in the array ops!
bool genprob1(int A, int l, int n, int a[], char ops[])
{
	strncpy(ops,"++/-++",6);
	a[1] = A;
	a[4] = 2*l*n-l-n;
	if (a[4] < 0 || n== 0) return false;
	a[5] = 2*n;
	a[6] = a[4] + a[5];
	if (a[5] < 0 ) return false;
	a[7] = a[1] + a[4];
	a[9] = A + 2*l*n-n+l; // Or: a[9] = a[7] +2*l;
	a[8] = a[9] - a[7];   //     a[8] = 2*l;
	SIGNCHECK(a[8], 5);
	a[3] = a[9] + a[6];
	a[2] = a[3] - a[1];
	SIGNCHECK(a[2], 0);
	return true;
}

// Type 2:
//	called eg. via
//	  r = genprob2(RAND(12,99), RAND(-49,99), RAND(12,499), a,ops);
//      note that this program may also produce problems of different
//	type in this case it adjusts the operations in the array ops!
bool genprob2(int A, int d, int D, int a[], char ops[])
{
	strncpy(ops,"xx+-++",6);
	a[1] = A;
#ifdef OLD
	int h = A*d-2*D-d;
	a[2] = D+d;
	if (a[2] < 0) return false;
	a[4] = D;
#else
	int h = A*d-2*(D-d)-d;
	a[2] = D;
	a[4] = D - d;
	if (a[4] < 0) return false;
#endif
	if (h % 2) return false;
	a[7] = a[1] * a[4];
	a[3] = a[1] * a[2];
	a[5] = h / 2; // This one is the magic one
	a[6] = a[4] + a[5];
	a[8] = a[2] + a[5];
	a[9] = a[7] + a[8];
	if (a[8] <= 0 || a[6] <= 0) return false;
	SIGNCHECK2(a[5], 2, 4);
	return true;
}

// Type 3: Now 3 parameters instead of 2
// 	called eg. via
//	  r = genprob3(RAND(12,99), RAND(12,99), RAND(1,9), a,ops);
//	this program does not yet change the array ops
bool genprob3(int D, int d, int l, int a[], char ops[])
{
	strncpy(ops,"xxx-x+",6);
	int B = D+d, k = (D+B)/gcd(D+B, d);
	a[4] = D;
	a[2] = B;
	a[1] = l * k;
	a[3] = a[1] * B;
	a[7] = a[1] * D;
	a[5] = a[1] * d / (D+B); // This one is magic
	a[8] = a[5] * a[2];
	a[9] = a[7] + a[8];
	a[6] = a[4] * a[5];
	return true;
}

// Type 4: This one is new!! 
//      I'm not sure: Can you get that one from Type 1 by transformation/SIGNCHECKS!
//	Anyway: I derived this formula and introduced the transformations later. Unlucky!
//	called eg via:
//	  r = genprob4(RAND(12,999), RAND(12,49), RAND(1,49), a,ops);
//	not ops modification yet!
bool genprob4(int A, int e, int l, int a[], char ops[])
{
	strncpy(ops,"--++x+",6);
	int E = 2*e, D = E + 2*l;
	a[1] = A;
	a[2] = (D * E + D - E)/2;
	a[3] = a[1] - a[2];
	if (a[3] < 0) return false;
	a[4] = D;
	a[5] = E;
	a[6] = D * E;
	a[7] = a[1] - a[4];
	if (a[7] < 0) return false;
	a[8] = a[2] + a[5];
	a[9] = a[3] + a[6];
	return true;
}


