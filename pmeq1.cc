
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


#define INCL_WIN
#define INCL_DOSPROCESS

#include <os2.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pmeq1.h"
#include "pmmnwin.h"
#include "pmhelp.h"
#include "pmini.h"
#include "pmgenprb.h"

HWND hwndClient, hwndFrame;
HAB what_is_it_hab;
 
HWND queryAppInstance(PCHAR pchClassWanted)
{
    CHAR achClass[256];
    HENUM heEnum=WinBeginEnumWindows(HWND_DESKTOP);
    HWND hwndTop=WinGetNextWindow(heEnum);
    while (hwndTop!=NULLHANDLE) {
       hwndClient=WinWindowFromID(hwndTop,FID_CLIENT);
       if (hwndClient!=NULLHANDLE) {
          WinQueryClassName(hwndClient,sizeof(achClass),(PSZ)achClass);
          if (strcmp(achClass,pchClassWanted)==0) {
             WinEndEnumWindows(heEnum);
             return hwndClient;
          } /* endif */
       } /* endif */
 
       hwndTop=WinGetNextWindow(heEnum);
    } /* endwhile */
 
    WinEndEnumWindows(heEnum);
    return NULLHANDLE;
}


int main(void)
{
  QMSG qmsg;
  BYTE mclass[]="Equatorfenster";
  ULONG flFlags = 
	    FCF_TITLEBAR 
            | FCF_DLGBORDER
            | FCF_TASKLIST
	    | FCF_MINBUTTON
	    | FCF_ACCELTABLE
	    | FCF_ICON
	    | FCF_MENU
            | FCF_SYSMENU
	    | FCF_SHELLPOSITION
	;

  what_is_it_hab = WinInitialize(0);
  if (!what_is_it_hab) MessageBox(HWND_DESKTOP, IDMSG_CANT_INIT, MB_OK | MB_ERROR, TRUE);

  if (!(hwndFrame = queryAppInstance((PCHAR)mclass))) {

	InitMachine(what_is_it_hab);

	HMQ hmq = WinCreateMsgQueue(what_is_it_hab, 0);
  	if (!hmq) MessageBox(HWND_DESKTOP, IDMSG_CANT_QUEUE, MB_OK | MB_ERROR, TRUE);

  	if (!WinRegisterClass(what_is_it_hab, (PSZ) mclass, (PFNWP) window_func,  CS_SIZEREDRAW,0L))
		MessageBox(HWND_DESKTOP, IDMSG_CANT_REGISTER, MB_OK | MB_ERROR, TRUE);

        // Startmeldung zeigen, sofort, bevor irgendein Fenster aufgemacht ist!!!
	INT temp = FCF_SYSMODAL;
	WinDlgBox(HWND_DESKTOP, HWND_DESKTOP, AboutDlgProc, (HMODULE)0, ID_HELLO, &temp);

  	hwndFrame = WinCreateStdWindow(HWND_DESKTOP,
				WS_SYNCPAINT,
				&flFlags,
				(PSZ) mclass, 
				(PSZ) "FSN's PM-Equator",
				WS_SYNCPAINT,
				(HMODULE)0, 
				ID_ClientWindow, 
				&hwndClient);
	if (!hwndFrame) MessageBox(HWND_DESKTOP, IDMSG_CANT_FRAME, MB_OK | MB_ERROR, TRUE);

	// Resourcen lesen, Fenster postieren, so flickert nichts
	GetBitMaps(hwndClient);
	InitMainWin(hwndClient);
	InitHelp();

	while (WinGetMsg(what_is_it_hab, &qmsg, (HWND) NULL, 0, 0))  {
		WinDispatchMsg(what_is_it_hab, &qmsg);
  	}
	DestroyHelpInstance();

  	WinDestroyWindow(hwndFrame);
  	WinDestroyMsgQueue(hmq);
  	SaveMachine(what_is_it_hab);
  } else {
	MessageBox(HWND_DESKTOP, IDMSG_ALLREADY_RUNNING, MB_OK | MB_ERROR, TRUE);
	WinSetWindowPos(WinWindowFromID(hwndFrame,QW_PARENT),
			HWND_DESKTOP, 0,0, 0,0, SWP_SHOW | SWP_ZORDER);
  }
  WinTerminate(what_is_it_hab);
}

// This is here for purely historical reasons
int newlevel, newlevel2, spinlevel, spinlevel2;

MRESULT EXPENTRY LevelDlgProc(HWND hwnd,ULONG msg,MPARAM mp1,MPARAM mp2)
{
   static HWND hwndSpin, hwndSpin2;
   LONG spinlevel;

   switch(msg) {
   case WM_INITDLG:
      hwndSpin = WinWindowFromID(hwnd,DID_LEVEL);
      hwndSpin2= WinWindowFromID(hwnd,DID_LEVEL2);
      spinlevel = level ;
      spinlevel2= level2;
      WinSendMsg(hwndSpin, SPBM_SETLIMITS, MPFROMLONG(50), MPFROMLONG(1));
      WinSendMsg(hwndSpin2,SPBM_SETLIMITS, MPFROMLONG(49),  MPFROMLONG(0));
      WinSendMsg(hwndSpin, SPBM_SETCURRENTVALUE,MPFROMLONG(spinlevel), NULL);
      WinSendMsg(hwndSpin2,SPBM_SETCURRENTVALUE,MPFROMLONG(spinlevel2),NULL);
      WinSetFocus(HWND_DESKTOP,hwndSpin);
      break;
   case WM_COMMAND:
      switch(SHORT1FROMMP(mp1)) {
      case DID_OK:
         WinSendMsg(hwndSpin,SPBM_QUERYVALUE,&spinlevel,NULL);
         WinSendMsg(hwndSpin2,SPBM_QUERYVALUE,&spinlevel2,NULL);
         newlevel = (short)spinlevel;
         newlevel2 = (short)spinlevel2;
	 if (newlevel2 < newlevel)
		WinDismissDlg(hwnd,DID_OK);
	 else {
		MessageBox(HWND_DESKTOP, IDMSG_MINDIFF, MB_OK | MB_ERROR, TRUE);
		newlevel = 0;
	 }
         break;
      case DID_CANCEL:
         newlevel = 0;
         WinDismissDlg(hwnd,DID_CANCEL);
         break;
      }
      break;
   default: 
        return WinDefDlgProc(hwnd,msg,mp1,mp2);

   }
   return (MRESULT) FALSE;
}



USHORT MessageBox(HWND hwndOwner, ULONG idMsg, ULONG fsStyle, BOOL fBeep)
{
   CHAR szText[127];
   ULONG err;

   if(!(err=WinLoadMessage(what_is_it_hab,
                     (HMODULE)NULL,
                     idMsg,127,
                     (PSZ)szText)))
   {
      WinAlarm(HWND_DESKTOP, WA_ERROR);
      WinAlarm(HWND_DESKTOP, WA_ERROR);
      sprintf(szText, "Could not load message #%ld, error #%ld!", idMsg,err);
      WinMessageBox(HWND_DESKTOP,
                        hwndOwner,
                        (PSZ) szText,
                        (PSZ) "Internal message error",
                        MSGBOXID,
                        MB_ERROR);
      return MBID_ERROR;
   }

   if(fBeep) WinAlarm(HWND_DESKTOP, WA_ERROR);

   return(WinMessageBox(HWND_DESKTOP,
                        hwndOwner,
                        (PSZ)szText,
                        (PSZ)NULL,
                        MSGBOXID,
                        fsStyle));

}   /* End of MessageBox   */




