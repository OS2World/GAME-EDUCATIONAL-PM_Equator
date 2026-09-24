
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
#define INCL_GPI
#define INCL_DOSPROCESS
#define INCL_DOSERRORS
#define INCL_DOSSEMAPHORES
#define INCL_GPIBITMAPS
#include <os2.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <process.h>

#include "compat.h"
#include "EQUATOR.H"
#include "lang.h"
#include "pmgenprb.h"
#include "pmmnwin.h"
#include "pmeqhelp.h"
#include "pmini.h"

//
//  Einige Parameter die beim Malen gebraucht werden
//


ULONG clock;
int assigned1[10], assigned2[10];

// Zeichnen der ganzen Symboelchen
#define SYMBOL1(x) ( AlphaSet ? hbmAa[x] : hbmAl[x])
#define SYMBOL(x) SYMBOL1(set[x])
#define DIGSYM(x) ( coded[x] ? assigned1[x] == -1 ? SYMBOL(x) : hbmNr[assigned1[x]] : hbmNr[x] )
static void DrawNumm(HPS hps, int num, int md, POINTL * ptl)
{
	int d=1, dig, wr, i;
	for (i=1; i < md; i++) d *= 10;
	wr = 0;
	for (i=0; i < md; i++) {
            dig = (num / d) % 10;
            if (dig > 0 || wr || d == 1) {
		wr = 1;
                WinDrawBitmap(hps, DIGSYM(dig), NULL, ptl, 0L, 0L, DBM_NORMAL);
	    }
	    d /= 10;
	    ptl->x += BigBmpData.cx;
	}
}

#define PRESKIP 6
static void DrawIcon(HPS hps, int id, POINTL * ptl)
{
	WinDrawBitmap(hps,
		!coded[id]
		? SYMBOL(id)
		: assigned2[id]==-1
			? hbmNr[id] : SYMBOL(assigned2[id]),
		NULL, ptl, 0L, 0L, DBM_NORMAL);
	ptl->x += BigBmpData.cx + PRESKIP;
}

#define SIGNSHIFT 8
#define SIGNDELTA 2
static void DrawSign(HPS hps, char sign, POINTL * ptl)
{
        HBITMAP hbm;
	ptl->x += SIGNDELTA;
	ptl->y += SIGNSHIFT;
        switch (sign) {
		case '+': hbm = hbmplus; break;
		case '-': hbm = hbmminus; break;
		case 'x': hbm = hbmmal; break;
		case '/': hbm = hbmdurch; break;
		default: hbm = hbmgleich;
        }
        WinDrawBitmap(hps, hbm ,NULL, ptl, 0L, 0L, DBM_NORMAL);
	ptl->x += SmallBmpData.cx + SIGNDELTA;
	ptl->y -= SIGNSHIFT;
}

#define TIMERms         200
#define SECONDS(x) (((x) * TIMERms)/1000)

static long int Score, Errors, preTime, nDigits;
static int col[3], lin[3];
static int cxBorder, cyBorder, xSize, ySize, leftNIcon;
static FONTMETRICS fontdata;
static RECTL rectl1, rectl2, rectl3;

#define CLICK_NR(hh) ((hh) - leftNIcon)/(BigBmpData.cx + PRESKIP);

static VOID MainPaint(HWND hwnd)
{
	POINTL ptl;
	RECTL todraw, dummy;
	char buf[127];
	int  i;
	HPS hps = WinBeginPaint (hwnd, NULLHANDLE, NULL);

        if (!WinQueryUpdateRect(hwnd, &todraw)) {
		// DosBeep(220, 40);
		WinQueryWindowRect(hwnd, &todraw);
	}

	if (WinIntersectRect(what_is_it_hab, &dummy, &todraw, &rectl1) ) {
	    WinFillRect(hps, &rectl1, CLR_BACKGROUND);
	    lin[0] =
	    ptl.y = rectl1.yTop - BigBmpData.cy-8;
	    ptl.x = 2+cxBorder;
	    col[0] = ptl.x;
	    DrawNumm(hps, anr[1], 4, &ptl);
	    DrawSign(hps, ops[0],    &ptl);
	    col[1] = ptl.x;
	    DrawNumm(hps, anr[2], 4, &ptl);
	    DrawSign(hps, '=' ,    &ptl);
	    col[2] = ptl.x;
	    DrawNumm(hps, anr[3], 4, &ptl);
	    ptl.y -= SmallBmpData.cy+2+SIGNSHIFT;
	    ptl.x  = cxBorder + 4*BigBmpData.cx - SmallBmpData.cx - SIGNSHIFT;
	    DrawSign(hps, ops[1],    &ptl); ptl.x += 4*BigBmpData.cx;
	    DrawSign(hps, ops[2],    &ptl); ptl.x += 4*BigBmpData.cx;
	    DrawSign(hps, ops[3],    &ptl);
	    lin[1] =
	    ptl.y -= BigBmpData.cy+2-SIGNSHIFT;
	    ptl.x = 2+cxBorder;
	    DrawNumm(hps, anr[4], 4, &ptl);
	    DrawSign(hps, ops[4],    &ptl);
	    DrawNumm(hps, anr[5], 4, &ptl);
	    DrawSign(hps, '=' ,    &ptl);
	    DrawNumm(hps, anr[6], 4, &ptl);
	    ptl.y -= SmallBmpData.cy+2+SIGNSHIFT;
	    ptl.x  = 2+cxBorder + 4*BigBmpData.cx - SmallBmpData.cx - SIGNSHIFT;
	    DrawSign(hps, '=',     &ptl); ptl.x += 4*BigBmpData.cx;
	    DrawSign(hps, '=',     &ptl); ptl.x += 4*BigBmpData.cx;
	    DrawSign(hps, '=',     &ptl);
	    lin[2] =
	    ptl.y -= BigBmpData.cy+2-SIGNSHIFT;
	    ptl.x = 2+cxBorder;
	    DrawNumm(hps, anr[7], 4, &ptl);
	    DrawSign(hps, ops[5],    &ptl);
	    DrawNumm(hps, anr[8], 4, &ptl);
	    DrawSign(hps, '=' ,    &ptl);
	    DrawNumm(hps, anr[9], 4, &ptl);
	}

	if (WinIntersectRect(what_is_it_hab, &dummy, &todraw, &rectl3) ) {
	      ptl.x = rectl3.xLeft; ptl.y = rectl3.yTop; GpiMove(hps, &ptl);
	      ptl.x = rectl3.xRight; GpiLine(hps, &ptl);
	      // GpiSetColor (hps, CLR_DARKCYAN);
	      if (preTime < 0)
	        sprintf(buf, "Time  = %3ld:%02ld (--)       ", SECONDS(clock)/60, SECONDS(clock)%60);
	      else
	        sprintf(buf, "Time  = %3ld:%02ld (%2ld)     ", SECONDS(clock)/60, SECONDS(clock)%60, preTime);
	      ptl.x = 40;
	      ptl.y = 8 + rectl3.yBottom;
	      GpiSetBackMix(hps, BM_OVERPAINT); // Damit wird automatisch alter Text ueberschrieben!
					// Default ist BM_LEAVEALONE und patzt alles zusammen!
	      GpiSetBackColor(hps, CLR_BACKGROUND); // DEFAULT schien weiss!
	      GpiCharStringAt(hps, &ptl, strlen(buf), (PSZ) buf);
	      ptl.y += fontdata.lMaxBaselineExt;
	      sprintf(buf, "Score = %06ld (%2ld/%1ld)     ", Score, Errors, nDigits);
	      GpiCharStringAt(hps, &ptl, strlen(buf), (PSZ) buf);
	}

	if (WinIntersectRect(what_is_it_hab, &dummy, &todraw, &rectl2) ) {
	      WinFillRect(hps, &rectl2, CLR_BACKGROUND);
	      ptl.x = rectl2.xLeft; ptl.y = rectl2.yTop; GpiMove(hps, &ptl);
	      ptl.x = rectl2.xRight; GpiLine(hps, &ptl);
	      ptl.y = rectl2.yBottom + 8;
	      ptl.x = leftNIcon;
	      for (i=0; i < 10; i++) { 
		DrawIcon(hps, i, &ptl);
	      }
	}
	WinEndPaint(hps);
}


