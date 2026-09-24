:userdoc.
.* Get the C - Defines
.*--------------------------------------------------------------*\
.*  Main window extended help panel                             *
:h1 res=2100. Informazioni su PM-Equator
:i1 id=aboutMain.Informazioni su PM-Equator

:p.:hp2. PM-Equator :ehp2.-- un po' di ginnastica per il cervello!
:artwork name='help\al0.bmp' runin.

:p.Questo \232 un classico gioco di numeri. Forza, esercitatevi! Iniziate
con un livello basso e guardatevi migliorare finch\232 riuscirete a
risolverlo tutto.

:p. Lo :hp1. scopo :ehp1. del gioco \232 ricostruire correttamente
la disposizione segreta dei calcoli. Vedete l'intera disposizione,
ma con ogni cifra sostituita da un simbolo unico, e il vostro compito
\232 identificare tutti i simboli.
Per i dettagli vedete :link reftype=hd res=2000.Come giocare. :elink.

:p. Molte grazie alla rivista :hp1.Games &amp. Puzzles:ehp1. e
in particolare a :hp2.Yerry Felix:ehp2. per avermi ispirato
questo programma.

:p. Saluti!

:p.
:p. P.S.: Vi prego di farmi sapere tutte le critiche e i suggerimenti
per migliorare questo piccolo programma. Scrivete a :hp1. nestel@am.uni-erlangen.de:ehp1..

.*--------------------------------------------------------------*\
.*  How to                                                      *
:h1 res=2000. Come giocare
:i2 refid=aboutMain.Le regole

:p. Bene, suppongo che abbiate letto :link reftype=hd res=2100.Informazioni su PM-Equator :elink.
e che conosciate l'idea del gioco: scoprire le cifre di alcuni calcoli. Se siete ancora
confusi, date un'occhiata a :link reftype=hd res=7777.Non ne ho idea:elink..

:p. Ricordate che ci sono due modalit\224 diverse per giocare a questo gioco (vedete
:link reftype=hd res=2220.Hardmode :elink.), ma la cosa principale
che volete sapere \232 spiegata qui:

:p. :hp3. Come posso inserire la cifra di un simbolo? :ehp3.

:p. Ci sono due metodi diversi per farlo: potete usare una speciale finestra
di dialogo per le cifre oppure una sorta di trascinamento simulato.

:p.:hp1.La finestra di dialogo dei numeri:ehp1.
:p. Basta un doppio clic con il tasto sinistro del mouse su un simbolo-cifra del puzzle:
compare una finestra di dialogo e potete inserire la vostra ipotesi sul valore di questo simbolo.

:p.:hp1.Drag'n drop:ehp1.
:p. Potete trascinare una cifra dalla striscia dei numeri sul puzzle oppure un simbolo
dal puzzle verso la striscia dei numeri: fate un clic sull'elemento che volete trascinare.
Osservate come cambia il cursore del mouse. Spostatelo dove volete rilasciarlo e fate
di nuovo clic con il tasto sinistro del mouse.

:note. Ogni volta che fate clic nella striscia dei numeri ottenete una cifra (anche se fate clic su
un simbolo), e ogni volta che fate clic sul puzzle ottenete un simbolo (anche se fate clic
su una cifra).

:p. Per interrompere questo drag'n drop, premete una volta il tasto destro del mouse.

:p.
:note. Potreste anche dare un'occhiata a
:link reftype=hd res=2220.Livello :elink. per impostare i livelli,
a :link reftype=hd res=4000.Punteggio:elink., per massimizzare
le vostre prestazioni.

:h1 res=7770.I puzzle
:i2 refid=aboutMain.I puzzle

:p. I puzzle generati da questo programma hanno le seguenti
caratteristiche:
.br
:sbul. C'\232 almeno un'operazione di prodotto (moltiplicazione o divisione) e almeno
un'addizione o sottrazione.
.br
:sbul. Tutti i numeri sono positivi.
.ve
:sbul. Ogni cifra da 0 a 9 compare almeno una volta.

