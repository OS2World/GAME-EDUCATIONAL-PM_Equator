/*****************************************************************************
* Program:  LANG.H
* Purpose:  Language support tables and accessor macros for Equator.
*
* Follows the standard set in the family plan (section 8): a single 2D
* array of const char* indexed by [language][string_id].  The table is
* INSTANTIATED in EQUATOR.CPP by defining LANG_MAIN before including
* this header.  Menu text is swapped at run time by set_language() in
* pmmnwin.cc.
*
* All translated text is pure ASCII (no accented characters) so that
* the sources remain buildable with the stock Open Watcom tool chain.
*****************************************************************************/
#ifndef LANG_H
#define LANG_H

/* Existing projects keep their established numeric order.  For a fresh
 * standardization starting point we use the neutral order from the plan. */
#define LANG_EN  0
#define LANG_ES  1
#define LANG_NL  2
#define LANG_DE  3
#define LANG_FR  4
#define LANG_IT  5
#define LANG_COUNT  6

/* The names of the languages in their own language, used for the
 * Language submenu entries.  These labels never change regardless
 * of the active language. */
#define LANG_NAME_EN  "English"
#define LANG_NAME_ES  "Espanol"
#define LANG_NAME_NL  "Nederlands"
#define LANG_NAME_DE  "Deutsch"
#define LANG_NAME_FR  "Francais"
#define LANG_NAME_IT  "Italiano"

/*****************************************************************************
* String IDs
*****************************************************************************/
enum {
   STR_MENU_GAME,        /* main menu heading                     */
   STR_MENU_NEWPUZZLE,   /* game > new puzzle                     */
   STR_MENU_SOLUTION,    /* game > solution                       */
   STR_MENU_HISCORE,     /* game > highscores                     */
   STR_MENU_LEVEL,       /* game > level                          */
   STR_MENU_HARDMODE,    /* game > hardmode (checkable)           */
   STR_MENU_ALPHA,       /* game > alpha (checkable)              */
   STR_MENU_HEDGEHOG,    /* game > hedgehog (checkable)           */
   STR_MENU_EXIT,        /* game > exit                           */
   STR_MENU_OPTIONS,     /* options menu heading                  */
   STR_MENU_LANGUAGE,    /* options > language submenu heading    */
   STR_MENU_SAVEONEXIT,  /* options > save settings on exit       */
STR_MENU_HELP,        /* help menu heading                  */
   STR_MENU_HELPINDEX,   /* help > help index                  */
   STR_MENU_HELPGENERAL, /* help > general help                */
   STR_MENU_HELPUSINGHELP, /* help > using help                */
   STR_MENU_HELPKEYS,    /* help > keys help                   */
   STR_MENU_ABOUT,       /* help > about                       */
   STR_TITLE,            /* window title                          */
   STR_COUNT
};

/* The currently active language (LANG_EN .. LANG_IT).  Defined in
 * EQUATOR.CPP and persisted via pmini.cc. */
extern int current_lang;

/* "Save settings on exit" flag.  Defined in pmini.cc. */
extern bool saveonexit;

/*****************************************************************************
 * The string table.  Instantiated in EQUATOR.CPP:
 *
 *      #define LANG_MAIN
 *      #include "lang.h"
 *
 *****************************************************************************/
extern const char *const lang_strings[LANG_COUNT][STR_COUNT];

/* Convenience accessor - returns the current-language string. */
#define tr(id)   ((char*)lang_strings[current_lang][(id)])

#endif  /* LANG_H */