static void WSetPos(HWND hwnd, int flags)
{
	HWND hParent = WinQueryWindow(hwnd, QW_PARENT);
	WinSetWindowPos(hParent,HWND_DESKTOP,
			(WinQuerySysValue(HWND_DESKTOP, SV_CXSCREEN) + 240 - xSize)/2,
			(WinQuerySysValue(HWND_DESKTOP, SV_CYSCREEN) - ySize - 2)/3,
			xSize, ySize,
			flags);
}

void InitMainWin(HWND hwnd)
{
	int dx;
	HPS hps = WinGetPS(hwnd);
	GpiQueryFontMetrics(hps, sizeof(fontdata), &fontdata);
	WinReleasePS(hps);
	
        cxBorder = WinQuerySysValue(HWND_DESKTOP,SV_CXDLGFRAME)
		  +WinQuerySysValue(HWND_DESKTOP,SV_CXBORDER);
        cyBorder = WinQuerySysValue(HWND_DESKTOP,SV_CYDLGFRAME)
		  +WinQuerySysValue(HWND_DESKTOP,SV_CYBORDER);

	dx = BigBmpData.cx*12 + (SmallBmpData.cx+SIGNDELTA)*2 + cxBorder*2;
	rectl1.xLeft  = rectl2.xLeft  = rectl3.xLeft  = 2;
	rectl1.xRight = rectl2.xRight = rectl3.xRight = dx;

rectl3.yBottom = 2;
 rectl3.yTop    = 4 * fontdata.lMaxBaselineExt + rectl3.yBottom;
 rectl2.yBottom = rectl3.yTop + 2;
 rectl2.yTop    = rectl2.yBottom + BigBmpData.cy + BigBmpData.cy / 3;
 rectl1.yBottom = rectl2.yTop + 2;
rectl1.yTop    = rectl1.yBottom +4
			+ BigBmpData.cy* 3 + (SmallBmpData.cy+SIGNSHIFT)*2 + cyBorder;
 
 	leftNIcon = (rectl2.xRight - rectl2.xLeft - 10 * (BigBmpData.cx + PRESKIP))/2;
 
 	xSize = dx + 2 * cxBorder;
 	ySize = rectl1.yTop - rectl3.yBottom
 	   + 2 * cyBorder
	   + WinQuerySysValue(HWND_DESKTOP, SV_CYTITLEBAR)
	   + WinQuerySysValue(HWND_DESKTOP, SV_CYMENU);
	WSetPos(hwnd, SWP_ACTIVATE | SWP_SHOW | SWP_MOVE | SWP_SIZE);
}
//=============================================================

static int GetDigit(POINTL ptl)
{
	int a = 1, d = 0, i, h;
	if (ptl.x >= col[2])
		a = 3;
	else if (ptl.x >= col[1])
		a = 2;
	else if (ptl.x >= col[0])
		a = 1;
	else
		return -1;
	h = ptl.x-col[a-1];
	if (ptl.y >= lin[2] && ptl.y < lin[2]+BigBmpData.cy)
		a += 6;
	else if (ptl.y >= lin[1] && ptl.y < lin[1]+BigBmpData.cy)
		a += 3;
	else if (ptl.y >= lin[0] && ptl.y < lin[0]+BigBmpData.cy)
		a = a;
	else
		return -1;
	d = 3; while (h > BigBmpData.cx) {
		h -= BigBmpData.cx;
		d--;
	}
	if (d < 0) return -1;
	for (h = anr[a],i=0; i < d; i++) {
		h /= 10;
		if (h==0) return -1;
	}
	return (h % 10);
}