:note. La soluzione di alcuni dei puzzle pi\249 facili potrebbe essere :hp2. non unica :ehp2..
In questo caso tocca a voi ricostruire il puzzle generato dal programma. Questo
introduce un po' di fortuna nel gioco, ma sparisce ai livelli superiori.


:h1 res=7770.Schermata principale
:i2 refid=aboutMain.Schermata principale
La schermata principale del programma si presenta cos\236:
:p.
:artwork name='help\pmwin.bmp'.
:p.
:p.ed \232 divisa in tre parti da linee orizzontali.
:p.:hp1.Sopra la linea superiore:ehp1. si trova il puzzle o la sua soluzione.

:p.:hp1.Sotto la linea inferiore:ehp1. potete vedere punteggio e tempo rimanente.

:p.Nella :hp1.parte centrale:ehp1. potete vedere quali cifre avete gi\224 decodificato o
che devono ancora essere indovinate.

:note. Le :hp1. due parti superiori:ehp1. della finestra reagiscono ad alcune azioni del mouse!
(vedete :link reftype=hd res=2000.Come giocare :elink.)


:h1 res=7777. Non ne ho idea
:i2 refid=aboutMain sortkey='zzz'.Non ne ho idea

:p. Se non avete mai incontrato :ph2. Equator :ph1. finora, diamo un'occhiata ad alcuni
esempi. Ogni simbolo

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
oppure
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
rappresenta una cifra.


Cos\236, se guardate questo calcolo:
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
Potete concludere subito
:artwork name='help\al1.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\nr1.bmp' runin.
dato che la somma di due numeri a tre cifre deve avere 0 oppure 1 come quarta cifra e
la cifra zero non viene mai scritta a sinistra di un numero (come in ogni numero).
Inoltre deve essere
:artwork name='help\al0.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\nr0.bmp' runin.
dato che 
.br
:artwork name='help\al0.bmp' runin.
:artwork name='help\plus.bmp' runin.
:artwork name='help\al3.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\al3.bmp' runin.
deve valere.

:p.
Un po' pi\249 difficile da vedere \232
:artwork name='help\al9.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\nr9.bmp' runin.
e infine
:artwork name='help\al8.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\nr8.bmp' runin.
ma \232 vero! E possiamo infine concludere
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
:p. che sembra un po' meno criptico del punto di partenza.

Con queste deduzioni e qualche tentativo potete risolvere tutti gli :hp2. Equator :ehp2.
generati da questo programma. Buona fortuna!

:note. Quanto sopra \232 un esempio molto semplice, solo per darvi un'idea:
di solito non potete dedurre cos\236 tanto da un solo calcolo.

Per avere altri primi indizi, potreste dare un'occhiata alle
:link reftype=hd res=2213.Soluzioni:elink.
di alcuni puzzle


.*--------------------------------------------------------------*\
.*  Game menu                                                   *
:h1 res=2200. Il menu di Equator
:i1 id=Game sortkey='zzzzzzz'.Menu di Equator
:p.Il menu di gioco contiene i comandi che usate per scegliere il
livello a cui giocare e per uscire dal programma.
I seguenti comandi compaiono nel menu Equator:
:parml tsize=15 break=all.
:pt.Livello
:pd.Compare una finestra di dialogo in cui potete inserire due livelli: uno come limite inferiore
e uno come limite superiore. I livelli validi vanno da 1 a 50.
:pt.Nuovo
:pd.Viene generato a caso un nuovo puzzle.
:pt.Soluzione
:pd.Mostra la soluzione del puzzle visualizzato.
:pt.Punteggi migliori
:pd.Mostra i punteggi migliori.
:pt.Livello
:pd.Modifica l'impostazione (vedete :link reftype=hd res=2220.Livello:elink.).
:pt.Hardmode
:pd.Passa alla :link reftype=hd res=2223.Hardmode :elink..
:pt.Alpha
:pd.Alterna tra Alpha e Symbolset per le cifre codificate.
:pt.Riccio
:pd.Attiva o disattiva il cursore speciale del mouse.
:pt.Esci
:pd.Bene, a volte tocca smettere di giocare e fare un po' di lavoro.
:eparml.

