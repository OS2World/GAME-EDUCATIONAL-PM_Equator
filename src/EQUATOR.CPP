
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
#define INCL_GPIBITMAPS
#include <os2.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LANG_MAIN
#include "compat.h"
#include "EQUATOR.H"
#include "lang.h"
#include "pmmnwin.h"
#include "pmeqhelp.h"
#include "pmini.h"
#include "pmgenprb.h"

int current_lang = LANG_EN;

const char *const lang_strings[LANG_COUNT][STR_COUNT] = {
   {  /* English */
      "~Game",
      "~New Puzzle\tCtrl+N",
      "~Solution\tCtrl+S",
      "H~ighscores\tCtrl+I",
      "~Level\tCtrl+L",
      "~Hardmode\tCtrl+H",
      "~Alpha\tCtrl+A",
      "Hedgeh~og",
      "E~xit\tCtrl+X",
      "~Options",
      "~Language",
      "~Save settings on exit",
      "~Help",
      "Help ~index",
      "~General help",
      "~Using help",
      "~Keys help",
      "~About Equator...",
      "Equator"
   },
   {  /* Espanol */
      "~Juego",
      "~Nuevo Puzzle\tCtrl+N",
      "~Solucion\tCtrl+S",
      "~Puntuaciones\tCtrl+I",
      "~Nivel\tCtrl+L",
      "~Modo Dificil\tCtrl+H",
      "~Alpha\tCtrl+A",
      "~Erizo",
      "~Salir\tCtrl+X",
      "~Opciones",
      "~Idioma",
      "~Guardar configuracion al salir",
      "~Ayuda",
      "~Indice",
      "~Ayuda general",
      "~Como usar la ayuda",
      "~Ayuda de teclas",
      "~Acerca de Equator...",
      "Equator"
   },
   {  /* Nederlands */
      "~Spel",
      "~Nieuw Puzzel\tCtrl+N",
      "~Oplossing\tCtrl+S",
      "H~oogste Scores\tCtrl+I",
      "~Niveau\tCtrl+L",
      "~Moeilijk\tCtrl+H",
      "~Alpha\tCtrl+A",
      "~Egel",
      "~Afsluiten\tCtrl+X",
      "~Opties",
      "~Taal",
      "~Instellingen opslaan bij afsluiten",
      "~Help",
      "Help ~index",
      "~Algemene help",
      "~Help gebruiken",
      "~Toetsen help",
      "~Over Equator...",
      "Equator"
   },
   {  /* Deutsch */
      "~Spiel",
      "~Neues Raetsel\tCtrl+N",
      "~Loesung\tCtrl+S",
      "~Bestenliste\tCtrl+I",
      "~Stufe\tCtrl+L",
      "~Schwierig\tCtrl+H",
      "~Alpha\tCtrl+A",
      "~Igel",
      "B~eenden\tCtrl+X",
      "~Optionen",
      "~Sprache",
      "~Einstellungen beim Beenden speichern",
      "~Hilfe",
      "Hilfe ~index",
      "~Allgemeine Hilfe",
      "~Hilfe verwenden",
      "~Tastaturhilfe",
      "~Ueber Equator...",
      "Equator"
   },
   {  /* Francais */
      "~Jeu",
      "~Nouveau Puzzle\tCtrl+N",
      "~Solution\tCtrl+S",
      "~Meilleurs Scores\tCtrl+I",
      "~Niveau\tCtrl+L",
      "~Mode Difficile\tCtrl+H",
      "~Alpha\tCtrl+A",
      "Heris~son",
      "~Quitter\tCtrl+X",
      "~Options",
      "~Langue",
      "~Enregistrer les parametres en quittant",
      "~Aide",
      "Aide ~index",
      "~Aide generale",
      "~Comment utiliser l'aide",
      "~Aide clavier",
      "~A propos d'Equator...",
      "Equator"
   },
   {  /* Italiano */
      "~Gioco",
      "~Nuovo Puzzle\tCtrl+N",
      "~Soluzione\tCtrl+S",
      "~Classifiche\tCtrl+I",
      "~Livello\tCtrl+L",
      "~Modo Difficile\tCtrl+H",
      "~Alpha\tCtrl+A",
      "~Riccio",
      "~Uscita\tCtrl+X",
      "~Opzioni",
      "~Lingua",
      "~Salva impostazioni all'uscita",
      "~Aiuto",
      "Aiuto ~indice",
      "~Aiuto generale",
      "~Come usare la guida",
      "~Guida ai tasti",
      "~Informazioni su Equator...",
      "Equator"
   }
};

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


static const char bldlevel[] =
	"@#Frank Sven Nestel:1.0#@##1## 20 Sep 2026 00:00:00      "
	"ARCAOS:::0::::@@A challenging number puzzle game for OS/2.\r\n\x1a";

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

  	hwndFrame = WinCreateStdWindow(HWND_DESKTOP,
				WS_SYNCPAINT,
				&flFlags,
				(PSZ) mclass, 
				(PSZ)tr(STR_TITLE),
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




