
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



#define ID_LEVEL		4301
#define DID_LEVEL		4302
#define DID_LEVEL2		4303

#define IDS_APPNAME		4401

#define IDMSG_MINDIFF		4001
#define IDMSG_CANT_INIT 	4002
#define IDMSG_CANT_QUEUE	4003
#define IDMSG_CANT_FRAME	4004
#define IDMSG_CANT_REGISTER     4005
#define IDMSG_ALLREADY_RUNNING  4006

MRESULT EXPENTRY LevelDlgProc(HWND hwnd,ULONG msg,MPARAM mp1,MPARAM mp2);
USHORT MessageBox(HWND hwndOwner, ULONG idMsg, ULONG fsStyle, BOOL fBeep);

extern HAB what_is_it_hab;
extern HWND hwndClient, hwndFrame;

