:userdoc.
.* Get the C - Defines
.*--------------------------------------------------------------*\
.*  Main window extended help panel                             *
:h1 res=2100. About PM-Equator
:i1 id=aboutMain.About PM-Equator

:p.:hp2. PM-Equator :ehp2.-- do some brain jogging!
:artwork name='E:\0MEINS\EQUATOR\al0.bmp' runin.

:p.This is a classic number puzzle. Come on, practice it! Start with
a low level and watch yourself improving and finally crack
it all.

:p. The:hp1. object :ehp1. of the game is to correctly reconstruct
the secret array of calculations. You are shown the whole array,
but with each digit replaced by a unique symbol and your aim is
to identify all the symbols. 
For details see :link reftype=hd res=2000.How to play. :elink.

:p. Many thanks to the magazine :hp1.Games &amp. Puzzles:ehp1. and
especially :hp2.Yerry Felix:ehp2. for inspiring me for this program.

:p. Cheers!

:p.
:p. P.S.: Please let me know of all critisisms and suggestions
to improve this little program. Mail :hp1. nestel@am.uni-erlangen.de:ehp1..

.*--------------------------------------------------------------*\
.*  How to                                                      *
:h1 res=2000. How to play the game
:i2 refid=aboutMain.The Rules

:p. Well, I'll assume you've read :link reftype=hd res=2100.About PM-Equator :elink.
and know the idea of the game: Finding out digits in some calculations. If you are still
confused, have a look at :link reftype=hd res=7777.I've any idea:elink..

:p. Remember there are two different modes to play this game (see
:link reftype=hd res=2220.Hardmode :elink.), but the main
thing you might wan't to know is answered here:

:p. :hp3. How can I enter the digit for a symbol? :ehp3.

:p. There are two different methods to do that: You can do it by a special digit
dialog or by a sort of simulated drap and drop.

:p.:hp1.The number dialog:ehp1.
:p. Just click twice with the left mouse button on a digit symbol in the puzzle,
a dialog box pops up and you can enter your guess for the value of this symbol.

:p.:hp1.Drag'n drop:ehp1.
:p. You can either drag a digit from the digit array on the puzzle or a symbol
from the puzzle to the digit array: Click once with the thing you wan't to drag.
Whatch the Mousecursor change. Move it, where you wan't to drop it and click
with the left mouse button again.

:note. Whenever you click in the digit array you get a digit (even if you click on
a symbol) and whenever you click on the puzzle you get a symbol (even if you click
on a digit).

:p. To stop this drag'n drop, press the right mouse button once.

:p.
:note. You might also have a look to
:link reftype=hd res=2220.Level :elink. about setting levels,
to :link reftype=hd res=4000.Scoring:elink., to maximize your
performance.

:h1 res=7770.The Puzzles
:i2 refid=aboutMain.The Puzzles

:p. The puzzles generated by this program have the following
features:
.br
:sbul. There is at least one dot operation (multiply or divide) and at least
an addition/subtraction.
.br
:sbul. All numbers are positive.
.ve
:sbul. Each digit 0,..,9 appears at least once.

:note. The solution of some of the easier puzzles might be :hp2. non unique :ehp2..
In this case it is your task to reconstruct the puzzle generated by the program. This
introduces a bit of luck in the game, but disappears at the higher levels.


:h1 res=7770.Main screen
:i2 refid=aboutMain.Main screen
The main screen of the program looks like
:p.
:artwork name='E:\0MEINS\EQUATOR\pmwin.bmp'.
:p.
:p.and is divided into three parts by horizontal lines.
:p.:hp1.Above the upper line:ehp1. is the puzzle or it's solution.

:p.:hp1.Below the lower line:ehp1. you can watch your score and remaining time.

:p.In the :hp1.middle part:ehp1. you can see which digits you allready decoded or
still to be guessed.

:note. The :hp1. upper two parts:ehp1. of the window are sensitive to certain mouse actions!
(see :link reftype=hd res=2000.How to play :elink.)


:h1 res=7777. I've any idea
:i2 refid=aboutMain sortkey='zzz'.I've any idea

:p. If you never came across :ph2. Equators :ph1. yet, lets look at some
examples. Each Symbol

