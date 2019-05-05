
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
#define INCL_WINHELP
#include <os2.h>

#include "pmeq1.h"
#include "pmhelp.h"

HWND hwndHelpInstance;
BOOL fHelpEnabled;
char  szWindowTitle[HELPLIBRARYNAMELEN], szLibName[HELPLIBRARYNAMELEN];

VOID InitHelp(VOID)
{
   HELPINIT hini;

   /* if we return because of an error, Help will be disabled */
   fHelpEnabled = FALSE;

   /* initialize help init structure */
   hini.cb = sizeof(HELPINIT);
   hini.ulReturnCode = 0;

   hini.pszTutorialName = (PSZ)NULL;   /* if tutorial added, add name here */

   hini.phtHelpTable = (PHELPTABLE)MAKELONG(TEMPLATE_HELP_TABLE, 0xFFFF);
   hini.hmodHelpTableModule = 0;
   hini.hmodAccelActionBarModule = 0;
   hini.idAccelTable = 0;
   hini.idActionBar = 0;

   if(!WinLoadString(what_is_it_hab,
                     (HMODULE)0,
                     IDS_HELPWINDOWTITLE,
                     HELPLIBRARYNAMELEN,
                     (PSZ)szWindowTitle))
   {
      MessageBox(hwndClient, IDMSG_CANNOTLOADSTRING, MB_OK | MB_ERROR, FALSE);
      return;
   }
   hini.pszHelpWindowTitle = (PSZ)szWindowTitle;

   if(!WinLoadString(what_is_it_hab,
                     (HMODULE)0,
                     IDS_HELPLIBRARYNAME,
                     HELPLIBRARYNAMELEN,
                     (PSZ)szLibName))
   {
      MessageBox(hwndClient, IDMSG_CANNOTLOADSTRING, MB_OK | MB_ERROR, FALSE);
      return;
   }

   hini.pszHelpLibraryName = (PSZ)szLibName;

   /* creating help instance */
   hwndHelpInstance = WinCreateHelpInstance(what_is_it_hab, &hini);

   if(hwndHelpInstance == NULLHANDLE || hini.ulReturnCode )
   {
      MessageBox(HWND_DESKTOP, IDMSG_HELPLOADERROR, MB_OK | MB_ERROR, TRUE);
      return;
   }

   /* associate help instance with main frame */
   if(!WinAssociateHelpInstance(hwndHelpInstance, hwndFrame))
   {
      MessageBox(HWND_DESKTOP, IDMSG_HELPLOADERROR, MB_OK | MB_ERROR, TRUE);
      return; 
   }

   /* help manager is successfully initialized so set flag to TRUE */
   fHelpEnabled = TRUE;
}   /* End of InitHelp   */


/**************************************************************************
 *
 *  Name       : HelpGeneral()
 *
 *  Description: Processes the WM_COMMAND message posted by the
 *               General Help item of the Help menu.
 *
 *  Concepts:    Called from MainCommand when the General Help
 *               menu item is selected.
 *
 *               Sends an HM_EXT_HELP message to the help
 *               instance so that the default Extended Help is
 *               displayed.
 *
 *************************************************************************/
VOID  HelpGeneral(VOID)
{
    /* this just displays the system extended help panel */
   if(fHelpEnabled)
      if(NULL != WinSendMsg(hwndHelpInstance, HM_EXT_HELP,
                            (MPARAM)NULL, (MPARAM)NULL))
         MessageBox(hwndClient,
                    IDMSG_HELPDISPLAYERROR,
                    MB_OK | MB_ERROR,
                    FALSE);
}   /* End of HelpGeneral  */

/**************************************************************************
 *
 *  Name       : HelpUsingHelp()
 *
 *  Description: Processes the WM_COMMAND message posted by the
 *               Using Help item of the Help menu.
 *
 *  Concepts:    Called from MainCommand when the Using Help
 *               menu item is selected.
 *
 *               Sends an HM_DISPLAY_HELP message to the help
 *               instance so that the default Using Help is
 *               displayed.
 *
 *************************************************************************/