//======================================================
char inname[NAMELEN];

static MRESULT EXPENTRY GetNameProc(HWND hwnd,ULONG msg,MPARAM mp1,MPARAM mp2)
{
   static HWND hwndName;
   int i;

   switch(msg) {
   case WM_INITDLG:
      hwndName = WinWindowFromID(hwnd,DID_GETNAME);
      WinSendDlgItemMsg(hwnd, DID_GETNAME, EM_SETTEXTLIMIT, MPFROMSHORT(NAMELEN), NULL);
      for (i=0; i < MAXSCORES; i++) {
	if (hard[i].validmagic == MAGIC) 
		WinSendDlgItemMsg(hwnd, DID_GETNAME, LM_INSERTITEM, MPFROMSHORT(LIT_END),
			(PSZ) hard[i].name);
	if (best[i].validmagic == MAGIC) 
		WinSendDlgItemMsg(hwnd, DID_GETNAME, LM_INSERTITEM, MPFROMSHORT(LIT_END),
			(PSZ) best[i].name);
	if (fast[i].validmagic == MAGIC) 
		WinSendDlgItemMsg(hwnd, DID_GETNAME, LM_INSERTITEM, MPFROMSHORT(LIT_END),
			(PSZ) fast[i].name);
      }
      WinSetFocus(HWND_DESKTOP,hwndName);
      inname[0] = '\0';
      break;
   case WM_CONTROL:
      if (SHORT1FROMMP(mp1) == EN_OVERFLOW) ; // Msg, dass Name zu lang!
      break;
   case WM_COMMAND:
      switch(SHORT1FROMMP(mp1)) {
      case DID_OK:
	 WinQueryWindowText(hwndName, NAMELEN, (PSZ)inname);
         // run into break;
      case DID_CANCEL:
         WinDismissDlg(hwnd,DID_CANCEL);
         break;
      }
      break;
   default: 
        return WinDefDlgProc(hwnd,msg,mp1,mp2);
   }
   return (MRESULT) FALSE;
}

void GetNameDlg(char name[NAMELEN])
{
	WinDlgBox(HWND_DESKTOP, HWND_DESKTOP, GetNameProc,(HMODULE)0, ID_GETNAME, NULL);
	strcpy(name, inname);
}

//----------------------------------------------------

HWND hwnd_hi = 0;
const int lineskip=28; // Distance between lines, maybe should be variable

static MRESULT EXPENTRY window_hi(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
  HPS hps;
  RECTL rcl;
  POINTL ptl;
  static int cxSize, cySize;
  int i;
  char buf[132];

  switch (msg)
    {
    case WM_SIZE:
	cySize =  SHORT2FROMMP(mp2);
	cxSize =  SHORT1FROMMP(mp2);
	break;
    case WM_PAINT:
      hps = WinBeginPaint (hwnd, NULLHANDLE, NULL);
      GpiErase(hps);
      WinQueryWindowRect (hwnd, &rcl);
      ptl.x = 16; ptl.y = cySize - lineskip-2;
      GpiCharStringAt(hps, &ptl, strlen("Hard"), (PSZ)"Hard"); ptl.y-=lineskip;
      for (i=0; i < MAXSCORES; i++) if (hard[i].validmagic == MAGIC) {
	sprintf(buf, "%1d. %20s %7ld %3ld:%02ld %02d.%02d.%04d",
			i+1, hard[i].name, hard[i].score, 
			SECONDS(hard[i].time)/60, SECONDS(hard[i].time)%60,
			hard[i].when.day, hard[i].when.month, hard[i].when.year
			);
	GpiCharStringAt(hps, &ptl, strlen(buf), (PSZ) buf);
        ptl.y -= lineskip;
      }
      ptl.y -= lineskip/2;
      GpiCharStringAt(hps, &ptl, strlen("Easy"), (PSZ)"Easy"); ptl.y-=lineskip;
      for (i=0; i < MAXSCORES; i++) if (best[i].validmagic == MAGIC) {
	sprintf(buf, "%1d. %20s %7ld %3ld:%02ld %02d.%02d.%04d",
			i+1, best[i].name, best[i].score, 
			SECONDS(best[i].time)/60, SECONDS(best[i].time)%60,
			best[i].when.day, best[i].when.month, best[i].when.year
			);
	GpiCharStringAt(hps, &ptl, strlen(buf), (PSZ) buf);
        ptl.y -= lineskip;
      }
      ptl.y -= lineskip/2;
      GpiCharStringAt(hps, &ptl, strlen("Easy & Fast"), (PSZ)"Easy & Fast"); ptl.y-=lineskip;
      for (i=0; i < MAXSCORES; i++) if (fast[i].validmagic == MAGIC) {
	sprintf(buf, "%1d. %20s %7ld %3ld:%02ld %02d.%02d.%04d",
			i+1, fast[i].name, fast[i].score, 
			SECONDS(fast[i].time)/60, SECONDS(fast[i].time)%60,
			fast[i].when.day, fast[i].when.month, fast[i].when.year
			);
	GpiCharStringAt(hps, &ptl, strlen(buf), (PSZ) buf);
        ptl.y -= lineskip;
      }
      WinEndPaint (hps);
    default:
	  return (WinDefWindowProc (hwnd, msg, mp1, mp2));
   }
  return (MRESULT) false;
}


