
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


#define INCL_WINSHELLDATA
#define INCL_WIN
#include <os2.h>
#include "pmini.h"
#include "pmgenprb.h"

#define PROFILE ((PSZ) "PMEQ.INI")
#define PROSEGM ((PSZ) "pmequator by FSN")
static HINI hini;

hiscore best[MAXSCORES], fast[MAXSCORES], hard[MAXSCORES];
bool HardLevel, AlphaSet, IGEL3flag;

int StoreScore(int score, ULONG time, ULONG level)
{
	int iB, iF, iH;
	char name[NAMELEN];

	iB = iF = iH = MAXSCORES;
	if (HardLevel) {
		iH = MAXSCORES-1; while (iH >= 0 && hard[iH].validmagic != MAGIC) iH--;
		if (iH==-1) {
			iH = 0;
		} else {
			iH ++;
			while (iH > 0 && score > hard[iH-1].score) {
				if (iH < MAXSCORES) hard[iH] = hard[iH-1];
				iH --;
			}
		}
	} else {
		iB = MAXSCORES-1; while (iB >= 0 && best[iB].validmagic != MAGIC) iB--;
		if (iB==-1) {
			iB = 0;
		} else {
			iB ++;
			while (iB > 0 && score > best[iB-1].score) {
				if (iB < MAXSCORES) best[iB] = best[iB-1];
				iB --;
			}
		}
		iF = MAXSPEED-1; while (iF >= 0 && fast[iF].validmagic != MAGIC) iF--;
		if (iF==-1) {
			iF = 0;
		} else {
			iF ++;
			while (iF > 0 && time < fast[iF-1].time) {
				if (iF < MAXSPEED) fast[iF] = fast[iF-1];
				iF --;
			}
		}
	}
	if (iB < MAXSCORES || iF < MAXSPEED || iH < MAXSCORES) {
		GetNameDlg(name);
	}
	if (iB < MAXSCORES) {
		best[iB].validmagic = MAGIC;
		best[iB].score = score;
		best[iB].time  = time;
		best[iB].level = level;
		strcpy(best[iB].name, name);
		DosGetDateTime(&(best[iB].when));
	}
	if (iF < MAXSPEED) {
		fast[iF].validmagic = MAGIC;
		fast[iF].score = score;
		fast[iF].time  = time;
		fast[iF].level = level;
		strcpy(fast[iF].name, name);
		DosGetDateTime(&(fast[iF].when));
	}
	if (iH < MAXSCORES) {
		hard[iH].validmagic = MAGIC;
		hard[iH].score = score;
		hard[iH].time  = time;
		hard[iH].level = level;
		strcpy(hard[iH].name, name);
		DosGetDateTime(&(hard[iH].when));
	}
	if (iB == 0 || iF == 0 || iH == 0)
		return 2;
	else if (iB < MAXSCORES || iF < MAXSPEED || iH < MAXSCORES ) 
		return 1;
	else return 0;
}

#define PRF_QUERY(name, var) dummy = sizeof((var));\
	PrfQueryProfileData(hini, PROSEGM, (PSZ) name, (PVOID)&(var), &dummy);

void InitMachine(HAB hab)
{
	hini = PrfOpenProfile(hab, PROFILE);
	ULONG dummy;
	level  = 30;
	level2 = 20;
	HardLevel = AlphaSet = IGEL3flag = true;
	for (int i=0; i < MAXSCORES; i++) {
		hard[i].validmagic = fast[i].validmagic = best[i].validmagic = MAGIC ^ 0x55555555;
	}
	if (hini) {
		PRF_QUERY("level", level);
		PRF_QUERY("level2", level2);
		PRF_QUERY("Hard", HardLevel);
		PRF_QUERY("Alf", AlphaSet);
		PRF_QUERY("b0", best[0]);
		PRF_QUERY("b1", best[1]);
		PRF_QUERY("b2", best[2]);
		PRF_QUERY("f0", fast[0]);
		// PRF_QUERY("f1", fast[1]);
		// PRF_QUERY("f2",  fast[2]);
		PRF_QUERY("h0",  hard[0]);
		PRF_QUERY("h1",  hard[1]);
		PRF_QUERY("h2",  hard[2]);
		PRF_QUERY("Igel3", IGEL3flag);
	} else {
		hini = (HINI) -3;
	}
	if (level > 50 || level2 < 0 || level2 > level) { level = 30; level2 =20;}
}