VOID  HelpUsingHelp(VOID)
{
   /* this just displays the system help for help panel */
   if(fHelpEnabled)
      if(NULL != WinSendMsg(hwndHelpInstance, HM_DISPLAY_HELP,
                            (MPARAM)NULL, (MPARAM)NULL))
         MessageBox(hwndClient,
                    IDMSG_HELPDISPLAYERROR,
                    MB_OK | MB_ERROR,
                    FALSE);
}   /* End of HelpUsingHelp   */


/**************************************************************************
 *
 *  Name       : HelpKeys()
 *
 *  Description: Processes the WM_COMMAND message posted by the
 *               Keys Help item of the Help menu.
 *
 *  Concepts:    Called from MainCommand when the Keys Help
 *               menu item is selected.
 *
 *               Sends an HM_KEYS_HELP message to the help
 *               instance so that the default Keys Help is
 *               displayed.
 *
 *************************************************************************/
VOID  HelpKeys(VOID)
{
   /* this just displays the system keys help panel */
   if(fHelpEnabled)
      if(NULL != WinSendMsg(hwndHelpInstance, HM_KEYS_HELP,
                            (MPARAM)NULL, (MPARAM)NULL))
         MessageBox(hwndClient,
                    IDMSG_HELPDISPLAYERROR,
                    MB_OK | MB_ERROR,
                    FALSE);
}   /* End of HelpKeys   */


/**************************************************************************
 *
 *  Name       : HelpIndex()
 *
 *  Description: Processes the WM_COMMAND message posted by the
 *               Help Index item of the Help menu.
 *
 *  Concepts:    Called from MainCommand when the Help Index
 *               menu item is selected.
 *
 *               Sends an HM_INDEX_HELP message to the help
 *               instance so that the default Help Index is
 *               displayed.
 *
 *************************************************************************/
VOID  HelpIndex(VOID)
{
   /* this just displays the system help index panel */
   if(fHelpEnabled)
      if(NULL != WinSendMsg(hwndHelpInstance, HM_HELP_INDEX,
                             (MPARAM)NULL, (MPARAM)NULL))
         MessageBox(hwndClient,
                    IDMSG_HELPDISPLAYERROR,
                    MB_OK | MB_ERROR,
                    FALSE);
}   /* End of HelpIndex() */

/**************************************************************************
 *
 *  Name       : DisplayHelpPanel(idPanel)
 *
 *  Description: Displays the help panel whose id is given
 *
 *  Concepts:    Called whenever a help panel is desired to be
 *               displayed, usually from the WM_HELP processing
 *               of the dialog boxes.
 *
 *               Sends HM_DISPLAY_HELP message to the help instance.
 *
 *  Parameters :  idPanel = panel i.d.
 *
 *************************************************************************/
VOID DisplayHelpPanel(ULONG idPanel)
{
   if(fHelpEnabled)
      if(NULL != WinSendMsg(hwndHelpInstance,
                            HM_DISPLAY_HELP,
                            MPFROMLONG(idPanel),
                            MPFROMSHORT(HM_RESOURCEID)))
         MessageBox(HWND_DESKTOP,
                    IDMSG_HELPDISPLAYERROR,
                    MB_OK | MB_ERROR,
                    TRUE);
}   /* End of DisplayHelpPanel   */


/**************************************************************************
 *
 *  Name       : DestroyHelpInstance()
 *
 *  Description: Destroys the help instance for the application
 *
 *  Concepts:    Called after exit from message loop.
 *
 *               Calls WinDestroyHelpInstance() to destroy the
 *               help instance.
 *
 *  API's      : WinDestroyHelpInstance
 *
 *************************************************************************/
VOID DestroyHelpInstance(VOID)
{
   if(hwndHelpInstance != NULLHANDLE)
      WinDestroyHelpInstance(hwndHelpInstance);
}   /* End of DestroyHelpInstance   */