static void ShowHiScore(HWND mainw)
{
  ULONG flFlags = FCF_DLGBORDER | FCF_SHELLPOSITION | FCF_TITLEBAR | FCF_MINBUTTON;
  char * mclass = "Scorefenster";
  HWND hwndClient2;

  if (!hwnd_hi) {
	  if (!WinRegisterClass(what_is_it_hab, (PSZ) mclass, (PFNWP) window_hi,  CS_SIZEREDRAW,0L))
		MessageBox(hwndFrame //HWND_DESKTOP
				, IDMSG_CANT_REGISTER, MB_OK | MB_ERROR, TRUE);
	  hwnd_hi = WinCreateStdWindow(HWND_DESKTOP, 0,
					&flFlags,
					(PSZ) mclass,
					(PSZ) "High Scores", 0,
					(HMODULE)0, ID_ClientWindow, &hwndClient2);
	 if (!hwnd_hi)
		MessageBox(hwndFrame // HWND_DESKTOP
			, IDMSG_CANT_FRAME, MB_OK | MB_ERROR, TRUE);
	WinSetOwner(hwnd_hi, mainw);
  }
  int  dx = 720,
       dy = lineskip*15 + 2 + WinQuerySysValue(HWND_DESKTOP, SV_CYTITLEBAR);
  WinSetWindowPos(hwnd_hi, hwndFrame,
		10,
		WinQuerySysValue(HWND_DESKTOP, SV_CYSCREEN) -dy - 10,
		dx, dy,
		SWP_SIZE | SWP_SHOW | SWP_MOVE | SWP_RESTORE ); // | SWP_ZORDER);
  WinInvalidateRect(hwnd_hi, NULL, TRUE);
  WinSendMsg(hwnd_hi, WM_PAINT, 0,0);
}

//======================================================

#define ALLDIGIT(x,y) {for(int ii=0; ii < 10; ii++) x[ii]=y;}

int inputDigit, oldtrial=-1;
bool success;

static void QueryHitDigit();

#define UNASSIGN(pos) assigned1[assigned2[pos]] = -1; assigned2[pos] = -1; \
			nDigits++; QueryHitDigit();

#define UNASSIGN2(pos2) assigned2[assigned1[pos2]] = -1; assigned1[pos2] = -1; \
			nDigits++; QueryHitDigit();

static bool Trial(int digit, int inputDigit)
{
	if (inputDigit < 0 || inputDigit > 9 || digit < 0 || digit > 9) return false;
	success = false;
	if (HardLevel) {
		bool unassign = false;
		if (assigned1[digit] >= 0) {
			UNASSIGN2(digit);
			unassign = true;
			Score -= 7;
		} 
		if (assigned2[inputDigit] >= 0) {
			UNASSIGN(inputDigit);
			unassign = true;
			Score -= 7;
		} 
		nDigits--; 
		if (!unassign && nDigits) preTime = preTime < 0 ? 5 : preTime + 5;
		assigned1[digit] = inputDigit;
		assigned2[inputDigit] = digit;
	} else if (digit == inputDigit) {
		DosBeep(440,50);
		coded[digit] = 0;
		nDigits--;
	} else {
		DosBeep(220,99);
		if (oldtrial != digit) {
			MessageBox(hwndFrame // HWND_DESKTOP
				, IDMSG_LEIDERFALSCH, MB_OK | MB_INFORMATION, TRUE);
			Errors++;
			preTime /= 2;
			Score -= (1000 + 20 * thelevel) * Errors;
		}
		oldtrial = digit;
		return false;
	}
	success = true;
	QueryHitDigit();
	return true;
}

static MRESULT EXPENTRY DigitDlgProc(HWND hwnd,ULONG msg,MPARAM mp1,MPARAM mp2)
{
   int digit;
   static HWND hwndDigit, hwndIcon;

   switch(msg) {
   case WM_INITDLG:
      oldtrial = -1;
      hwndDigit = WinWindowFromID(hwnd,DID_DIGIT);
      hwndIcon  = WinWindowFromID(hwnd, ID_DIGICON);
      digit = 0; while(coded[digit]==0 && digit < 10) digit++;
      if (digit==10) WinSendMsg(hwndDigit, WM_COMMAND, MPFROMSHORT(DID_CANCEL), NULL);
      WinSendMsg(hwndDigit, SPBM_SETLIMITS, MPFROMLONG(9), MPFROMLONG(0));
      WinSendMsg(hwndDigit, SPBM_SETCURRENTVALUE,MPFROMLONG(digit), NULL);
      WinSetFocus(HWND_DESKTOP,hwndDigit);
      break;
   case WM_PAINT:
      WinDefDlgProc(hwnd,msg,mp1,mp2);
      HPS hps = WinBeginPaint (hwndIcon,NULLHANDLE,NULL);
      POINTL ptl;
      ptl.x = 0; ptl.y = 0;
      WinDrawBitmap(hps, SYMBOL(inputDigit), NULL, &ptl, 0L, 0L, DBM_NORMAL);
      WinEndPaint(hps);
      break;
   case WM_COMMAND:
      switch(SHORT1FROMMP(mp1)) {
      case SPBN_UPARROW:
        WinSendMsg(hwndDigit,SPBM_QUERYVALUE,&digit,NULL);
	if (coded[digit]==0) WinSendMsg(hwndDigit, SPBM_SPINUP, MPFROMSHORT(1), NULL);
	break;
      case SPBN_DOWNARROW:
        WinSendMsg(hwndDigit,SPBM_QUERYVALUE,&digit,NULL);
	if (coded[digit]==0) WinSendMsg(hwndDigit, SPBM_SPINDOWN, MPFROMSHORT(1), NULL);
	break;
      case DID_OK:
        WinSendMsg(hwndDigit,SPBM_QUERYVALUE,&digit,NULL);
	if (Trial(inputDigit, digit)) {
		WinDismissDlg(hwnd,DID_OK);
	}
        break;
      case DID_CANCEL:
	 success = false;
         WinDismissDlg(hwnd,DID_CANCEL);
         break;
      }
      break;
   case WM_BUTTON1DBLCLK:
	 success = false;
         WinDismissDlg(hwnd,DID_CANCEL);
         break;
   default: 
        return WinDefDlgProc(hwnd,msg,mp1,mp2);
   }
   return (MRESULT) FALSE;
}

