
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


#define IDM_HELP 900
#define IDM_HELPUSINGHELP 901
#define IDM_HELPGENERAL 902
#define IDM_HELPKEYS 903
#define IDM_HELPINDEX 904
#define IDM_HELPTUTORIAL 905
#define IDM_HELPPRODUCTINFO 906
#define IDM_About	IDM_HELPPRODUCTINFO
#define IDM_PRODUCTINFO_OK

#define IDMSG_CANNOTLOADSTRING   908
#define IDMSG_HELPLOADERROR     909
#define IDMSG_HELPDISPLAYERROR  910

#define IDS_HELPLIBRARYNAME         3
#define IDS_HELPWINDOWTITLE         5

#define HELPLIBRARYNAMELEN     20

/*
 *  Help table and subtables
 */
#define TEMPLATE_HELP_TABLE                 1000
#define SUBTABLE_MAIN                       2000
#define SUBTABLE_PRODUCTINFODLG             3000


/*
 *  Main window help panels
 */
#define PANEL_MAIN                          2100
#define PANEL_PRODUCTINFODLG                3100


#define PANEL_Spiel                         2200
#define PANEL_New                           2210
#define PANEL_Solution			    2213
#define PANEL_Highscores		    2216
#define PANEL_Stufe                         2220
#define PANEL_Hard			    2223
#define PANEL_Alpha			    2226
#define PANEL_IGEL3			    2227
#define PANEL_Exit                          2230
#define PANEL_HELP                          2910
#define PANEL_HELPINDEX                     2920
#define PANEL_HELPGENERAL                   2930
#define PANEL_HELPUSINGHELP                 2940
#define PANEL_HELPKEYS                      2950
#define PANEL_HELPTUTORIAL                  2960
#define PANEL_HELPPRODUCTINFO               2970
#define PANEL_PRODUCTINFO_OK                2980

#define PANEL_Howto                         2000

#define PANEL_Scoring                       4000
#define PANEL_Advertisments                 4010

#define HID_FS_OPEN_DLG_HELP_PANEL          3963
#define HID_FS_SAVE_DLG_HELP_PANEL          3910

VOID InitHelp();
void    HelpIndex();
void    HelpGeneral();
void    HelpUsingHelp();
void    HelpKeys();
VOID DestroyHelpInstance();

