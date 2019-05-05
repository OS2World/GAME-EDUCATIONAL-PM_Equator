
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


#define MSGBOXID 1001
#define ID_ClientWindow 	4200

#define IDM_Equator		4201
#define IDM_Level		4202
#define IDM_Neu			4203
#define IDM_Exit		4204
#define IDM_Sol			4205
#define IDM_Hard		4206
#define IDM_HISCORE		4213
#define IDM_Alpha		4214
#define IDM_IGEL3		4215

#define ID_Timer		4000
#define ID_Timer2		4001
#define DID_DIGIT		4207
#define ID_DIGIT		4208
#define ID_DIGICON		4209
#define ID_DIGICON2		4210
#define ID_GETNAME		4211
#define DID_GETNAME		4212


#define IDS_APPNAME		4401

#define ID_HELLO                4801
#define IDMSG_LEIDERFALSCH	4007

MRESULT EXPENTRY window_func(HWND hwnd, ULONG mess, MPARAM parm1, MPARAM parm2);
void InitMainWin(HWND hwnd);
MRESULT EXPENTRY AboutDlgProc(HWND hwnd,ULONG msg,MPARAM mp1,MPARAM mp2);

extern int newlevel, newlevel2, spinlevel, spinlevel2;

