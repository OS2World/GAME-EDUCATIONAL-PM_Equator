CC  = gcc
OBJ = genprob.o evalprob.o mixtool.o
LIBS= -lbsd
CFLG= -O2 -g -Zmtd # Die mtd Option ist eigentlich fuer PM!
DISTFILE=a:\pmeqv01.zip

.cc.o:
	$(CC) -c -Wall $(CFLG) $<

all: eq.exe pmeq eqsys.exe

clean:
	-del *.o
	-del *.o2
	-del *.

copy: pmeq1.exe pmeq1.hlp readme pmeq.ini
	echo "Enter copy-disk into drive a:"
	pause
	-mkdir a:\pmeq
	-cd a:\pmeq
	copy pmeq1.exe a:
	copy pmeq1.hlp a:
	copy readme a:
	copy pmeq.ini a:


dist: pmeq file_id.diz register.txt license.txt read.me zipcom files.lst
	copy f:\emx\dll\emxlibcm.dll f:\emx\dll\emx.dll .
	zip -9 -T -u -b . -@ $(DISTFILE) < files.lst
	del emx*.dll
# Doesn't work! zip -z -v -T -b . $(DISTFILE) < zipcom

files.lst: makefile
	@echo pmeq1.exe > files.lst
	@echo pmeq1.hlp >> files.lst
	@echo pmeq.ini >> files.lst
	@echo file_id.diz >> files.lst
	@echo register.txt >> files.lst
	@echo license.txt >> files.lst
	@echo pmeq1.ico >> files.lst
	@echo read.me >> files.lst
	@echo files.lst >> files.lst
	@echo emxlibcm.dll >> files.lst
	@echo emx.dll >> files.lst
	type files.lst

#
# The basic (alpha) version
#

eq.exe: 3type.o $(OBJ)
	$(CC) -o eq.exe $(CFLG) 3type.o $(OBJ) $(LIBS)

eqsys.exe: systems.o genprob.o mixtool.o
	$(CC) -o eqsys.exe $(CFLG) systems.o genprob.o mixtool.o $(LIBS)

evalprob.o: evalprob.cc evalprob.h 3type.h
genprob.o: genprob.cc genprob.h 3type.h
mixtool.o: mixtool.cc mixtool.h 3type.h
3type.o:   3type.cc genprob.h evalprob.h 3type.h mixtool.h
systems.o: systems.cc genprob.h 3type.h mixtool.h 

#
# The PM _Version (uses genprob and evalprob)
#
pmeq: pmeq1.exe pmeq1.hlp pmeq.ini

RCINC= f:\emx\include
BMPS = al0.bmp al1.bmp al2.bmp al3.bmp al4.bmp al5.bmp al6.bmp al7.bmp al8.bmp al9.bmp \
       nr0.bmp nr1.bmp nr2.bmp nr3.bmp nr4.bmp nr5.bmp nr6.bmp nr7.bmp nr8.bmp nr9.bmp \
       ala0.bmp ala1.bmp ala2.bmp ala3.bmp ala4.bmp ala5.bmp ala6.bmp ala7.bmp ala8.bmp ala9.bmp \
       drag0.ptr drag1.ptr drag2.ptr drag3.ptr drag4.ptr drag5.ptr \
       drag6.ptr drag7.ptr drag8.ptr drag9.ptr \
       draga0.ptr draga1.ptr draga2.ptr draga3.ptr draga4.ptr draga5.ptr \
       draga6.ptr draga7.ptr draga8.ptr draga9.ptr \
       durch.bmp gleich.bmp mal.bmp minus.bmp plus.bmp 
PMOBJ= pmgenprb.o pmmnwin.o pmhelp.o pmini.o

pmeq1: pmeq1.o $(OBJ) $(PMOBJ)
	$(CC) -Zmtd -o pmeq1 pmeq1.o $(OBJ) $(PMOBJ) $(LIBS)

pmeq1.exe: pmeq1 pmeq1.res 
	emxbind -bpq -rpmeq1.res f:\emx\bin\emxl pmeq1

pmeq1.res: pmeq1.rc pmeq1.h pmeq1.ico $(BMPS)
	rc -r -i $(RCINC) pmeq1.rc

pmeq1.o: pmeq1.cc pmeq1.h pmini.h pmmnwin.h pmhelp.h
pmgenprb.o: pmgenprb.cc pmgenprb.h 3type.h genprob.h evalprob.h mixtool.h
pmmnwin.o: pmmnwin.cc pmmnwin.h pmeq1.h pmgenprb.h pmhelp.h pmini.h
pmhelp.o: pmhelp.cc pmhelp.h pmeq1.h
pmini.o: pmini.cc pmini.h pmgenprb.h

# lets build some help
pmeq1.hlp: pmeq1.ipf $(BMPS) pmwin.bmp
	ipfc pmeq1.ipf /W1 /S

pmeq1.ipf: pmeq1.scr pmhelp.h
	ipfcprep pmeq1.scr pmeq1.ipf

# Generating an ini file, by merely copying an empty one
pmeq.ini:
	makeini pmeq.ini pmeq.irc

testini: testini.o
	$(CC) -Zexe -o testini testini.o $(LIBS)

testini.o: testini.cc pmini.h


