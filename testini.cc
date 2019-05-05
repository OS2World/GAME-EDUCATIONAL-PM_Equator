
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


#include <stdio.h>
#define INCL_WINSHELLDATA
#include <os2.h>

#include "pmini.h"

#define PROFILE  "PMEQ.INI"
#define PROSEGM  (PSZ)"pmequator by FSN"
static HINI hini;

hiscore best[MAXSCORES], fast[MAXSCORES], hard[MAXSCORES];

int main(int argc, char *argv[])
{
	ULONG level, level2;
	ULONG dummy;
	
	if (argc != 2) {
		printf("Brauche Dateinamen!");
	}
	char str[99];
	strcpy(str, PROFILE);
	HAB hab = WinInitialize(0);
	printf("HAB = %ld\n", hab);
	hini = PrfOpenProfile(hab, (PSZ)str);
	printf("Hini = %d\n", hini);
	printf("Hini1= %d\n", HINI_USERPROFILE);
	printf("Hini2= %d\n", HINI_SYSTEMPROFILE);
	printf("Size=%d\n", sizeof(hiscore));
	PrfQueryProfileData(hini, PROSEGM, (PSZ)"level", (PVOID) &level, &dummy);printf("%d\n", dummy);
	PrfQueryProfileData(hini, PROSEGM, (PSZ)"level2", (PVOID) &level2, &dummy);printf("%d\n", dummy);
	dummy = sizeof(hiscore);
	PrfQueryProfileData(hini, PROSEGM, (PSZ)"b0", (PVOID) &(best[0]), &dummy);printf("%d\n", dummy);
	PrfQueryProfileData(hini, PROSEGM, (PSZ)"b1", (PVOID) &(best[1]), &dummy);printf("%d\n", dummy);
	PrfQueryProfileData(hini, PROSEGM, (PSZ)"b2", (PVOID) &(best[2]), &dummy);printf("%d\n", dummy);
	PrfQueryProfileData(hini, PROSEGM, (PSZ)"f0", (PVOID) &(fast[0]), &dummy);printf("%d\n", dummy);
	PrfQueryProfileData(hini, PROSEGM, (PSZ)"f1", (PVOID) &(fast[1]), &dummy);printf("%d\n", dummy);
	PrfQueryProfileData(hini, PROSEGM, (PSZ)"f2", (PVOID) &(fast[2]), &dummy); printf("%d\n", dummy);
	PrfQueryProfileData(hini, PROSEGM, (PSZ)"h0", (PVOID) &(hard[0]), &dummy);printf("%d\n", dummy);
	PrfQueryProfileData(hini, PROSEGM, (PSZ)"h1", (PVOID) &(hard[1]), &dummy);printf("%d\n", dummy);
	PrfQueryProfileData(hini, PROSEGM, (PSZ)"h2", (PVOID) &(hard[2]), &dummy);printf("%d\n", dummy);
	for (int i=0; i < 3; i++) {
		printf("b[%d].magic = %08x, %5ld !%s!\n",
			i,best[i].validmagic, best[i].score, best[i].name);
		printf("f[%d].magic = %08x, %5ld !%s!\n",
			i,fast[i].validmagic, fast[i].score, fast[i].name);
		printf("h[%d].magic = %08x, %5ld !%s!\n",
			i,hard[i].validmagic, hard[i].score, best[i].name);
	}
	PrfCloseProfile(hini);
	WinTerminate(hab);
}

