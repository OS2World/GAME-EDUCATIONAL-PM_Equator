:userdoc.
.* Get the C - Defines
.*--------------------------------------------------------------*\
.*  Main window extended help panel                             *
:h1 res=2100. Ueber PM-Equator
:i1 id=aboutMain.Ueber PM-Equator

:p.:hp2. PM-Equator :ehp2.-- etwas Gehirnjogging!
:artwork name='help\al0.bmp' runin.

:p.Das ist ein klassisches Zahlenraetsel. Los, uebe es! Beginne mit
einer niedrigen Stufe und beobachte, wie du dich verbesserst und es
schliesslich ganz schaffst.

:p. Das:hp1. Ziel :ehp1. des Spiels ist es, die geheime Anordnung der
Rechnungen korrekt zu rekonstruieren. Du siehst die gesamte Anordnung,
aber jede Ziffer ist durch ein eindeutiges Symbol ersetzt, und dein Ziel
ist es, alle Symbole zu identifizieren.
Einzelheiten siehe :link reftype=hd res=2000.Spielanleitung. :elink.

:p. Vielen Dank an die Zeitschrift :hp1.Games &amp. Puzzles:ehp1. und
besonders an :hp2.Yerry Felix:ehp2. fuer die Anregung zu diesem Programm.

:p. Viel Spass!

:p.
:p. P.S.: Bitte teilt mir alle Kritik und Vorschlaege zur Verbesserung
dieses kleinen Programms mit. Mail an :hp1. nestel@am.uni-erlangen.de:ehp1..

.*--------------------------------------------------------------*\
.*  How to                                                      *
:h1 res=2000. Spielanleitung
:i2 refid=aboutMain.Die Regeln

:p. Nun, ich gehe einmal davon aus, dass du :link reftype=hd res=2100.Ueber PM-Equator :elink.
gelesen hast und die Idee des Spiels kennst: Ziffern in einigen Rechnungen herausfinden. Wenn du
immer noch verwirrt bist, wirf einen Blick auf :link reftype=hd res=7777.Die Idee dahinter:elink..

:p. Denke daran, dass es zwei verschiedene Spielmodi gibt (siehe
:link reftype=hd res=2220.Hardmode :elink.), aber die wichtigste Frage,
die du vielleicht hast, wird hier beantwortet:

:p. :hp3. Wie kann ich die Ziffer fuer ein Symbol eingeben? :ehp3.

:p. Dafuer gibt es zwei verschiedene Methoden: Entweder ueber einen speziellen Zifferndialog
oder durch eine Art simuliertes Ziehen und Ablegen.

:p.:hp1.Der Zifferndialog:ehp1.
:p. Klicke einfach zweimal mit der linken Maustaste auf ein Ziffernsymbol im Raetsel,
daraufhin erscheint ein Dialogfeld, in das du deinen Tipp fuer den Wert dieses Symbols
eingeben kannst.

:p.:hp1.Drag'n drop:ehp1.
:p. Du kannst entweder eine Ziffer aus dem Ziffernfeld ins Raetsel ziehen oder ein Symbol
aus dem Raetsel ins Ziffernfeld: Klicke einmal auf das, was du ziehen willst.
Beobachte, wie sich der Mauszeiger aendert. Bewege ihn dorthin, wo du ablegen willst, und klicke
erneut mit der linken Maustaste.

:note. Immer wenn du ins Ziffernfeld klickst, erhaeltst du eine Ziffer (selbst wenn du auf
ein Symbol klickst), und immer wenn du ins Raetsel klickst, erhaeltst du ein Symbol (selbst
wenn du auf eine Ziffer klickst).

:p. Um dieses Ziehen und Ablegen zu beenden, druecke einmal die rechte Maustaste.

:p.
:note. Du kannst dich auch ueber :link reftype=hd res=2220.Stufe :elink.
ueber das Einstellen der Stufen informieren sowie ueber :link reftype=hd res=4000.Bewertung:elink.,
um deine Leistung zu verbessern.

:h1 res=7770.Die Raetsel
:i2 refid=aboutMain.Die Raetsel

