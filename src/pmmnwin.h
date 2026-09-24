
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

/* menu item IDs - standardized ranges (family plan section 6.4)      */
/* 100-199: Game menu                                                 */
#define IDM_NEW		100
#define IDM_SOLUTION	101
#define IDM_HISCORE	102
#define IDM_LEVEL	103
#define IDM_HARD	104
#define IDM_ALPHA	105
#define IDM_HEDGEHOG	106
#define IDM_EXIT	107

/* 200-299: Options menu                                               */
#define IDM_SAVEONEXIT	200

/* 300-399: Language items                                             */
#define IDM_LANG_EN	300
#define IDM_LANG_ES	301
#define IDM_LANG_NL	302
#define IDM_LANG_DE	303
#define IDM_LANG_FR	304
#define IDM_LANG_IT	305

/* 900-999: Help menu                                                  */
#define IDM_HELPINDEX	901
#define IDM_HELPGENERAL	902
#define IDM_HELPUSINGHELP 903
#define IDM_HELPKEYS	904
#define IDM_ABOUT	999

/* 1000-1099: submenu cascade IDs (needed for runtime MM_SETITEMTEXT)  */
#define IDM_SUBMENU_GAME	1000
#define IDM_SUBMENU_OPTIONS	1001
#define IDM_SUBMENU_LANGUAGE	1002
#define IDM_SUBMENU_HELP	1003

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
void set_language(HWND hwndMenu, int lang);

extern int newlevel, newlevel2, spinlevel, spinlevel2;