//======================================================

MRESULT EXPENTRY AboutDlgProc(HWND hwnd,ULONG msg,MPARAM mp1,MPARAM mp2)
{
   HPS hps;
   static HWND hwndIcon;
   static int symbol;
   POINTL ptl;

   switch(msg) {
   case WM_INITDLG:
      symbol = 0;
      WinStartTimer(what_is_it_hab, hwnd, ID_Timer2, 1000);
      break;
   case WM_TIMER:
      symbol = (symbol + 1) % 10;
      // WinInvalidateRect(hwnd, NULL, TRUE);
      hwndIcon  = WinWindowFromID(hwnd, ID_DIGICON2);
      WinInvalidateRect(hwndIcon, NULL, FALSE);
      break;
   case WM_PAINT:
      WinDefDlgProc(hwnd,msg,mp1,mp2);
      hwndIcon  = WinWindowFromID(hwnd, ID_DIGICON2);
      hps = WinBeginPaint (hwndIcon,NULLHANDLE,NULL);
      ptl.x = 0; ptl.y = 0;
      WinDrawBitmap(hps, hbmAl[symbol], NULL, &ptl, 0L, 0L, DBM_NORMAL);
      WinEndPaint(hps);
      break;
   default: 
        return WinDefDlgProc(hwnd,msg,mp1,mp2);
   }
   return (MRESULT) FALSE;
}

//======================================================
static HPOINTER currpointer;
#define MAUS_ZEIGER(x)	WinSetPointer(HWND_DESKTOP, currpointer = (x));
#define MAUS_CZEIGER(t,x) MAUS_ZEIGER((t? DragPtr[x] : Drag2Ptr[x]))
#define NORM_MAUS_ZEIGER MAUS_ZEIGER(currpointer=IGEL3flag ? IGEL3 : \
			WinQuerySysPointer(HWND_DESKTOP,SPTR_ARROW, FALSE));

//======================================================
#define NOTE(x,y) DosBeep(x,y-15); DosBeep(0,15);
static void melody(void * dummy)
{
	for (int i = 0; i < 3; i++)
	{
		NOTE(440, 100);
		NOTE(500, 100);
		NOTE( 40,  20);
	}
}

static int Fehler()
{
	int i,c=0;
	for (i=0; i < 10; i++) {
		if (assigned1[i] != i) c++;
	}
	return c;
}

static void QueryHitDigit()
{
	int c = 0, c2;
	if (success) {
	    if ( (!HardLevel && nDigits == 1) || (HardLevel && nDigits == 0) ) {
		NOTE(880, 66);
		WinInvalidateRect(hwndClient, NULL, FALSE);
		if (HardLevel && (c=Fehler())) {
			char msg[120];
			sprintf(msg,"There are %d mistakes in your solution!", c);
			WinMessageBox(HWND_DESKTOP, hwndClient,
   	                     (PSZ)msg, (PSZ)NULL, MSGBOXID, MB_OK | MB_NOICON);
			return;
		}
		ALLDIGIT(coded, 0); 
		ALLDIGIT(assigned1, -1);
		ALLDIGIT(assigned2, -1);
		nDigits = 0;
		if (c==0) {
			if (!HardLevel && preTime > 0) Score += preTime*(preTime+1)/2;
			if (c2=StoreScore(Score, clock, thelevel)) {
				ShowHiScore(hwndClient);
#ifndef USE_CREATETHREAD
				_beginthread(melody, NULL, 8192, NULL);
#else
DosCreateThread(&tid, (PFNTHREAD)melody, 0UL, 0UL, 8192);
#endif
				// Level-Advance bei neuem Spitzenreiter
				if (c2 == 2) {
					if (level  < 50   ) level ++;
					if (level2 < level) level2++;
				}
			}
		}
	    } else if (!HardLevel)
	        preTime = preTime < 0 ? 10 : preTime + 10;
	}
	WinInvalidateRect(hwndClient, NULL, FALSE);
}

//======================================================

/* Relabel all menu texts for the given language and set the language
 * checkmark.  hwndMenu is the FID_MENU window of the frame.  Called on
 * startup (WM_CREATE) and whenever the user picks a language. */
