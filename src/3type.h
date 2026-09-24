
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


#ifndef __3TYPE_H__
#define __3TYPE_H__

inline int lodig(int x) { return x % 10; }
inline int dig2(int x) { return (x/10) % 10; }
inline int dig3(int x) { return (x/100) % 10; }
inline int ctod(char x) { return x-'0'; }
template <class X> static void swap(X &a, X &b) { X t = a; a = b; b = t; };
#define INVOP(c)	c=(c=='+' ? '-' : c=='x' ? '/' : c=='-' ? '+' : 'x');
#endif