:p.
:artwork name='E:\0MEINS\EQUATOR\al0.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al1.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al2.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al3.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al4.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al5.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al6.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al7.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al8.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al9.bmp' runin.
:p.
or
:p.
:artwork name='E:\0MEINS\EQUATOR\ala0.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\ala1.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\ala2.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\ala3.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\ala4.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\ala5.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\ala6.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\ala7.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\ala8.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\ala9.bmp' runin.
:p.
symbolizes a digit.


So, if you look at this calculation:
:p.
:artwork name='E:\0MEINS\EQUATOR\al9.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al8.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al0.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\plus.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al8.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al9.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al3.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\gleich.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al1.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al8.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al5.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al3.bmp' runin.

:p.
:p.
You can conclude immediately
:artwork name='E:\0MEINS\EQUATOR\al1.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\gleich.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\nr1.bmp' runin.
since the sum of two 3 digit numbers must have a 0 or 1 as 4th digit and
the digit zero is never written on the left hand of a number (as with any number).
Furthermore it has to be
:artwork name='E:\0MEINS\EQUATOR\al0.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\gleich.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\nr0.bmp' runin.
since 
.br
:artwork name='E:\0MEINS\EQUATOR\al0.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\plus.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al3.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\gleich.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al3.bmp' runin.
must hold.

:p.
A bit more difficult to see is
:artwork name='E:\0MEINS\EQUATOR\al9.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\gleich.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\nr9.bmp' runin.
and finally
:artwork name='E:\0MEINS\EQUATOR\al8.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\gleich.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\nr8.bmp' runin.
but it's true! And we can finally conclude
:p.
:artwork name='E:\0MEINS\EQUATOR\nr9.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\nr8.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\nr0.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\plus.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\nr8.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\nr9.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al3.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\gleich.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\nr1.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\nr8.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\nr7.bmp' runin.
:artwork name='E:\0MEINS\EQUATOR\al3.bmp' runin.

:p.
:p. which looks a bit less cryptical than the starting point.

By such deducing and some trials one can solve all :hp2. Equators :ehp2.
generated by this program. Good look!

:note. The above is a very simple example, just to give you an idea,
normally you can't conclude so much from just one calculation.

To get some more first clues, you might like to peak at the 
:link reftype=hd res=2213.Solutions:elink.
of some puzzles 