void set_language(HWND hwndMenu, int lang)
{
   MENUITEM miGame, miOpt, miLang, miHelp;
   HWND hwndGame, hwndOpt, hwndLang, hwndHelp;

   if (lang < 0 || lang >= LANG_COUNT) lang = 0;
   current_lang = lang;
   if (!hwndMenu) return;

   /* top-level cascade item labels */
   WinSendMsg(hwndMenu, MM_SETITEMTEXT, MPFROM2SHORT(IDM_SUBMENU_GAME, TRUE),
	      (MPARAM)tr(STR_MENU_GAME));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT, MPFROM2SHORT(IDM_SUBMENU_OPTIONS, TRUE),
	      (MPARAM)tr(STR_MENU_OPTIONS));
   WinSendMsg(hwndMenu, MM_SETITEMTEXT, MPFROM2SHORT(IDM_SUBMENU_HELP, TRUE),
	      (MPARAM)tr(STR_MENU_HELP));

   /* resolve the submenu window handles */
   memset(&miGame, 0, sizeof(MENUITEM));
   memset(&miOpt, 0, sizeof(MENUITEM));
   memset(&miLang, 0, sizeof(MENUITEM));
   memset(&miHelp, 0, sizeof(MENUITEM));
   WinSendMsg(hwndMenu, MM_QUERYITEM, MPFROM2SHORT(IDM_SUBMENU_GAME, TRUE), (MPARAM)&miGame);
   WinSendMsg(hwndMenu, MM_QUERYITEM, MPFROM2SHORT(IDM_SUBMENU_OPTIONS, TRUE), (MPARAM)&miOpt);
   WinSendMsg(hwndMenu, MM_QUERYITEM, MPFROM2SHORT(IDM_SUBMENU_LANGUAGE, TRUE), (MPARAM)&miLang);
   WinSendMsg(hwndMenu, MM_QUERYITEM, MPFROM2SHORT(IDM_SUBMENU_HELP, TRUE), (MPARAM)&miHelp);
   hwndGame = miGame.hwndSubMenu;
   hwndOpt  = miOpt.hwndSubMenu;
   hwndLang = miLang.hwndSubMenu;
   hwndHelp = miHelp.hwndSubMenu;

   if (hwndGame) {
      WinSendMsg(hwndGame, MM_SETITEMTEXT, MPFROM2SHORT(IDM_NEW, TRUE), (MPARAM)tr(STR_MENU_NEWPUZZLE));
      WinSendMsg(hwndGame, MM_SETITEMTEXT, MPFROM2SHORT(IDM_SOLUTION, TRUE), (MPARAM)tr(STR_MENU_SOLUTION));
      WinSendMsg(hwndGame, MM_SETITEMTEXT, MPFROM2SHORT(IDM_HISCORE, TRUE), (MPARAM)tr(STR_MENU_HISCORE));
      WinSendMsg(hwndGame, MM_SETITEMTEXT, MPFROM2SHORT(IDM_LEVEL, TRUE), (MPARAM)tr(STR_MENU_LEVEL));
      WinSendMsg(hwndGame, MM_SETITEMTEXT, MPFROM2SHORT(IDM_HARD, TRUE), (MPARAM)tr(STR_MENU_HARDMODE));
      WinSendMsg(hwndGame, MM_SETITEMTEXT, MPFROM2SHORT(IDM_ALPHA, TRUE), (MPARAM)tr(STR_MENU_ALPHA));
      WinSendMsg(hwndGame, MM_SETITEMTEXT, MPFROM2SHORT(IDM_HEDGEHOG, TRUE), (MPARAM)tr(STR_MENU_HEDGEHOG));
      WinSendMsg(hwndGame, MM_SETITEMTEXT, MPFROM2SHORT(IDM_EXIT, TRUE), (MPARAM)tr(STR_MENU_EXIT));
   }
   if (hwndOpt) {
      WinSendMsg(hwndOpt, MM_SETITEMTEXT, MPFROM2SHORT(IDM_SUBMENU_LANGUAGE, TRUE),
		 (MPARAM)tr(STR_MENU_LANGUAGE));
      WinSendMsg(hwndOpt, MM_SETITEMTEXT, MPFROM2SHORT(IDM_SAVEONEXIT, TRUE), (MPARAM)tr(STR_MENU_SAVEONEXIT));
   }
   if (hwndHelp) {
      WinSendMsg(hwndHelp, MM_SETITEMTEXT, MPFROM2SHORT(IDM_HELPINDEX, TRUE), (MPARAM)tr(STR_MENU_HELPINDEX));
      WinSendMsg(hwndHelp, MM_SETITEMTEXT, MPFROM2SHORT(IDM_HELPGENERAL, TRUE), (MPARAM)tr(STR_MENU_HELPGENERAL));
      WinSendMsg(hwndHelp, MM_SETITEMTEXT, MPFROM2SHORT(IDM_HELPUSINGHELP, TRUE), (MPARAM)tr(STR_MENU_HELPUSINGHELP));
      WinSendMsg(hwndHelp, MM_SETITEMTEXT, MPFROM2SHORT(IDM_HELPKEYS, TRUE), (MPARAM)tr(STR_MENU_HELPKEYS));
      WinSendMsg(hwndHelp, MM_SETITEMTEXT, MPFROM2SHORT(IDM_ABOUT, TRUE), (MPARAM)tr(STR_MENU_ABOUT));
   }

   /* language checkmarks: exactly one of the six is checked */
   if (hwndLang) {
      WinCheckMenuItem(hwndLang, IDM_LANG_EN, lang == LANG_EN);
      WinCheckMenuItem(hwndLang, IDM_LANG_ES, lang == LANG_ES);
      WinCheckMenuItem(hwndLang, IDM_LANG_NL, lang == LANG_NL);
      WinCheckMenuItem(hwndLang, IDM_LANG_DE, lang == LANG_DE);
      WinCheckMenuItem(hwndLang, IDM_LANG_FR, lang == LANG_FR);
      WinCheckMenuItem(hwndLang, IDM_LANG_IT, lang == LANG_IT);
   }
}