.*--------------------------------------------------------------*\
.*  Game menu Choose Level command help panel                   *
:h1 res=2220. Livello
:i2 refid=Game.Livello
:p. Compare una finestra di dialogo in cui potete inserire i due livelli
desiderati. I livelli validi vanno da 1 a 50. Il livello superiore deve
essere :hp1. pi\249 grande :eph1. di quello inferiore!

:note. C'\232 un altro modo per rendere il gioco pi\249 facile o pi\249 difficile:
vedete :link reftype=hd res=2223.Hardmode :elink.

L'impostazione del livello \232 memorizzata nel file :hp2. .ini :ehp2..

Forza! Allenatevi e ogni tanto aumentate il livello.
Guardate il vostro punteggio migliorare con il tempo.

:note. Impostare un nuovo livello genera subito un nuovo puzzle,
un processo che su una macchina lenta pu\242 richiedere alcuni secondi (
cfr. :link reftype=hd res=2210.Nuovo :elink.)

.*--------------------------------------------------------------*\
.*  Game menu Next Level command help panel                     *
:h1 res=2210. Nuovo
:i2 refid=Game.Nuovo
:p.Con la voce di menu :hp1.Equator-Nuovo:ehp1. viene generato un nuovo :hp2. Equator:ehp2..

:note. Su un computer lento ci\242 pu\242 richiedere alcuni secondi, poich\232 il
programma genera molti puzzle e li scarta se non soddisfano
determinati criteri (:hp1. principalmente il vostro livello:ehp1.; generare
problemi molto facili o molto difficili pu\242 richiedere tempo).

:h1 res=2213. Soluzione
:i2 refid=Game.Soluzione
:p. Con la voce di menu :hp1. Equator-Soluzione:ehp1. viene mostrata la soluzione del puzzle.

:note. Se non sapete come imparare :hp2. Equator:ehp2., potete generare
alcuni puzzle con :link reftype=hd res=2210.Nuovo:elink. e guardare
le soluzioni.

:h1 res=2216.Punteggi migliori
:i2 refid=Game.Punteggi migliori
:p. Potete vedere i punteggi migliori selezionando questa voce.

:note. Vengono conservati tre tipi di punteggi migliori: i 4 punteggi pi\249 alti in
Hardmode, i 4 punteggi pi\249 alti in Easymode e le 2 soluzioni pi\249 rapide in Easymode.

:note. I punteggi migliori sono conservati nel file ini del programma, tutti tranne l'ultimo
di ciascun tipo. Cos\236 potete controllare le vostre prestazioni ogni volta
che giocate.

:h1 res=2226.Alpha
:i2 refid=Game.Alpha
:p. Con questa voce di menu a spunta potete alternare tra due diversi
insiemi di simboli.

:note. Se giocate in :link reftype=hd res=2223.Hardmode:elink.
potete giocare solo in modalit\224 alpha. I cursori per il drag &amp. drop
(vedete :link reftype=hd res=2000.Come giocare:elink.) corrispondono solo
ai simboli della modalit\224 alpha.

:h1 res2227.Cursore Riccio
:i2 refid=Game.Cursore riccio
:p. :ph2. Equator :ehp2. \232 dotato di un cursore speciale del mouse; se
non vi piace, potete disattivarlo qui. Tra l'altro il naso \232 il :ph1. punto
caldo:hp2., ma \232 un po' sconcertante...

.*--------------------------------------------------------------*\
.*  Game menu Hardmode
.*--------------------------------------------------------------*/
:h1 res=2223.Hardmode
:i2 refid=Hardmode.Hardmode

:p. Facendo clic su questa voce di menu si attiva o si disattiva la spunta per
:ph1. Hardmode :ehp1.. Sconsiglio Hardmode ai principianti!

:p. Ci sono due modi diversi di giocare a :ph2. Equator :ehp2..