:p. Die von diesem Programm erzeugten Raetsel haben die folgenden
Eigenschaften:
.br
:sbul. Es gibt mindestens eine Punktrechnung (Multiplikation oder Division) und mindestens
eine Addition/Subtraktion.
.br
:sbul. Alle Zahlen sind positiv.
.ve
:sbul. Jede Ziffer von 0 bis 9 kommt mindestens einmal vor.

:note. Die Loesung einiger der einfacheren Raetsel kann :hp2. nicht eindeutig :ehp2..
In diesem Fall ist es deine Aufgabe, das vom Programm erzeugte Raetsel zu rekonstruieren. Das
bringt ein wenig Glueck ins Spiel, das aber auf den hoeheren Stufen verschwindet.


:h1 res=7770.Hauptbildschirm
:i2 refid=aboutMain.Hauptbildschirm
Der Hauptbildschirm des Programms sieht folgendermassen aus
:p.
:artwork name='help\pmwin.bmp'.
:p.
:p.und ist durch horizontale Linien in drei Teile unterteilt.
:p.:hp1.Ueber der oberen Linie:ehp1. befindet sich das Raetsel bzw. seine Loesung.

:p.:hp1.Unterhalb der unteren Linie:ehp1. kannst du deine Punktzahl und die verbleibende Zeit verfolgen.

:p.Im :hp1.mittleren Teil:ehp1. siehst du, welche Ziffern du bereits entschluesselt hast oder
welche noch zu erraten sind.

:note. Die :hp1. beiden oberen Teile:ehp1. des Fensters reagieren auf bestimmte Mausaktionen!
(siehe :link reftype=hd res=2000.Spielanleitung :elink.)


:h1 res=7777. Die Idee dahinter
:i2 refid=aboutMain sortkey='zzz'.Die Idee dahinter

:p. Falls du noch nie mit :ph2. Equatoren :ph1. zu tun hattest, sehen wir uns einige
Beispiele an. Jedes Symbol

:p.
:artwork name='help\al0.bmp' runin.
:artwork name='help\al1.bmp' runin.
:artwork name='help\al2.bmp' runin.
:artwork name='help\al3.bmp' runin.
:artwork name='help\al4.bmp' runin.
:artwork name='help\al5.bmp' runin.
:artwork name='help\al6.bmp' runin.
:artwork name='help\al7.bmp' runin.
:artwork name='help\al8.bmp' runin.
:artwork name='help\al9.bmp' runin.
:p.
oder
:p.
:artwork name='help\ala0.bmp' runin.
:artwork name='help\ala1.bmp' runin.
:artwork name='help\ala2.bmp' runin.
:artwork name='help\ala3.bmp' runin.
:artwork name='help\ala4.bmp' runin.
:artwork name='help\ala5.bmp' runin.
:artwork name='help\ala6.bmp' runin.
:artwork name='help\ala7.bmp' runin.
:artwork name='help\ala8.bmp' runin.
:artwork name='help\ala9.bmp' runin.
:p.
symbolisiert eine Ziffer.


Wenn du dir also diese Rechnung ansiehst:
:p.
:artwork name='help\al9.bmp' runin.
:artwork name='help\al8.bmp' runin.
:artwork name='help\al0.bmp' runin.
:artwork name='help\plus.bmp' runin.
:artwork name='help\al8.bmp' runin.
:artwork name='help\al9.bmp' runin.
:artwork name='help\al3.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\al1.bmp' runin.
:artwork name='help\al8.bmp' runin.
:artwork name='help\al5.bmp' runin.
:artwork name='help\al3.bmp' runin.

:p.
:p.
Dann kannst du sofort schliessen:
:artwork name='help\al1.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\nr1.bmp' runin.
da die Summe zweier dreistelliger Zahlen eine 0 oder 1 als vierte Ziffer haben muss und
die Ziffer Null nie auf der linken Seite einer Zahl geschrieben wird (wie bei jeder Zahl).
Weiterhin muss es heissen:
:artwork name='help\al0.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\nr0.bmp' runin.
denn
.br
:artwork name='help\al0.bmp' runin.
:artwork name='help\plus.bmp' runin.
:artwork name='help\al3.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\al3.bmp' runin.
muss gelten.

