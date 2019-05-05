
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


#include <stdlib.h>
#include "3type.h"
#include "mixtool.h"

// Very primitive shuffling method for digits:
// I was lazy to think about anything smart
void rset(int count, char set[], int base)
{
	int i; char h;
	for (i=0; i < base; i++) set[i] = (count/3+i)%base;
	for (i=0; i < count+97; i++) {
		int j1  = (i/2) % base;
		int j2  = (i+1) % base;
		h       = set[j1];
		set[j1] = set[j2];
		set[j2] = h;
	}
}

/* 
	Try to change the puzzle randomly by swapping rows 
		the method is rather stupid since I was lazy again :-)
 */


#define KOMMUTES(c)	(c=='+' || c=='x') // Operations we might exchange
#define PCT(x) ((random()/2)%100 < x) 

// Try to swap rows
void Iswap(int &a1, int &a2, int &a3, 
	   int &a4, int &a5, int &a6, 
	   int &a7, int &a8, int &a9,
	   char &o1, char &o2, char &o3,
	   char &o4, char &o5, char &o6
	   )
{
	for (int i=0; i < 2; i++)
	{
	    if (KOMMUTES(o1) && KOMMUTES(o2) && KOMMUTES(o3) 
             && PCT(29))
	    {
		swap(a1,a4); swap(a2,a5); swap(a3,a6);
		swap(o4, o5);
	    }
	    if (PCT(29))
	    {
		swap(a1,a7); swap(a2,a8); swap(a3,a9);
		INVOP(o1); INVOP(o2); INVOP(o3);
		swap(o4,o6);
	    }
	}
}

// Try to swap rows and colums, by swapping the problem and the transposed alternating
// In the beginning sometmies transpose the whole scheme
void swappy(int a[], char * op)
{
    if (PCT(50)) { // Do an extra transposition, to speed things up
	swap(a[2], a[4]); swap(a[7], a[3]); swap(a[8], a[6]);
	swap(op[0], op[1]); swap(op[4], op[2]); swap(op[5],op[3]);
    }
    for(int i =0; i < 2; i++)
    {
	Iswap(a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],
		op[1],op[2],op[3],op[0],op[4],op[5]);
	Iswap(a[1],a[4],a[7],a[2],a[5],a[8],a[3],a[6],a[9],
		op[0],op[4],op[5],op[1],op[2],op[3]);
    }
}