//======================================================
static void Commands(HWND hwnd, ULONG mess, MPARAM parm1, MPARAM parm2)
{
	switch (SHORT1FROMMP (parm1))
	{
	   case IDM_EXIT:
		WinSendMsg(hwnd, WM_CLOSE, NULL, NULL);
		break;
	   case IDM_LEVEL:
		WinDlgBox(HWND_DESKTOP, hwnd, LevelDlgProc,(HMODULE)0, ID_LEVEL, NULL);
		if (newlevel) {
			level = newlevel;
			level2=newlevel2;
		}
		else break;
		// Otherwise we wan't to have a new puzzle!
	   case IDM_NEW:
		DosReleaseMutexSem(hmtx);
		DosPostEventSem(hev2);
		MAUS_ZEIGER(WinQuerySysPointer(HWND_DESKTOP, SPTR_WAIT,FALSE));
		nDigits = 0;
		ALLDIGIT(coded, 1); ALLDIGIT(assigned1,-1); ALLDIGIT(assigned2 ,-1);
		{ HPS hps = WinBeginPaint (hwnd, NULLHANDLE, NULL);
		GpiErase(hps);
		WinEndPaint(hps); }
		break;
	   case IDM_SOLUTION:
		ALLDIGIT(coded,0); ALLDIGIT(assigned1, -1); ALLDIGIT(assigned2, -1);
		Score = preTime = nDigits = 0;
		WinInvalidateRect(hwnd, NULL, FALSE);
		break;
	   case IDM_HELPINDEX:
	      	HelpIndex();
	      	break;
	   case IDM_HELPGENERAL:
	      	HelpGeneral();
	      	break;
	   case IDM_HELPUSINGHELP:
	      	HelpUsingHelp();
	      	break;
	   case IDM_HELPKEYS:
	      	HelpKeys();
	      	break;
	   case IDM_HISCORE:
	      	ShowHiScore(hwnd);
	      	break;
	   case IDM_HARD:
	      	HardLevel = !HardLevel;
	      	if (!WinSendMsg(WinWindowFromID(WinQueryWindow(hwnd, QW_PARENT), FID_MENU),
				MM_ISITEMVALID,
				MPFROM2SHORT(IDM_HARD, TRUE),0))
			break;
	      	WinSendMsg(WinWindowFromID(WinQueryWindow(hwnd, QW_PARENT), FID_MENU),
				MM_SETITEMATTR,
				MPFROM2SHORT(IDM_HARD, TRUE),    
				HardLevel
				? MPFROM2SHORT(MIA_CHECKED,MIA_CHECKED)
				: MPFROM2SHORT(MIA_CHECKED,0));
		WinSendMsg(hwnd, WM_COMMAND, (MPARAM)IDM_NEW, 0);
	      	break;
          case IDM_ALPHA:
	      	AlphaSet = !AlphaSet;
	      	WinSendMsg(WinWindowFromID(WinQueryWindow(hwnd, QW_PARENT), FID_MENU),
				MM_SETITEMATTR,
				MPFROM2SHORT(IDM_ALPHA, TRUE),    
				AlphaSet
				? MPFROM2SHORT(MIA_CHECKED,MIA_CHECKED)
				: MPFROM2SHORT(MIA_CHECKED,0));
		WinInvalidateRect(hwnd, NULL, FALSE);
	      	break;
          case IDM_HEDGEHOG:
	      	IGEL3flag = !IGEL3flag;
	      	WinSendMsg(WinWindowFromID(WinQueryWindow(hwnd, QW_PARENT), FID_MENU),
				MM_SETITEMATTR,
				MPFROM2SHORT(IDM_HEDGEHOG, TRUE),
				IGEL3flag
				? MPFROM2SHORT(MIA_CHECKED,MIA_CHECKED)
				: MPFROM2SHORT(MIA_CHECKED,0));
		NORM_MAUS_ZEIGER
	      	break;
	   case IDM_SAVEONEXIT:
		saveonexit = !saveonexit;
		WinSendMsg(WinWindowFromID(WinQueryWindow(hwnd, QW_PARENT), FID_MENU),
			MM_SETITEMATTR,
			MPFROM2SHORT(IDM_SAVEONEXIT, TRUE),
			saveonexit
			? MPFROM2SHORT(MIA_CHECKED,MIA_CHECKED)
			: MPFROM2SHORT(MIA_CHECKED,0));
		break;
case IDM_LANG_EN: case IDM_LANG_ES: case IDM_LANG_NL:
   case IDM_LANG_DE: case IDM_LANG_FR: case IDM_LANG_IT:
      set_language(WinWindowFromID(WinQueryWindow(hwnd, QW_PARENT), FID_MENU),
		   SHORT1FROMMP(parm1) - IDM_LANG_EN);
      WinSetWindowText(WinQueryWindow(hwnd, QW_PARENT), (PSZ)tr(STR_TITLE));
      UpdateHelpFile();
      break;
	   case IDM_ABOUT:
		ULONG temp = FCF_SYSMODAL;
		WinDlgBox(HWND_DESKTOP, hwnd, AboutDlgProc, (HMODULE)0, ID_HELLO, &temp);
		break;
	}
}

// Semaphores
HEV hev, hev2;
HMTX hmtx;
static TID tid;

static bool first = true;