:p.
Etwas schwieriger zu erkennen ist
:artwork name='help\al9.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\nr9.bmp' runin.
und schliesslich
:artwork name='help\al8.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\nr8.bmp' runin.
aber es stimmt! Und wir koennen abschliessend folgern:
:p.
:artwork name='help\nr9.bmp' runin.
:artwork name='help\nr8.bmp' runin.
:artwork name='help\nr0.bmp' runin.
:artwork name='help\plus.bmp' runin.
:artwork name='help\nr8.bmp' runin.
:artwork name='help\nr9.bmp' runin.
:artwork name='help\al3.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\nr1.bmp' runin.
:artwork name='help\nr8.bmp' runin.
:artwork name='help\nr7.bmp' runin.
:artwork name='help\al3.bmp' runin.

:p.
:p. das sieht schon etwas weniger geheimnisvoll aus als der Ausgangspunkt.

Durch solches logisches Schliessen und ein wenig Probieren kann man alle :hp2. Equatoren :ehp2.
loesen, die dieses Programm erzeugt. Viel Glueck!

:note. Das obige Beispiel ist sehr einfach und soll dir nur eine Idee geben;
normalerweise kannst du nicht so viel aus einer einzigen Rechnung schliessen.

Um ein paar erste Anhaltspunkte zu bekommen, kannst du dir die
:link reftype=hd res=2213.Loesungen:elink.
einiger Raetsel ansehen