:p. In :ph1.Easymode:ehp1. il vostro inserimento viene controllato ogni volta
che inserite una cifra. Se avete ragione, bene; se sbagliate, subite una
penalit\224 (vedete: :link reftype=hd res=4000.Punteggio:elink.).

:p. In :ph1.Hardmode:ehp1 potete inserire tutte le cifre. Il programma
verifica la correttezza delle vostre ipotesi solo quando entrate la :ph2. ultima cifra
:ehp2.. Naturalmente \232 molto pi\249 difficile.

:note. C'\232 un altro modo per rendere il gioco pi\249 facile o pi\249 difficile:
vedete :link reftype=hd res=2220.Livello :elink.

L'impostazione di Hardmode \232 memorizzata nel file :hp2. .ini :ehp2..

Cercate di diventare davvero tosti: giocate in Hardmode.

:note. Attivare o disattivare Hardmode genera subito un nuovo puzzle,
un processo che su una macchina lenta pu\242 richiedere alcuni secondi (
cfr. :link reftype=hd res=2210.Nuovo :elink.)


.*--------------------------------------------------------------*\
.*  Game menu Exit command help panel                           *
:h1 res=2230 PANEL_Exit.Esci
:i2 refid=Game.Esci
:p. A un certo punto \232 di nuovo ora di fare un po' di lavoro, quindi usate
questo comando, se lo desiderate:

:p. Si esce dal programma usando il comando Esci. Per
uscire dall'applicazione di esempio, procedete come segue:

:p. Selezionate il menu Equator e scegliete il comando Esci.

.*--------------------------------------------------------------*\
.*  Main Help menu                                              *
:h1 res=2910. Menu Aiuto
:p.Qui trovate aiuto!

.*--------------------------------------------------------------*\
.*  Help menu Save As command help panel                        *
:h1 res=2920. Indice
:p.Qui vanno inserite le informazioni per la voce Indice del menu di aiuto.

.*--------------------------------------------------------------*\
.*  Help menu General help help panel                           *
.*      res = PANEL_HELPGENERAL                                 *
.*--------------------------------------------------------------*/
:h1 res=2930. Aiuto generale
:p.Qui vanno inserite le informazioni per la voce di menu Aiuto generale.
:note.Questa schermata viene di solito gestita dal comportamento predefinito.

.*--------------------------------------------------------------*\
.*  Help menu Using help help panel                             *
:h1 res=2940. Uso della guida
:p. Che posso dire?

:p. \232 la guida per l'uso della guida!


.*--------------------------------------------------------------*\
.*  Help menu Product information help panel                    *
:h1 res=2970.Informazioni sul prodotto
:p.PM :ph2. Equator:ehp2. \232 stato scritto da Frank Sven Nestel
:p.(:hp1. nestel@am.uni-erlangen.de :ehp1.).

:p.Guardate pure le informazioni sul prodotto!

:p.Se vi piace questo programma, non esitate a registrarlo!

.*--------------------------------------------------------------*\
.*  Help for Product information                                *
:h1 res=3100.Finestra di dialogo delle informazioni sul prodotto
:p.Questa finestra di dialogo mostra informazioni sull'applicazione, come
il numero di versione e la nota di copyright.

:p. ;-)


.*--------------------------------------------------------------*\
.*  About Box Dialog Ok button                                  *
:h1 res=3110.Continua
:p.Il pulsante Continua chiude la finestra di dialogo delle informazioni sul prodotto.

.*--------------------------------------------------------------*\
:h1 res=4000.Punteggio
:i1 id=Scoring.Punteggio
:p. Bene, il punteggio \232 un po' complicato. Ci sono due sistemi di punteggio
diversi. Uno per :link reftype=hd res=7002.Easymode:elink..
uno per :link reftype=hd res=2223.Hardmode:elink..