MRESULT EXPENTRY
window_func(HWND hwnd, ULONG mess, MPARAM parm1, MPARAM parm2)
{
  int i, pos = -1;
  ULONG temp;
  static TID tid;
  HPS hps = 0;
  POINTL ptl;

  switch(mess)
  {
    case WM_CREATE:
	// Und jetzt wirds multitaskig!
	DosCreateMutexSem((PSZ)NULL, &hmtx, 0L, (BOOL32) 0);
	DosCreateEventSem((PSZ)NULL, &hev , 0L, (BOOL32) 0);
	DosCreateEventSem((PSZ)NULL, &hev2, 0L, (BOOL32) 0);
#ifndef USE_CREATETHREAD
	tid = _beginthread(genprob, NULL, 8192, NULL);
#else
	DosCreateThread(&tid, (PFNTHREAD)genprob, 0UL, 0UL, 8192);
#endif


	clock = nDigits = Score = 0;


	// Jetzt Aufgabe erzeugen!
	WinSendMsg(hwnd, WM_COMMAND, (MPARAM)IDM_NEW, 0);

	// Menu veraendern
	if (!HardLevel)
		WinSendMsg(WinWindowFromID(WinQueryWindow(hwnd, QW_PARENT), FID_MENU),
			MM_SETITEMATTR,
			MPFROM2SHORT(IDM_HARD, TRUE),
			MPFROM2SHORT(MIA_CHECKED, 0)
			);
	if (!AlphaSet)
		WinSendMsg(WinWindowFromID(WinQueryWindow(hwnd, QW_PARENT), FID_MENU),
			MM_SETITEMATTR,
			MPFROM2SHORT(IDM_ALPHA, TRUE),
			MPFROM2SHORT(MIA_CHECKED, 0));
	if (!IGEL3flag)
		WinSendMsg(WinWindowFromID(WinQueryWindow(hwnd, QW_PARENT), FID_MENU),
			MM_SETITEMATTR,
			MPFROM2SHORT(IDM_HEDGEHOG, TRUE),
			MPFROM2SHORT(MIA_CHECKED, 0));

	if (!saveonexit)
		WinSendMsg(WinWindowFromID(WinQueryWindow(hwnd, QW_PARENT), FID_MENU),
			MM_SETITEMATTR,
			MPFROM2SHORT(IDM_SAVEONEXIT, TRUE),
			MPFROM2SHORT(MIA_CHECKED, 0));

	// Sprache aus den Settings anwenden
	set_language(WinWindowFromID(WinQueryWindow(hwnd, QW_PARENT), FID_MENU),
		current_lang);
	UpdateHelpFile();

	// Einen Timer schliesslich, damit er auch die Aufgabe abholt!
	WinStartTimer(what_is_it_hab, hwnd, ID_Timer, TIMERms);
	NORM_MAUS_ZEIGER
	DosBeep(30, 500);
        break;

    case WM_TIMER:
	if (first) {
		WSetPos(hwnd, SWP_ACTIVATE | SWP_SHOW | SWP_MOVE | SWP_SIZE);
		first = false;
	}
	if (nDigits) clock++;
	if (nDigits && SECONDS(clock-1) != SECONDS(clock)) {
	    preTime--;
	    if (preTime < 0) {
		if (HardLevel)
			Score -= 50;
		else if (nDigits == 10)
			Score -= 100 + Errors;
		else if (nDigits) 
			Score -=  81 + 2*nDigits + Errors;
	    } else if (!HardLevel) {
		Score += preTime;
	    }
	    WinInvalidateRect(hwnd, &rectl3, FALSE);
	}
	DosQueryEventSem(hev, &temp);
	if (temp && DosRequestMutexSem(hmtx, TIMERms/2) != ERROR_TIMEOUT)  {
		if (thelevel > level || thelevel < level2) // nach Aenderungen
			WinSendMsg(hwnd, WM_COMMAND, (MPARAM)IDM_NEW, 0);
		else {
			clock   = 0;
			nDigits = 10;
			Score   = thelevel * 1700 + 15000;
			Errors  = 0;
			if (HardLevel)
				preTime = 30;
			else
				preTime = 10;
			DosResetEventSem(hev, &temp);
			WinInvalidateRect(hwnd, NULL, FALSE);
			NORM_MAUS_ZEIGER
		}
	}
	break;

    case WM_MOUSEMOVE:
	WinSetPointer(HWND_DESKTOP, currpointer);
	break;

    case WM_ERASEBACKGROUND:
	hps = WinBeginPaint(hwnd, NULLHANDLE, NULL);
	GpiErase(hps);
	WinEndPaint(hps);
	WinInvalidateRect(hwnd, NULL, FALSE);
	break;

    case WM_PAINT:
	MainPaint(hwnd);
	break;

    case WM_COMMAND:
	Commands(hwnd, mess, parm1, parm2);
	break;

    case WM_BUTTON2CLICK:
	NORM_MAUS_ZEIGER
	break;
 
    case WM_BUTTON1CLICK:
        ptl.x = SHORT1FROMMP(parm1); ptl.y = SHORT2FROMMP(parm1);
	if (WinPtInRect(what_is_it_hab, &rectl1, &ptl)) {
	    inputDigit = GetDigit(ptl);
	    if (inputDigit > -1) {
		for (i = 0; i < 10; i++) {
			if (AlphaSet && currpointer==DragPtr[i]) {
				oldtrial = -1;
				if (Trial(inputDigit, i)) {
					NORM_MAUS_ZEIGER
				}
				return (MRESULT) FALSE;
			}
		}
		MAUS_ZEIGER(Drag2Ptr[set[inputDigit]]);
	    }
	} else if (WinPtInRect(what_is_it_hab, &rectl2, &ptl) && ptl.x >= leftNIcon) {
	    {
		pos = CLICK_NR(ptl.x);
		for (i = 0; i < 10; i++) {
			if (currpointer==Drag2Ptr[set[i]]) {
				oldtrial = -1;
				if (Trial(i, pos)) {
					NORM_MAUS_ZEIGER
				}
				return (MRESULT) FALSE;
			}
		}
		if (0 <= pos && pos <= 9) {
			MAUS_ZEIGER(DragPtr[pos])
		}
	     }
	}
	break;

    case WM_BUTTON1DBLCLK:
	NORM_MAUS_ZEIGER
        ptl.x = SHORT1FROMMP(parm1); 
	ptl.y = SHORT2FROMMP(parm1);
	if (WinPtInRect(what_is_it_hab, &rectl1, &ptl)) {
	        inputDigit = GetDigit(ptl);
		if (inputDigit > -1) {
			WinDlgBox(HWND_DESKTOP, hwnd, DigitDlgProc,(HMODULE)0, ID_DIGIT, NULL);
		}
	} else if (WinPtInRect(what_is_it_hab, &rectl2, &ptl) && ptl.x >= leftNIcon) {
		pos = CLICK_NR(ptl.x);
		if (HardLevel) {
			UNASSIGN(pos);
		}
	}
	break;

    case WM_DESTROY:
	DosKillThread(tid);
	DeleteBitMaps();
	WinStopTimer(what_is_it_hab, hwnd, ID_Timer);
	break;

    case WM_PRESPARAMCHANGED:
	DosBeep(2000, 1111);
	InitMainWin(hwnd);
	WinInvalidateRect(hwnd, NULL, FALSE);
	break;

    case WM_CLOSE:
      // WinSendMsg(hwnd, WM_QUIT, NULL, NULL);
      // Somehow better without break;

	
    default:
          return WinDefWindowProc(hwnd, mess, parm1, parm2);
    }
    return (MRESULT) 0;
}