#define PRF_WRITE(name, var) PrfWriteProfileData(hini, PROSEGM, (PSZ) name, (PVOID)&(var), sizeof((var)));
void SaveMachine(HAB hab)
{
	PRF_WRITE("level",  level);
	PRF_WRITE("level2",  level2);
	PRF_WRITE("Hard", HardLevel);
	PRF_WRITE("Alf", AlphaSet);
	PRF_WRITE("b0",  (best[0]));
	PRF_WRITE("b1",  (best[1]));
	PRF_WRITE("b2",  (best[2]));
	PRF_WRITE("f0",  (fast[0]));
	// PRF_WRITE("f1",  (fast[1]));
	// PRF_WRITE("f2",  (fast[2]));
	PRF_WRITE("h0",  (hard[0]));
	PRF_WRITE("h1",  (hard[1]));
	PRF_WRITE("h2",  (hard[2]));
	PRF_WRITE("Igel3", IGEL3flag);
	PrfWriteProfileString(hini,PROSEGM, (PSZ)"no_cheat", (PSZ)"Don't peek at this file :-)");
	PrfCloseProfile(hini);
}

BITMAPINFOHEADER BigBmpData, SmallBmpData;
HBITMAP hbmNr[10], hbmAl[10], hbmAa[10], hbmplus, hbmminus, hbmmal, hbmdurch, hbmgleich;
HPOINTER DragPtr[10], Drag2Ptr[10], IGEL3;

void GetBitMaps(HWND hwnd)
{
	HPS hps = WinGetPS(hwnd);
        for (int i = 0; i < 10; i ++) {
		hbmNr[i] = GpiLoadBitmap (hps,NULLHANDLE,IDB_HBMNR+i,0L,0L);
		hbmAl[i] = GpiLoadBitmap (hps,NULLHANDLE,IDB_HBMAL+i,0L,0L);
		hbmAa[i] = GpiLoadBitmap (hps,NULLHANDLE,IDB_HBMALA+i,0L,0L);
		DragPtr[i] = WinLoadPointer(HWND_DESKTOP, NULLHANDLE, IDPS+i);
		Drag2Ptr[i] = WinLoadPointer(HWND_DESKTOP, NULLHANDLE, IDP2S+i);
	}
	IGEL3 = WinLoadPointer(HWND_DESKTOP, NULLHANDLE, IDP_IGEL3);
	hbmplus  = GpiLoadBitmap(hps, NULLHANDLE, IDB_HBMPLUS, 0L, 0L);
	hbmminus = GpiLoadBitmap(hps, NULLHANDLE, IDB_HBMMINUS, 0L ,0L);
	hbmmal   = GpiLoadBitmap(hps, NULLHANDLE, IDB_HBMMAL, 0L, 0L);
	hbmdurch = GpiLoadBitmap(hps, NULLHANDLE, IDB_HBMDURCH, 0L, 0L);
	hbmgleich= GpiLoadBitmap(hps, NULLHANDLE, IDB_HBMGLEICH, 0L, 0L);

        // Bitmapgroesse, eine stellvertretend fuer alle
        GpiQueryBitmapParameters(hbmNr[0],&BigBmpData);
	GpiQueryBitmapParameters(hbmplus, &SmallBmpData);
	WinReleasePS(hps);
}

void DeleteBitMaps()
{
        for (int i = 0; i < 10; i ++) {
		GpiDeleteBitmap (IDB_HBMNR+i);
		GpiDeleteBitmap (IDB_HBMAL+i);
		GpiDeleteBitmap (IDB_HBMALA+i);
		WinDestroyPointer(DragPtr[i]);
		WinDestroyPointer(Drag2Ptr[i]);
	}
	WinDestroyPointer(IGEL3);
	GpiDeleteBitmap(hbmplus);
	GpiDeleteBitmap(hbmminus);
	GpiDeleteBitmap(hbmmal);
	GpiDeleteBitmap(hbmdurch);
	GpiDeleteBitmap(hbmgleich);	
}