.*--------------------------------------------------------------*\
.*  Game menu                                                   *
:h1 res=2200. Das Equator-Menue
:i1 id=Game sortkey='zzzzzzz'.Equator-Menue
:p.Das Spielmenue enthaelt die Befehle, mit denen du die Stufe zum
Spielen waehlst und die Anwendung beendest.
Die folgenden Befehle erscheinen im Dateimenue:
:parml tsize=15 break=all.
:pt.Stufe
:pd.Es erscheint ein Dialogfeld, in das zwei Stufen eingegeben werden koennen: eine als
untere und eine als obere Grenze. Gueltige Stufen reichen von 1 bis 50.
:pt.Neu
:pd.Es wird zufaellig ein neues Raetsel erzeugt.
:pt.Loesung
:pd.Zeigt die Loesung des angezeigten Raetsels.
:pt.Bestenliste
:pd.Zeigt die Bestenliste.
:pt.Stufe
:pd.Aendern (siehe Einstellung :link reftype=hd res=2220.Stufe :elink.
:pt.Hardmode
:pd.Umschalten auf :link reftype=hd res=2223.Hardmode :elink.
:pt.Alpha
:pd.Umschalten zwischen Alpha- oder Symbolschrift fuer die verschluesselten Ziffern.
:pt.Igel
:pd.Schaltet den speziellen Mauszeiger ein/aus.
:pt.Beenden
:pd.Nun, manchmal muss man das Spielen beenden und etwas Arbeit erledigen.
:eparml.

.*--------------------------------------------------------------*\
.*  Game menu Choose Level command help panel                   *
:h1 res=2220. Stufe
:i2 refid=Game.Stufe
:p. Es erscheint ein Dialogfeld, in das du die beiden gewuenschten
Stufen eingeben kannst. Gueltige Stufen reichen von 1 bis 50. Die obere Stufe
muss :hp1. groesser :eph1. sein als die untere!

:note. Es gibt eine andere Moeglichkeit, das Spiel leichter oder schwerer zu machen:
Siehe :link reftype=hd res=2223.Hardmode :elink.

Die Stufeneinstellung wird in der :hp2. .ini :ehp2. -Datei gespeichert.

Los! Uebe dich und erhoehe die Stufe hin und wieder.
Beobachte, wie sich deine Punktzahl mit der Zeit verbessert.

:note. Das Einstellen einer neuen Stufe erzeugt sofort ein neues Raetsel,
ein Vorgang, der auf einem langsamen Rechner einige Sekunden dauern kann
(vgl. :link reftype=hd res=2210.Neu :elink.)

.*--------------------------------------------------------------*\
.*  Game menu Next Level command help panel                     *
:h1 res=2210. Neu
:i2 refid=Game.Neu
:p.Mit dem Menuepunkt :hp1.Spiel-Neu:ehp1. wird ein neuer :hp2. Equator:ehp2. erzeugt.

:note. Das kann auf einem langsamen Rechner einige Sekunden dauern, da das
Programm viele Raetsel erzeugt und wieder verwirft, wenn sie nicht bestimmten
Kriterien entsprechen (:hp1. hauptsaechlich deiner Stufeneinstellung:ehp1.; das
Erzeugen sehr leichter oder sehr schwerer Aufgaben kann dauern).

:h1 res=2213. Loesung
:i2 refid=Game.Loesung
:p. Mit dem Menuepunkt :hp1. Equator-Loesung:ehp1. wird die Loesung des Raetsels angezeigt.

:note. Wenn du nicht weisst, wie du :hp2. Equator:ehp2. lernen sollst, kannst du
mit :link reftype=hd res=2210.Neu:elink. einige Raetsel erzeugen und dir
die Loesungen ansehen.

:h1 res=2216.Bestenliste
:i2 refid=Game.Bestenliste
:p. Du kannst die Bestenliste sehen, indem du diesen Eintrag auswaehlst.

:note. Es werden drei Arten von Bestenlisten gefuehrt: Die 4 hoechsten Punktzahlen im
Hardmode, die 4 hoechsten Punktzahlen im Easymode und die 2 schnellsten Loesungen im Easymode.

:note. Die Bestenliste wird in der INI-Datei des Programms gespeichert, jeweils mit Ausnahme
des jeweils letzten Eintrags einer Art. So kannst du deine Leistung jedes Mal
verfolgen, wenn du spielst.

:h1 res=2226.Alpha
:i2 refid=Game.Alpha
:p. Mit diesem ankreuzbaren Menuepunkt kannst du zwischen zwei verschiedenen
Symbolsaetzen umschalten.

:note. Wenn du :link reftype=hd res=2223.Hardmode:elink.
spielst, kannst du nur den Alpha-Modus verwenden. Die Drag &amp. Drop-Mauszeiger
(siehe :link reftype=hd res=2000.Spielanleitung:elink.) passen nur zu den
Symbolen des Alpha-Modus.

:h1 res2227.Igel-Mauszeiger
:i2 refid=Game.Mauszeiger
:p. :ph2. Equator :ehp2. bringt einen speziellen Mauszeiger mit; wenn er dir
nicht gefaellt, kannst du ihn hier ausschalten. Uebrigens: Die Nase ist der :ph1. heisse
Punkt:hp2., aber das ist etwas verwirrend...

.*--------------------------------------------------------------*\
.*  Game menu Hardmode
.*--------------------------------------------------------------*/
:h1 res=2223.Hardmode
:i2 refid=Hardmode.Hardmode

:p. Ein Klick auf diesen Menuepunkt setzt oder entfernt das Haekchen fuer
:ph1. Hardmode :ehp1.. Ich empfehle den Hardmode nicht fuer Anfaenger!

:p. Es gibt zwei verschiedene Arten, :ph2. Equator :ehp2. zu spielen.

:p. Im :ph1.Easymode:ehp1. wird deine Eingabe jedes Mal ueberprueft, wenn du
eine Ziffer eingibst. Wenn du richtig liegst, bist du richtig; wenn du falsch liegst, bekommst
du eine Strafe (Siehe: :link reftype=hd res=4000.Bewertung:elink.).

:p. Im :ph1.Hardmode:ehp1 kannst du alle Ziffern eingeben. Das Programm
ueberprueft die Richtigkeit deiner Theorie erst, wenn du die :ph2. letzte Ziffer
:ehp2. eingibst. Das ist natuerlich viel schwieriger.

:note. Es gibt eine andere Moeglichkeit, das Spiel leichter oder schwerer zu machen:
Siehe :link reftype=hd res=2220.Stufe :elink.

Die Hardmode-Einstellung wird in der :hp2. .ini :ehp2. -Datei gespeichert.

Versuche, so richtig zaeh zu werden, spiele den Hardmode.

:note. Das Umschalten des Hardmode erzeugt sofort ein neues Raetsel,
ein Vorgang, der auf einem langsamen Rechner einige Sekunden dauern kann
(vgl. :link reftype=hd res=2210.Neu :elink.)


.*--------------------------------------------------------------*\
.*  Game menu Exit command help panel                           *
:h1 res=2230 PANEL_Exit.Beenden
:i2 refid=Game.Beenden
:p. Irgendwann ist es wieder Zeit, etwas Arbeit zu erledigen; verwende diesen
Befehl, wenn du dich dazu bereit fuehlst:

:p. Die Anwendung wird ueber den Befehl Beenden beendet. Um
die Beispielanwendung zu beenden, gehe wie folgt vor:

:p. Waehle das Spielmenue und danach den Befehl Beenden.

.*--------------------------------------------------------------*\
.*  Main Help menu                                              *
:h1 res=2910. Hilfemenue
:p.Hier bekommst du Hilfe!

.*--------------------------------------------------------------*\
.*  Help menu Save As command help panel                        *
:h1 res=2920. Index
:p.Hier Informationen fuer den Menuepunkt Hilfe-Index einfuegen.

.*--------------------------------------------------------------*\
.*  Help menu General help help panel                           *
.*      res = PANEL_HELPGENERAL                                 *
.*--------------------------------------------------------------*/
:h1 res=2930. Allgemeine Hilfe
:p.Hier Informationen fuer den Menuepunkt Allgemeine Hilfe einfuegen.
:note.Dieser Bildschirm wird normalerweise von der Standard-Hilfe uebernommen.

.*--------------------------------------------------------------*\
.*  Help menu Using help help panel                             *
:h1 res=2940. Hilfe verwenden
:p. Was soll ich sagen?

:p. Es ist Hilfe zur Benutzung der Hilfe!


.*--------------------------------------------------------------*\
.*  Help menu Product information help panel                    *
:h1 res=2970.Produktinformation
:p.PM :ph2. Equator:ehp2. wurde von Frank Sven Nestel geschrieben
:p.(:hp1. nestel@am.uni-erlangen.de :ehp1.).

:p.Bitte wirf einen Blick auf die Produktinformation!

:p.Wenn dir dieses Programm gefaellt, kannst du es gerne registrieren!

.*--------------------------------------------------------------*\
.*  Help for Product information                                *
:h1 res=3100.Produktinformation-Dialog
:p.Dieser Dialog zeigt Informationen ueber die Anwendung, wie zum
    Beispiel Versionsnummer und Urheberrechtsvermerk.

:p. ;-)