:h2 res=7002.Easymode
:i2 refid=Scoring.Easymode
:p. All'inizio ricevete un punteggio base e un po' di :hp1.tempo libero :ehp1.
Pi\249 alto \232 il livello (vedete :link reftype=hd res=2220.Livello:elink.),
pi\249 punteggio base ottenete. Se siete nel tempo libero, il vostro
punteggio aumenta lentamente; se il tempo libero finisce, il punteggio diminuisce, e questa
diminuzione \232 leggermente legata al numero di cifre che avete gi\224 identificato.
Ogni volta che identificate una cifra ricevete nuovo tempo libero. Se sbagliate
nell'identificare una cifra subite una penalit\224 e perdete un po' di tempo libero. Questa
penalit\224 aumenta a ogni errore, perci\242 state attenti.

:p. Potete vedere punteggio, errori, tempo e tempo libero nella parte inferiore
della finestra.

:note. Ci sono due modalit\224 diverse, ma tre punteggi migliori diversi; vedete
:link reftype=hd res=2216.Punteggi migliori:elink.

:p. C'\232 un metodo di punteggio diverso per
:link reftype=hd res=7001.Hardmode:elink..

:h2 res=7001.Hardmode
:i2 refid=Scoring.Hardmode
:p.Hardmode \232 pi\249 semplice di :link reftype=hd res=7002.Easymode:elink..
Poich\232 non ci sono tentativi intermedi sulle cifre
(se alla fine avete ragione, bene, altrimenti siete completamente perduti), subite
una penalit\224 costante nel tempo. Sebbene partiate con una maggiore quantit\224 di tempo libero,
non ricevete nuovo tempo libero durante il gioco, quindi il punteggio dipende soprattutto dal tempo.

:p. Potete vedere punteggio, errori, tempo e tempo libero nella parte inferiore
della finestra.

:note. Ci sono due modalit\224 diverse, ma tre punteggi migliori diversi; vedete
:link reftype=hd res=2216.Punteggi migliori:elink.


:h1 res=9990.. Ancora un po' di pubblicit\224
:i1 id=ads sortkey='zzzz'.Ancora un po' di pubblicit\224

:p. Avrete notato di tanto in tanto un riccio
in questo programma.
.br 
:artwork name='help\igel3.bmp' runin.
.br 
questo \232 il logo di una piccola casa di giochi della Germania meridionale:
.br
Ci chiamiamo Doris &amp. Frank o pi\249 brevemente D&amp.F e finora abbiamo pubblicato alcuni
:hp2. giochi da tavolo :ehp2.e questo programma \232 il primo tentativo di Frank di produrre
un po' di shareware.

Se siete interessati ai :hp1. giochi da tavolo :ehp1. (soprattutto a quelli piccoli)
date un'occhiata alle pagine WWW di Ken Tidwell o alle mie:
.br
:hp1. http&colon.//www.kaleida.com/u/tidwell/GameCabinet.html :ehp1.
.br
l\224 troverete informazioni molto, molto buone e
ci troverete anche tra gli editori.

:p.
Potete anche scrivere una lettera cartacea a:
:p.
Doris &amp. Frank
.br 
Obere B\252ch 24
.br 
D-91054 Buckenhof
.br 
Germania
:p.
Grazie!


:h1 res=9990.. Registrazione?
:i1 id=reg sortkey='zzzz'.Registrazione

:p. Se siete cos\236 gentili da voler registrare questo programma, vi prego
di inviarmi un eurocheque da 10 DM (questo \232 l'unico modo per me di incassarlo
senza una commissione di 30 DM) a:
:p.
Frank Sven Nestel
.br 
Obere B\252ch 24
.br 
D-91054 Buckenhof
.br 
Germania
:p.
Se preferite pagare in un altro modo (ad esempio se venite dalla
Germania), chiedetemelo prima:
.br
:hp1. nestel@am.uni-erlangen.de:ehp1.

:note. Non posso ancora offrirvi garanzie di aggiornamento, documentazione stampata
o altri miei programmi. L'unica cosa che posso fare \232 restare in contatto con voi.
Se questo funziona ho molte idee per altri piccoli programmi come questo, e
forse anche per qualcuno pi\249 grande.

:p.
Grazie di tutto!

:p.
:p. P.S.: Vi prego di farmi sapere tutte le critiche e i suggerimenti
per migliorare questo piccolo programma.

:euserdoc.