.*--------------------------------------------------------------*\
.*  Game menu                                                   *
:h1 res=2200. The Equator Menu
:i1 id=Game sortkey='zzzzzzz'.Equator Menu
:p.The Game menu contains commands that you use to choose the
level to play and to exit the application.
The following commands appear in the File menu:
:parml tsize=15 break=all.
:pt.Level
:pd.A dialog box appears where two levels can be entered: One as a lower
and one as a upper bound. Legal levels range from 1 to 50.
:pt.New
:pd.A new puzzle is generated at random.
:pt.Solution
:pd.Give the solution of the displayed puzzle.
:pt.Highscores
:pd.Show highscores.
:pt.Level
:pd.Change (see :link reftype=hd res=2220.level :elink. setting.
:pt.Hardmode
:pd.Switch to :link reftype=hd res=2223.Hardmode :elink.
:pt.Alpha
:pd.Switch between Alpha or Symbolset for coded digits.
:pt.Hedgehog
:pd.Switch on/off the special mouse cursor.
:pt.Exit
:pd.Well, sometimes one has to end playing and do some work.
:eparml.

.*--------------------------------------------------------------*\
.*  Game menu Choose Level command help panel                   *
:h1 res=2220. Level
:i2 refid=Game.Level
:p. A dialog box appears where you can enter the two desired
levels. Legal levels range from 1 to 50. The upper level has
to be :hp1. bigger :eph1. than the lower!

:note. There is another way to make the game easier or harder:
See :link reftype=hd res=2223.Hardmode :elink.

The level setting is stored in the :hp2. .ini :ehp2. file.

Come on! Practice yourself and increase the level every now
and then. Watch your score improve with time.

:note. Setting a new level immediately generates a new puzzle,
a process which can take a few seconds on a slow machine (
cf. :link reftype=hd res=2210.New :elink.)

.*--------------------------------------------------------------*\
.*  Game menu Next Level command help panel                     *
:h1 res=2210. New
:i2 refid=Game.New
:p.With the menu selection :hp1.Game-New:ehp1. a new :hp2. Equator:ehp2. is generated.

:note. This may take a few seconds on a slow computer, since the
program generates a lot of puzzles and discards them if they don't
fit certain criteria (:hp1. mainly your level setting:ehp1., generating
very easy or very difficult problems may take time).

:h1 res=2213. Solution
:i2 refid=Game.Solution
:p. With the menu selection :hp1. Equator-Solution:ehp1. the solution of the puzzle is shown.

:note. If you don't know how to learn :hp2. Equator:ehp2. you might generate
some puzzles with :link reftype=hd res=2210.New:elink. and look
at the solutions.

:h1 res=2216.Highscores
:i2 refid=Game.Highscores
:p. You can see the Highscores by selecting this item.

:note. There are three types of Highscores kept: The 4 highest scores in
Hardmode, the 4 highest scores in Easymode and the 2 fastest solutions in Easymode.

:note. The highscores are kept in the programs ini file, all but the very last one
of each type. This allows you to watch your performance every
time you play.

:h1 res=2226.Alpha
:i2 refid=Game.Alpha
:p. You can toggle between two different sets of symbols with this
checkmark menu item.

:note. If you play :link reftype=hd res=2223.Hardmode:elink.
you can only play with alpha mode. Drag & drop cursors 
(see :link reftype=hd res=2000.How to play:elink.) only match
alpha mode symbols.

:h1 res2227.Hedgehog Cursor
:i2 refid=Game.Cursor
:p. :ph2. Equator :ehp2. comes with a special mouse cursor, if you
don't like it, you can switch it of here. Btw. the nose is the :ph1. hot
spot:hp2., but it's a bit confusing...

.*--------------------------------------------------------------*\
.*  Game menu Hardmode
.*--------------------------------------------------------------*/
:h1 res=2223.Hardmode
:i2 refid=Hardmode.Hardmode

:p. Clicking on this menuitem toggles the checkmark for 
:ph1. Hardmode :ehp1.. I do not recommend Hardmode for beginners!

:p. There are two different ways to play :ph2. Equator :ehp2..

:p. In :ph1.Easymode:ehp1. your input is checked, whenever you enter
a digit. If you are right, you are right, if you are wrong, you suffer a
penalty (See: :link reftype=hd res=4000.Scoring:elink.).

:p. In :ph1.Hardmode:ehp1 you can enter all digits. The program
checks the correctness of your theory only when you enter the :ph2. last digit
:ehp2.. This is naturally much more difficult.

:note. There is another way to make the game easier or harder:
See :link reftype=hd res=2220.Level :elink.

The Hardmode setting is stored in the :hp2. .ini :ehp2. file.

Try to get really tuff, play the Hardmode.

:note. Toggling Hardmode immediately generates a new puzzle,
a process which can take a few seconds on a slow machine (
cf. :link reftype=hd res=2210.New :elink.)


.*--------------------------------------------------------------*\
.*  Game menu Exit command help panel                           *
:h1 res=2230 PANEL_Exit.Exit
:i2 refid=Game.Exit
:p. Some time its time to do some work again, so use this
command, if you feel so:

:p. You quit the application by using the Exit command. To
quit the Sample application, do the following:

:p. Select the Game menu and choose the Exit command.

.*--------------------------------------------------------------*\
.*  Main Help menu                                              *
:h1 res=2910. Help Menu
:p.Here you get help!

.*--------------------------------------------------------------*\
.*  Help menu Save As command help panel                        *
:h1 res=2920. Index
:p.Place information for the Help Index menu item here.

.*--------------------------------------------------------------*\
.*  Help menu General help help panel                           *
.*      res = PANEL_HELPGENERAL                                 *
.*--------------------------------------------------------------*/
:h1 res=2930. General help
:p.Place information for the General Help menu item here.
:note.This screen will usually be handled by the default.

.*--------------------------------------------------------------*\
.*  Help menu Using help help panel                             *
:h1 res=2940. Using Help
:p. What can I say?

:p. It's help for using help!


.*--------------------------------------------------------------*\
.*  Help menu Product information help panel                    *
:h1 res=2970.Product information
:p.PM :ph2. Equator:ehp2. was written by Frank Sven Nestel
:p.(:hp1. nestel@am.uni-erlangen.de :ehp1.).

:p.Please have a look at the product information!

:p.If you like this program, feel free to register it!

.*--------------------------------------------------------------*\
.*  Help for Product information                                *
:h1 res=3100.Product information dialog
:p.This dialog displays information about the application, such
    as version number and copyright notice.

:p. ;-)