.*--------------------------------------------------------------*\
.*  About Box Dialog Ok button                                  *
:h1 res=3110.Weiter
:p.Der Schalter Weiter schliesst den Produktinformation-Dialog.

.*--------------------------------------------------------------*\
:h1 res=4000.Bewertung
:i1 id=Scoring.Bewertung
:p. Nun, die Bewertung ist etwas kompliziert. Es gibt zwei verschiedene
Bewertungsmethoden. Eine fuer :link reftype=hd res=7002.Easymode:elink.
und eine fuer :link reftype=hd res=2223.Hardmode:elink..

:h2 res=7002.Easymode
:i2 refid=Scoring.Easymode
:p. Zu Beginn erhaeltst du eine Grundpunktzahl und etwas :hp1.Freizeit :ehp1.
Je hoeher die Stufe (siehe :link reftype=hd res=2220.Stufe:elink.),
desto mehr Grundpunkte bekommst du. Solange du in deiner Freizeit bist,
steigt deine Punktzahl langsam; wenn deine Freizeit abgelaufen ist, sinkt deine Punktzahl; diese
Abnahme haengt ein wenig von der Zahl der bereits identifizierten Ziffern ab.
Immer wenn du eine Ziffer identifizierst, erhaeltst du neue Freizeit. Wenn du beim
Identifizieren einer Ziffer einen Fehler machst, bekommst du eine Strafe und verlierst etwas
Freizeit. Diese Strafe steigt mit jedem Fehler, sei also vorsichtig.

