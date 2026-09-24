#----------------------------------------------------------------------#
#  EQUATOR console tools - OS/2 port build (Open Watcom)               #
#                                                                      #
#  Targets:                                                            #
#    all   -> EQ.EXE EQSYS.EXE TESTINI.EXE EQUATOR.EXE                 #
#    clean -> remove everything under bin\                             #
#                                                                      #
#  Notes:                                                              #
#    - Run via compile-wat.cmd (sets WATCOM/INCLUDE/PATH).             #
#    - wpp386 has native C++ bool; random/srandom map comes from       #
#      src\compat.h.                                                   #
#----------------------------------------------------------------------#

WATCOM    = $(%WATCOM)

!ifndef OS2TK
OS2TK     = c:\os2tk45
!endif

INC       = $(OS2TK)\h;$(WATCOM)\h;$(WATCOM)\h\os2;src
CC        = wpp386
WLINK     = wlink
!define RCFLAGS   -r -bt=os2 -i=src -i=$(OS2TK)\h
!define BINDWF    -q -bt=os2
OUT       = bin

CFLAGS    = -bt=os2 -mf -5 -fpi -Oaxt -W3 -ze -d0 -i=src -i=$(OS2TK)\h
LFLAGS_C  = system os2v2 option heapsize=4096 option stack=65536
LFLAGS_PM = system os2v2 pm option heapsize=4096 option stack=65536 library $(OS2TK)\lib\mmpm2.lib

TARGETS   = $(OUT)\EQ.EXE $(OUT)\EQSYS.EXE $(OUT)\TESTINI.EXE $(OUT)\EQUATOR.EXE
HLPSRC    = help
HLPDIR    = $(OUT)\hlp
IPFC      = ipfc
HELPFILES = $(HLPDIR)\EQUATOR_EN.HLP $(HLPDIR)\EQUATOR_ES.HLP $(HLPDIR)\EQUATOR_NL.HLP $(HLPDIR)\EQUATOR_DE.HLP $(HLPDIR)\EQUATOR_FR.HLP $(HLPDIR)\EQUATOR_IT.HLP

all       : $(TARGETS) $(HELPFILES) .SYMBOLIC

$(OUT)    :
	@if not exist $(OUT) mkdir $(OUT)

$(OUT)\3type.OBJ : src\3type.cc src\compat.h src\3type.h src\genprob.h src\evalprob.h src\mixtool.h $(OUT)
	$(CC) $(CFLAGS) -fo=$@ src\3type.cc

$(OUT)\systems.OBJ : src\systems.cc src\compat.h src\systems.h src\genprob.h src\mixtool.h $(OUT)
	$(CC) $(CFLAGS) -fo=$@ src\systems.cc

$(OUT)\genprob.OBJ : src\genprob.cc src\compat.h src\3type.h src\genprob.h $(OUT)
	$(CC) $(CFLAGS) -fo=$@ src\genprob.cc

$(OUT)\evalprob.OBJ : src\evalprob.cc src\compat.h src\3type.h src\evalprob.h $(OUT)
	$(CC) $(CFLAGS) -fo=$@ src\evalprob.cc

$(OUT)\mixtool.OBJ : src\mixtool.cc src\compat.h src\3type.h src\mixtool.h $(OUT)
	$(CC) $(CFLAGS) -fo=$@ src\mixtool.cc

$(OUT)\testini.OBJ : src\testini.cc src\compat.h src\pmini.h $(OUT)
	$(CC) $(CFLAGS) -fo=$@ src\testini.cc

$(OUT)\getopt.OBJ : src\getopt.cc src\getopt.h $(OUT)
	$(CC) $(CFLAGS) -fo=$@ src\getopt.cc

$(OUT)\EQUATOR.OBJ : src\EQUATOR.CPP src\EQUATOR.H src\lang.h src\pmmnwin.h src\pmeqhelp.h src\pmini.h src\pmgenprb.h src\compat.h $(OUT)
	$(CC) $(CFLAGS) -fo=$@ src\EQUATOR.CPP

$(OUT)\pmgenprb.OBJ : src\pmgenprb.cc src\pmgenprb.h src\compat.h src\3type.h src\genprob.h src\evalprob.h src\mixtool.h $(OUT)
	$(CC) $(CFLAGS) -fo=$@ src\pmgenprb.cc

$(OUT)\pmmnwin.OBJ : src\pmmnwin.cc src\pmmnwin.h src\EQUATOR.H src\lang.h src\pmgenprb.h src\pmeqhelp.h src\pmini.h src\compat.h $(OUT)
	$(CC) $(CFLAGS) -fo=$@ src\pmmnwin.cc

$(OUT)\pmhelp.OBJ : src\pmhelp.cc src\pmeqhelp.h src\EQUATOR.H src\lang.h src\compat.h $(OUT)
	$(CC) $(CFLAGS) -fo=$@ src\pmhelp.cc

$(OUT)\pmini.OBJ : src\pmini.cc src\pmini.h src\pmgenprb.h src\lang.h src\compat.h $(OUT)
	$(CC) $(CFLAGS) -fo=$@ src\pmini.cc

$(OUT)\EQ.EXE : $(OUT)\3type.OBJ $(OUT)\getopt.OBJ $(OUT)\genprob.OBJ $(OUT)\evalprob.OBJ $(OUT)\mixtool.OBJ
	$(WLINK) $(LFLAGS_C) name $(OUT)\EQ.EXE file $(OUT)\3type.OBJ, $(OUT)\getopt.OBJ, $(OUT)\genprob.OBJ, $(OUT)\evalprob.OBJ, $(OUT)\mixtool.OBJ