.*--------------------------------------------------------------*\
.*  About Box Dialog Ok button                                  *
:h1 res=3110.Continue
:p.The Continue button closes the Product information dialog.

.*--------------------------------------------------------------*\
:h1 res=4000.Scoring
:i1 id=Scoring.Scoring
:p. Well the scoring is a bit difficult. There are two different scoring
schemes. One for :link reftype=hd res=7002.Easymode:elink..
one for :link reftype=hd res=2223.Hardmode:elink..

:h2 res=7002.Easymode
:i2 refid=Scoring.Easymode
:p. In the beginning you receive a base score and a bit of :hp1.free time :ehp1.
The higher the level (see :link reftype=hd res=2220.Level:elink.),
the more base score you get. If you are in your free time, your
score increases slowly, if you run out of free time, your score decreases, this
decrease is slightly coupled with the number of digits you allready identified.
Whenever you identify a digit you receive new free time. When you make a mistake
while identifying a digit you suffer a penalty and loose some free time. This 
penalty increases with each mistake, so be carefull.

:p. You can watch your score, errors, time and free time in the lower part of
the window.

:note. There are two different modes, but three different highscores, see
:link reftype=hd res=2216.Highscores:elink.

:p. There is a differnt Scoring method for
:link reftype=hd res=7001.Scoring.Hardmode:elink.

:h2 res=7001.Hardmode
:i2 refid=Scoring.Hardmode
:p.Hardmode is simpler than :link reftype=hd res=7002.Scoring.Easymode:elink..
Since there are no in between guesses of digits
(if you are right in the end, ok, otherwise you are completely lost) and so you suffer
a constant penalty in time. Though you start with a higher amount of free time, you
don't get new free time during play, so scoring is mainly dependant on time.

:p. You can watch your score, errors, time and free time in the lower part of
the window.

:note. There are two different modes, but three different highscores, see
:link reftype=hd res=2216.Highscores:elink.


:h1 res=9990.. Some more advertisement
:i1 id=ads sortkey='zzzz'.Some more Advertisement

:p. You may have recognized a hedgehog every now and then
in this program. 
.br 
:artwork name='E:\0MEINS\EQUATOR\igel3.bmp' runin.
.br 
this is the Logo of a small game company from Southern Germany:
.br
We call ourselves Doris &amp. Frank or shorter D&amp.F and we published some
:hp2. board:ehp2.games yet and this program is Franks first trial to produce
some shareware.

If you are interested in :hp1. boardgames :ehp1.  (mainly little ones)
have a look at Ken Tidwells or my WWW - Pages&colon.
.br
:hp1. http&colon.//www.kaleida.com/u/tidwell/GameCabinet.html :ehp1.
.br
you'll find very, very good information there and you'll find
us under publishers.

:p.
You may also write a snail mail to
:p.
Doris &amp. Frank
.br 
Obere B�ch 24
.br 
D-91054 Buckenhof
.br 
Germany
:p.
Thanx!


:h1 res=9990.. Register?
:i1 id=reg sortkey='zzzz'.Register

:p. If you are so kind and wan't to register this program, please
send me eurocheque with 10 DM (thats the only way for me to cash it
without 30DM fee's) to
:p.
Frank Sven Nestel
.br 
Obere B�ch 24
.br 
D-91054 Buckenhof
.br 
Germany
:p.
If wan't to pay in a different way (e.g. if you are from
Germany), please first ask me:
.br
:hp1. nestel@am.uni-erlangen.de:ehp1.

:note. I can't offer you any upgrade garanties, printed documentation
other programs of mine yet. The only thing I can do, is keep in touch with you.
If this works out I've a lot of ideas for more little programs like that, and
maybe some bigger ones.

:p.
Thanx for anything!

:p.
:p. P.S.: Please let me know of all critisisms and suggestions
to improve this little program. 

:euserdoc.