:p. Du kannst deine Punktzahl, Fehler, Zeit und Freizeit im unteren Teil des
Fensters verfolgen.

:note. Es gibt zwei verschiedene Modi, aber drei verschiedene Bestenlisten, siehe
:link reftype=hd res=2216.Bestenliste:elink.

:p. Fuer :link reftype=hd res=7001.Hardmode:elink.
gibt es eine andere Bewertungsmethode.

:h2 res=7001.Hardmode
:i2 refid=Scoring.Hardmode
:p.Der Hardmode ist einfacher als der :link reftype=hd res=7002.Easymode:elink..
Da es keine Zwischenraten von Ziffern gibt (wenn du am Ende richtig liegst, gut,
andernfalls bist du voellig verloren), erleidest du eine konstante Zeitstrafe. Obwohl du
mit mehr Freizeit beginnst, bekommst du waehrend des Spiels keine neue Freizeit,
so dass die Punktzahl hauptsaechlich von der Zeit abhaengt.

:p. Du kannst deine Punktzahl, Fehler, Zeit und Freizeit im unteren Teil des
Fensters verfolgen.

:note. Es gibt zwei verschiedene Modi, aber drei verschiedene Bestenlisten, siehe
:link reftype=hd res=2216.Bestenliste:elink.


:h1 res=9990.. Noch etwas Werbung
:i1 id=ads sortkey='zzzz'.Noch etwas Werbung

:p. Vielleicht ist dir in diesem Programm hin und wieder ein Igel
aufgefallen.
.br 
:artwork name='help\igel3.bmp' runin.
.br 
das ist das Logo einer kleinen Spielefirma aus Sueddeutschland:
.br
Wir nennen uns Doris &amp. Frank oder kurz D&amp.F und wir haben bereits einige
:hp2. Brett:ehp2.spiele veroefentlicht, und dieses Programm ist Franks erster Versuch,
ein wenig Shareware herzustellen.

Wenn du dich fuer :hp1. Brettspiele :ehp1. interessierst (hauptsaechlich kleine),
schau dir Ken Tidwells oder meine WWW - Seiten an&colon.
.br
:hp1. http&colon.//www.kaleida.com/u/tidwell/GameCabinet.html :ehp1.
.br
dort findest du sehr, sehr gute Informationen, und uns findest du
unter den Herausgebern (publishers).

:p.
Du kannst uns auch einen Brief schreiben an
:p.
Doris &amp. Frank
.br 
Obere Buech 24
.br 
D-91054 Buckenhof
.br 
Deutschland
:p.
Danke!


:h1 res=9990.. Registrieren?
:i1 id=reg sortkey='zzzz'.Registrieren

:p. Wenn du so freundlich bist und dieses Programm registrieren moechtest, schicke
mir bitte einen Euroscheque ueber 10 DM (das ist fuer mich die einzige Moeglichkeit, ihn
ohne 30 DM Gebuehren einzuloesen) an
:p.
Frank Sven Nestel
.br 
Obere Buech 24
.br 
D-91054 Buckenhof
.br 
Deutschland
:p.
Wenn du auf andere Weise bezahlen moechtest (z.B. wenn du aus
Deutschland kommst), frage mich bitte erst:
.br
:hp1. nestel@am.uni-erlangen.de:ehp1.

:note. Ich kann dir noch keine Upgradegarantien, gedruckte Dokumentation
oder weitere Programme von mir anbieten. Das Einzige, was ich tun kann, ist mit dir in Kontakt
zu bleiben. Wenn das klappt, habe ich viele Ideen fuer weitere kleine Programme dieser Art,
und vielleicht auch ein paar groessere.

:p.
Danke fuer alles!

:p.
:p. P.S.: Bitte teilt mir alle Kritik und Vorschlaege zur Verbesserung
dieses kleinen Programms mit.

:euserdoc.