$(OUT)\EQSYS.EXE : $(OUT)\systems.OBJ $(OUT)\getopt.OBJ $(OUT)\genprob.OBJ $(OUT)\mixtool.OBJ
	$(WLINK) $(LFLAGS_C) name $(OUT)\EQSYS.EXE file $(OUT)\systems.OBJ, $(OUT)\getopt.OBJ, $(OUT)\genprob.OBJ, $(OUT)\mixtool.OBJ

$(OUT)\TESTINI.EXE : $(OUT)\testini.OBJ
	$(WLINK) $(LFLAGS_PM) name $(OUT)\TESTINI.EXE file $(OUT)\testini.OBJ

$(OUT)\EQUATOR.RES : src\EQUATOR.RC $(OUT)
	@if not exist $(OUT) mkdir $(OUT)
	wrc $(RCFLAGS) -fo=$@ src\EQUATOR.RC

$(OUT)\EQUATOR.EXE : $(OUT)\EQUATOR.OBJ $(OUT)\pmgenprb.OBJ $(OUT)\pmmnwin.OBJ $(OUT)\pmhelp.OBJ $(OUT)\pmini.OBJ $(OUT)\genprob.OBJ $(OUT)\evalprob.OBJ $(OUT)\mixtool.OBJ $(OUT)\EQUATOR.RES
	@if not exist $(OUT) mkdir $(OUT)
	$(WLINK) $(LFLAGS_PM) name $@ file $(OUT)\EQUATOR.OBJ, $(OUT)\pmgenprb.OBJ, $(OUT)\pmmnwin.OBJ, $(OUT)\pmhelp.OBJ, $(OUT)\pmini.OBJ, $(OUT)\genprob.OBJ, $(OUT)\evalprob.OBJ, $(OUT)\mixtool.OBJ
	wrc $(BINDWF) -fe=$@ $(OUT)\EQUATOR.RES $@

$(HLPDIR)   :
	@if not exist $(HLPDIR) mkdir $(HLPDIR)

$(HLPDIR)\EQUATOR_EN.HLP : $(HLPSRC)\pmeq_en.ipf $(HLPDIR)
	$(IPFC) $(HLPSRC)\pmeq_en.ipf $@

$(HLPDIR)\EQUATOR_ES.HLP : $(HLPSRC)\pmeq_es.ipf $(HLPDIR)
	$(IPFC) $(HLPSRC)\pmeq_es.ipf $@

$(HLPDIR)\EQUATOR_NL.HLP : $(HLPSRC)\pmeq_nl.ipf $(HLPDIR)
	$(IPFC) $(HLPSRC)\pmeq_nl.ipf $@

$(HLPDIR)\EQUATOR_DE.HLP : $(HLPSRC)\pmeq_de.ipf $(HLPDIR)
	$(IPFC) $(HLPSRC)\pmeq_de.ipf $@

$(HLPDIR)\EQUATOR_FR.HLP : $(HLPSRC)\pmeq_fr.ipf $(HLPDIR)
	$(IPFC) $(HLPSRC)\pmeq_fr.ipf $@

$(HLPDIR)\EQUATOR_IT.HLP : $(HLPSRC)\pmeq_it.ipf $(HLPDIR)
	$(IPFC) $(HLPSRC)\pmeq_it.ipf $@

clean     : .SYMBOLIC
	@if exist bin\EQ.EXE del bin\EQ.EXE >nul
	@if exist bin\EQSYS.EXE del bin\EQSYS.EXE >nul
	@if exist bin\TESTINI.EXE del bin\TESTINI.EXE >nul
	@if exist bin\EQUATOR.EXE del bin\EQUATOR.EXE >nul
	@if exist bin\EQUATOR.RES del bin\EQUATOR.RES >nul
	@if exist bin\EQUATOR.OBJ del bin\EQUATOR.OBJ >nul
	@if exist bin\pmgenprb.OBJ del bin\pmgenprb.OBJ >nul
	@if exist bin\pmmnwin.OBJ del bin\pmmnwin.OBJ >nul
	@if exist bin\pmhelp.OBJ del bin\pmhelp.OBJ >nul
	@if exist bin\pmini.OBJ del bin\pmini.OBJ >nul
	@if exist bin\3type.OBJ del bin\3type.OBJ >nul
	@if exist bin\systems.OBJ del bin\systems.OBJ >nul
	@if exist bin\genprob.OBJ del bin\genprob.OBJ >nul
	@if exist bin\evalprob.OBJ del bin\evalprob.OBJ >nul
	@if exist bin\mixtool.OBJ del bin\mixtool.OBJ >nul
	@if exist bin\testini.OBJ del bin\testini.OBJ >nul
	@if exist bin\getopt.OBJ del bin\getopt.OBJ >nul
	@if exist bin\hlp\EQUATOR_EN.HLP del bin\hlp\EQUATOR_EN.HLP >nul
	@if exist bin\hlp\EQUATOR_ES.HLP del bin\hlp\EQUATOR_ES.HLP >nul
	@if exist bin\hlp\EQUATOR_NL.HLP del bin\hlp\EQUATOR_NL.HLP >nul
	@if exist bin\hlp\EQUATOR_DE.HLP del bin\hlp\EQUATOR_DE.HLP >nul
	@if exist bin\hlp\EQUATOR_FR.HLP del bin\hlp\EQUATOR_FR.HLP >nul
	@if exist bin\hlp\EQUATOR_IT.HLP del bin\hlp\EQUATOR_IT.HLP >nul
	@if exist bin\hlp rd bin\hlp >nul
	@if exist bin rd bin >nul