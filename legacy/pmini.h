
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


#define MAGIC   0x12101965
// Block fuer Ziffern
#define IDB_HBMNR		4500
#define IDB_HBMNR0		4500
#define IDB_HBMNR1		4501
#define IDB_HBMNR2		4502
#define IDB_HBMNR3		4503
#define IDB_HBMNR4		4504
#define IDB_HBMNR5		4505
#define IDB_HBMNR6		4506
#define IDB_HBMNR7		4507
#define IDB_HBMNR8		4508
#define IDB_HBMNR9		4509
// Block fuer Symbole
#define IDB_HBMAL		4510 
#define IDB_HBMAL0		4510 
#define IDB_HBMAL1		4511
#define IDB_HBMAL2		4512
#define IDB_HBMAL3		4513
#define IDB_HBMAL4		4514
#define IDB_HBMAL5		4515
#define IDB_HBMAL6		4516
#define IDB_HBMAL7		4517
#define IDB_HBMAL8		4518
#define IDB_HBMAL9		4519
// Block fuer Buchstaben
#define IDB_HBMALA		4520 
#define IDB_HBMALA0		4520
#define IDB_HBMALA1		4521
#define IDB_HBMALA2		4522
#define IDB_HBMALA3		4523
#define IDB_HBMALA4		4524
#define IDB_HBMALA5		4525
#define IDB_HBMALA6		4526
#define IDB_HBMALA7		4527
#define IDB_HBMALA8		4528
#define IDB_HBMALA9		4529
// Rechensymbole
#define IDB_HBMPLUS		4530
#define IDB_HBMMINUS		4531
#define IDB_HBMMAL		4532
#define IDB_HBMDURCH		4533
#define IDB_HBMGLEICH		4534
// Block fuer Mauszeiger
#define IDPS			4540
#define IDP_0			4540
#define IDP_1			4541
#define IDP_2			4542
#define IDP_3			4543
#define IDP_4			4544
#define IDP_5			4545
#define IDP_6			4546
#define IDP_7			4547
#define IDP_8			4548
#define IDP_9			4549
// Block fuer Mauszeiger 2
#define IDP2S			4550
#define IDP2_0			4550
#define IDP2_1			4551
#define IDP2_2			4552
#define IDP2_3			4553
#define IDP2_4			4554
#define IDP2_5			4555
#define IDP2_6			4556
#define IDP2_7			4557
#define IDP2_8			4558
#define IDP2_9			4559

#define IDP_IGEL3               4560

void InitMachine(HAB hab);
void SaveMachine(HAB hab);
void GetBitMaps(HWND);
void DeleteBitMaps();

#define MAXSCORES 4
#define MAXSPEED  2
#define NAMELEN 20

struct hiscore {
	ULONG validmagic;
	long int score;
	ULONG time;
	ULONG level;
	char name[NAMELEN];
	DATETIME when;
};

extern hiscore best[MAXSCORES], fast[MAXSCORES], hard[MAXSCORES];
extern bool HardLevel, AlphaSet ,IGEL3flag;
extern BITMAPINFOHEADER BigBmpData, SmallBmpData;
extern HBITMAP hbmNr[10], hbmAl[10], hbmAa[10], hbmplus, hbmminus, hbmmal, hbmdurch, hbmgleich;
extern HPOINTER DragPtr[10], Drag2Ptr[10], IGEL3;

int StoreScore(int score, ULONG time, ULONG level);

void GetNameDlg(char name[NAMELEN]); // Aus pmmnwin

