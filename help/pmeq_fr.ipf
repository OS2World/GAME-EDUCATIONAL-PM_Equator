:userdoc.
.* Get the C - Defines
.*--------------------------------------------------------------*\
.*  Main window extended help panel                             *
:h1 res=2100. A\192 propos de PM-Equator
:i1 id=aboutMain.A\192 propos de PM-Equator

:p.:hp2. PM-Equator :ehp2.-- faites travailler vos m\233ninges !
:artwork name='help\al0.bmp' runin.

:p.C'est un jeu de chiffres classique. Allez, entra\238nez-vous ! Commencez
\224 un niveau peu \233lev\233 et regardez-vous progresser jusqu'\224 tout
r\233soudre.

:p. Le :hp1. but :ehp1. du jeu est de reconstituer correctement
l'ensemble secret des calculs. On vous montre l'ensemble complet,
mais chaque chiffre y est remplac\233 par un symbole unique et votre but est
d'identifier tous les symboles.
Pour les d\233tails, voir :link reftype=hd res=2000.Comment jouer. :elink.

:p. Merci beaucoup au magazine :hp1.Games &amp. Puzzles:ehp1. et
en particulier \224 :hp2.Yerry Felix:ehp2. qui m'a inspir\233 ce programme.

:p. Bravo !

:p.
:p. P.S. : Merci de me faire part de toutes les critiques et de toutes les suggestions
pour am\233liorer ce petit programme. \201crivez-moi \224 :hp1. nestel@am.uni-erlangen.de:ehp1..

.*--------------------------------------------------------------*\
.*  How to                                                      *
:h1 res=2000. Comment jouer au jeu
:i2 refid=aboutMain.Les r\232gles

:p. Bon, je suppose que vous avez lu :link reftype=hd res=2100.A\192 propos de PM-Equator :elink.
et que vous connaissez l'id\233e du jeu : retrouver des chiffres dans des calculs. Si vous \234tes
encore perdu, jetez un oeil \224 :link reftype=hd res=7777.Si vous avez une id\233e:elink..

:p. Rappelez-vous qu'il existe deux modes de jeu diff\233rents (voir
:link reftype=hd res=2220.Mode difficile :elink.), mais l'essentiel
que vous voulez savoir est expliqu\233 ici :

:p. :hp3. Comment saisir le chiffre d'un symbole ? :ehp3.

:p. Deux m\233thodes sont possibles : une bo\238te de dialogue consacr\233e aux chiffres
ou une sorte de glisser-d\233poser simul\233.

:p.:hp1.La bo\238te de dialogue des chiffres:ehp1.
:p. Cliquez simplement deux fois avec le bouton gauche de la souris sur un symbole du puzzle,
une bo\238te de dialogue s'affiche et vous pouvez saisir votre proposition pour la valeur de ce symbole.

:p.:hp1.Glisser-d\233poser:ehp1.
:p. Vous pouvez soit faire glisser un chiffre de la r\233serve de chiffres vers le puzzle, soit un
symbole du puzzle vers la r\233serve de chiffres : cliquez une fois sur l'\233l\233ment \224
faire glisser. Observez le curseur de la souris changer. D\233placez-le \224 l'endroit o\249
vous voulez le d\233poser et cliquez de nouveau avec le bouton gauche de la souris.

:note. D\232s que vous cliquez dans la r\233serve de chiffres, vous obtenez un chiffre (m\234me si vous cliquez
sur un symbole) et d\232s que vous cliquez sur le puzzle, vous obtenez un symbole (m\234me si vous cliquez
sur un chiffre).

:p. Pour arr\234ter ce glisser-d\233poser, appuyez une fois sur le bouton droit de la souris.

:p.
:note. Vous pouvez aussi jeter un oeil \224
:link reftype=hd res=2220.Niveau :elink. pour r\233gler les niveaux,
\224 :link reftype=hd res=4000.D\233compte des points:elink., pour optimiser
vos performances.

:h1 res=7770.Les puzzles
:i2 refid=aboutMain.Les puzzles

:p. Les puzzles g\233n\233r\233s par ce programme ont les caract\233ristiques
suivantes :
.br
:sbul. Il y a au moins une op\233ration de multiplication ou de division et au moins
une addition/soustraction.
.br
:sbul. Tous les nombres sont positifs.
.ve
:sbul. Chaque chiffre de 0 \224 9 appara\238t au moins une fois.

:note. La solution de certains des puzzles les plus faciles peut \234tre :hp2. non unique :ehp2..
Dans ce cas, votre t\226che est de reconstituer le puzzle g\233n\233r\233 par le programme. Cela
introduit un peu de chance dans le jeu, mais celle-ci dispara\238t aux niveaux sup\233rieurs.


:h1 res=7770.\311cran principal
:i2 refid=aboutMain.\311cran principal
L'\311cran principal du programme ressemble \224 ceci :
:p.
:artwork name='help\pmwin.bmp'.
:p.
:p.et est divis\233 en trois parties par des lignes horizontales.
:p.:hp1.Au-dessus de la ligne sup\233rieure :ehp1. se trouve le puzzle ou sa solution.

:p.:hp1.Sous la ligne inf\233rieure :ehp1. vous pouvez suivre votre score et le temps restant.

:p.Dans la :hp1.partie du milieu:ehp1. vous pouvez voir les chiffres que vous avez d\233j\224 d\233cod\233s ou
ceux qui restent \224 deviner.

:note. Les :hp1. deux parties sup\233rieures:ehp1. de la fen\234tre r\233agissent \224 certaines actions de la souris !
(voir :link reftype=hd res=2000.Comment jouer :elink.)


:h1 res=7777. Si vous avez une id\233e
:i2 refid=aboutMain sortkey='zzz'.Si vous avez une id\233e

:p. Si vous n'avez encore jamais rencontr\233 :ph2. les Equator :ph1. auparavant, regardons quelques
exemples. Chaque symbole

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
ou
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
repr\233sente un chiffre.


Ainsi, si vous regardez ce calcul :
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
Vous pouvez conclure imm\233diatement
:artwork name='help\al1.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\nr1.bmp' runin.
car la somme de deux nombres \224 trois chiffres doit avoir un 0 ou un 1 comme quatri\232me chiffre et
le z\233ro ne s'\233crit jamais \224 gauche d'un nombre (comme pour tout nombre).
En outre, on doit avoir
:artwork name='help\al0.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\nr0.bmp' runin.
car
.br
:artwork name='help\al0.bmp' runin.
:artwork name='help\plus.bmp' runin.
:artwork name='help\al3.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\al3.bmp' runin.
doit \234tre v\233rifi\233.

:p.
Un peu plus difficile \224 voir est
:artwork name='help\al9.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\nr9.bmp' runin.
et enfin
:artwork name='help\al8.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\nr8.bmp' runin.
mais c'est vrai ! Et nous pouvons enfin conclure
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
:p. ce qui semble un peu moins cryptique que le point de d\233part.

Gr\226ce \224 ce genre de d\233ductions et \224 quelques essais, vous pouvez r\233soudre tous les :hp2. Equator :ehp2.
g\233n\233r\233s par ce programme. Bonne chance !

:note. L'exemple ci-dessus est un exemple tr\232s simple, juste pour vous donner une id\233e ;
normalement, vous ne pouvez pas conclure autant \224 partir d'un seul calcul.

Pour obtenir quelques premiers indices, vous pouvez jeter un oeil aux
:link reftype=hd res=2213.Solutions:elink.
de certains puzzles


.*--------------------------------------------------------------*\
.*  Game menu                                                   *
:h1 res=2200. Le menu Equator
:i1 id=Game sortkey='zzzzzzz'.Menu Equator
:p.Le menu Game contient les commandes qui vous permettent de choisir le
niveau auquel jouer et de quitter l'application.
Les commandes suivantes apparaissent dans le menu File :
:parml tsize=15 break=all.
:pt.Niveau
:pd.Une bo\238te de dialogue s'affiche dans laquelle vous pouvez saisir deux niveaux : l'un comme borne
inf\233rieure et l'autre comme borne sup\233rieure. Les niveaux autoris\233s vont de 1 \224 50.
:pt.Nouveau
:pd.Un nouveau puzzle est g\233n\233r\233 au hasard.
:pt.Solution
:pd.Affiche la solution du puzzle affich\233.
:pt.Meilleurs scores
:pd.Affiche les meilleurs scores.
:pt.Niveau
:pd.Modification (voir :link reftype=hd res=2220.le r\233glage du niveau :elink..
:pt.Mode difficile
:pd.Passe en :link reftype=hd res=2223.Mode difficile :elink.
:pt.Alpha
:pd.Bascule entre l'ensemble Alpha et l'ensemble de symboles pour les chiffres cod\233s.
:pt.H\233risson
:pd.Activer ou d\233sactiver le curseur de souris sp\233cial.
:pt.Quitter
:pd. Eh bien, il faut parfois arr\234ter de jouer et se remettre au travail.
:eparml.

.*--------------------------------------------------------------*\
.*  Game menu Choose Level command help panel                   *
:h1 res=2220. Niveau
:i2 refid=Game.Niveau
:p. Une bo\238te de dialogue s'affiche dans laquelle vous pouvez saisir les deux niveaux
souhait\233s. Les niveaux autoris\233s vont de 1 \224 50. Le niveau sup\233rieur doit
\234tre :hp1. plus grand :eph1. que le niveau inf\233rieur !

:note. Il existe un autre moyen de rendre le jeu plus facile ou plus difficile :
voir :link reftype=hd res=2223.Mode difficile :elink.

Le r\233glage du niveau est enregistr\233 dans le fichier :hp2. .ini :ehp2..

Allez ! Entra\238nez-vous et augmentez le niveau de temps en temps.
Regardez votre score s'am\233liorer avec le temps.

:note. La d\233finition d'un nouveau niveau g\233n\232re imm\233diatement un nouveau puzzle,
un processus qui peut prendre quelques secondes sur une machine lente
(cf. :link reftype=hd res=2210.Nouveau :elink.)

.*--------------------------------------------------------------*\
.*  Game menu Next Level command help panel                     *
:h1 res=2210. Nouveau
:i2 refid=Game.Nouveau
:p.Avec la s\233lection de menu :hp1.Game-Nouveau:ehp1., un nouveau :hp2. Equator:ehp2. est g\233n\233r\233.

:note. Cela peut prendre quelques secondes sur un ordinateur lent, car le
programme g\233n\232re beaucoup de puzzles et les rejette s'ils ne correspondent
pas \224 certains crit\232res (:hp1. principalement votre r\233glage de niveau:ehp1. ; la
g\233n\233ration de probl\232mes tr\232s faciles ou tr\232s difficiles peut prendre du temps).

:h1 res=2213. Solution
:i2 refid=Game.Solution
:p. Avec la s\233lection de menu :hp1. Equator-Solution:ehp1., la solution du puzzle est affich\233e.

:note. Si vous ne savez pas comment apprendre :hp2. Equator:ehp2., vous pouvez g\233n\233rer
quelques puzzles avec :link reftype=hd res=2210.Nouveau:elink. et regarder
les solutions.

:h1 res=2216.Meilleurs scores
:i2 refid=Game.Meilleurs scores
:p. Vous pouvez consulter les meilleurs scores en s\233lectionnant cet \233l\233ment.

:note. Trois types de meilleurs scores sont conserv\233s : les 4 meilleurs scores en mode
difficile, les 4 meilleurs scores en mode facile et les 2 solutions les plus rapides en mode facile.

:note. Les meilleurs scores sont conserv\233s dans le fichier ini du programme, tous sauf le
tout dernier de chaque type. Cela vous permet de suivre vos performances \224 chaque
partie.

:h1 res=2226.Alpha
:i2 refid=Game.Alpha
:p. Gr\226ce \224 cet \233l\233ment de menu \224 coche, vous pouvez basculer entre deux
ensembles de symboles diff\233rents.

:note. Si vous jouez en :link reftype=hd res=2223.Mode difficile:elink.,
vous ne pouvez jouer qu'en mode alpha. Les curseurs de glisser-d\233poser
(voir :link reftype=hd res=2000.Comment jouer:elink.) ne correspondent
qu'aux symboles du mode alpha.

:h1 res2227.Curseur H\233risson
:i2 refid=Game.Curseur
:p. :ph2. Equator :ehp2. est livr\233 avec un curseur de souris sp\233cial ; si vous
ne l'aimez pas, vous pouvez le d\233sactiver ici. Au fait, le nez est le :ph1. point
chaud:hp2., mais c'est un peu d\233routant...

.*--------------------------------------------------------------*\
.*  Game menu Hardmode
.*--------------------------------------------------------------*/
:h1 res=2223.Mode difficile
:i2 refid=Hardmode.Mode difficile

:p. Cliquer sur cet \233l\233ment de menu active ou d\233sactive la coche de
:ph1. Mode difficile :ehp1.. Je ne recommande pas le Mode difficile aux d\233butants !

:p. Il existe deux mani\232res diff\233rentes de jouer \224 :ph2. Equator :ehp2..

:p. En :ph1.Mode facile:ehp1., votre saisie est v\233rifi\233e \224 chaque fois que vous
entrez un chiffre. Si vous avez raison, c'est bon ; si vous avez tort, vous subissez une
p\233nalit\233 (voir : :link reftype=hd res=4000.D\233compte des points:elink.).

:p. En :ph1.Mode difficile:ehp1. vous pouvez saisir tous les chiffres. Le programme
ne v\233rifie la justesse de votre th\233orie que lorsque vous entrez le :ph2. dernier chiffre
:ehp2.. C'est naturellement beaucoup plus difficile.

:note. Il existe un autre moyen de rendre le jeu plus facile ou plus difficile :
voir :link reftype=hd res=2220.Niveau :elink.

Le r\233glage du Mode difficile est enregistr\233 dans le fichier :hp2. .ini :ehp2..

Essayez d'\234tre vraiment costaud, jouez au Mode difficile.

:note. L'activation ou la d\233sactivation du Mode difficile g\233n\232re imm\233diatement
un nouveau puzzle, un processus qui peut prendre quelques secondes sur une machine lente
(cf. :link reftype=hd res=2210.Nouveau :elink.)


.*--------------------------------------------------------------*\
.*  Game menu Exit command help panel                           *
:h1 res=2230 PANEL_Exit.Exit
:i2 refid=Game.Quitter
:p. Le moment vient parfois de reprendre le travail, alors utilisez cette
commande si le coeur vous en dit :

:p. Vous quittez l'application au moyen de la commande Quitter. Pour
quitter l'application exemple, proc\233dez comme suit :

:p. S\233lectionnez le menu Game et choisissez la commande Quitter.

.*--------------------------------------------------------------*\
.*  Main Help menu                                              *
:h1 res=2910. Menu d'aide
:p.Ici, vous obtenez de l'aide !

.*--------------------------------------------------------------*\
.*  Help menu Save As command help panel                        *
:h1 res=2920. Index
:p.Placez ici les informations pour l'\233l\233ment de menu Index de l'aide.

.*--------------------------------------------------------------*\
.*  Help menu General help help panel                           *
.*      res = PANEL_HELPGENERAL                                 *
.*--------------------------------------------------------------*/
:h1 res=2930. Aide g\233n\233rale
:p.Placez ici les informations pour l'\233l\233ment de menu Aide g\233n\233rale.
:note.Cet \233cran est en g\233n\233ral pris en charge par la valeur par d\233faut.

.*--------------------------------------------------------------*\
.*  Help menu Using help help panel                             *
:h1 res=2940. Utilisation de l'aide
:p. Que puis-je dire ?

:p. C'est de l'aide pour utiliser l'aide !


.*--------------------------------------------------------------*\
.*  Help menu Product information help panel                    *
:h1 res=2970.Informations sur le produit
:p.PM :ph2. Equator:ehp2. a \233t\233 \233crit par Frank Sven Nestel
:p.(:hp1. nestel@am.uni-erlangen.de :ehp1.).

:p.Veuillez consulter les informations sur le produit !

:p.Si vous aimez ce programme, n'h\233sitez pas \224 l'enregistrer !

.*--------------------------------------------------------------*\
.*  Help for Product information                                *
:h1 res=3100.Bo\238te de dialogue Informations sur le produit
:p.Cette bo\238te de dialogue affiche des informations sur l'application, telles
que le num\233ro de version et la mention de copyright.

:p. ;-)


.*--------------------------------------------------------------*\
.*  About Box Dialog Ok button                                  *
:h1 res=3110.Continuer
:p.Le bouton Continuer ferme la bo\238te de dialogue Informations sur le produit.

.*--------------------------------------------------------------*\
:h1 res=4000.D\233compte des points
:i1 id=Scoring.D\233compte des points
:p. Eh bien, le d\233compte des points est un peu compliqu\233. Il existe deux syst\232mes
de d\233compte diff\233rents : l'un pour le :link reftype=hd res=7002.Mode facile:elink.,
l'autre pour le :link reftype=hd res=2223.Mode difficile:elink..

:h2 res=7002.Mode facile
:i2 refid=Scoring.Mode facile
:p. Au d\233but, vous recevez un score de base et un peu de :hp1.temps libre :ehp1.
Plus le niveau est \233lev\233 (voir :link reftype=hd res=2220.Niveau:elink.),
plus votre score de base est important. Pendant votre temps libre, votre
score augmente lentement ; si votre temps libre s'\233puise, votre score diminue. Cette
diminution est l\233g\232rement li\233e au nombre de chiffres que vous avez d\233j\224 identifi\233s.
Chaque fois que vous identifiez un chiffre, vous recevez du nouveau temps libre. Lorsque
vous faites une erreur en identifiant un chiffre, vous subissez une p\233nalit\233 et perdez
du temps libre. Cette p\233nalit\233 augmente \224 chaque erreur, alors soyez prudent.

:p. Vous pouvez suivre votre score, vos erreurs, le temps et le temps libre dans la partie
inf\233rieure de la fen\234tre.

:note. Il existe deux modes diff\233rents, mais trois meilleurs scores diff\233rents ; voir
:link reftype=hd res=2216.Meilleurs scores:elink.

:p. Il existe une m\233thode de d\233compte diff\233rente pour le
:link reftype=hd res=7001.Mode difficile:elink.

:h2 res=7001.Mode difficile
:i2 refid=Scoring.Mode difficile
:p.Le mode difficile est plus simple que le :link reftype=hd res=7002.Mode facile:elink..
Comme il n'y a pas de v\233rification interm\233diaire des chiffres
(si vous avez raison \224 la fin, tant mieux ; sinon, vous \234tes compl\232tement perdu), vous subissez
une p\233nalit\233 constante en temps. Bien que vous commenciez avec une plus grande quantit\233 de
temps libre, vous n'obtenez pas de nouveau temps libre pendant la partie, si bien que le
d\233compte d\233pend principalement du temps.

:p. Vous pouvez suivre votre score, vos erreurs, le temps et le temps libre dans la partie
inf\233rieure de la fen\234tre.

:note. Il existe deux modes diff\233rents, mais trois meilleurs scores diff\233rents ; voir
:link reftype=hd res=2216.Meilleurs scores:elink.


:h1 res=9990.. Encore un peu de publicit\233
:i1 id=ads sortkey='zzzz'.Encore un peu de publicit\233

:p. Vous avez peut-\234tre remarqu\233 un h\233risson de temps en temps
dans ce programme.
.br
:artwork name='help\igel3.bmp' runin.
.br
c'est le logo d'une petite soci\233t\233 de jeux du sud de l'Allemagne :
.br
Nous nous appelons Doris &amp. Frank, ou plus bri\232vement D&amp.F, et nous avons d\233j\224 publi\233
quelques :hp2. jeux de soci\233t\233:ehp2. ; ce programme est la premi\232re tentative de Frank
pour produire un shareware.

Si vous vous int\233ressez aux :hp1. jeux de soci\233t\233 :ehp1. (principalement les petits),
jetez un oeil aux pages WWW de Ken Tidwell ou aux miennes&colon.
.br
:hp1. http&colon.//www.kaleida.com/u/tidwell/GameCabinet.html :ehp1.
.br
vous y trouverez de tr\232s, tr\232s bonnes informations et vous nous trouverez
dans la liste des \233diteurs.

:p.
Vous pouvez aussi envoyer une lettre \224
:p.
Doris &amp. Frank
.br
Obere B\252ch 24
.br
D-91054 Buckenhof
.br
Allemagne
:p.
Merci !


:h1 res=9990.. Enregistrer ?
:i1 id=reg sortkey='zzzz'.Enregistrer

:p. Si vous \234tes assez aimable pour enregistrer ce programme, veuillez
m'envoyer un euroch\232que de 10 DM (c'est le seul moyen pour moi de l'encaisser
sans payer 30 DM de frais) \224
:p.
Frank Sven Nestel
.br
Obere B\252ch 24
.br
D-91054 Buckenhof
.br
Allemagne
:p.
Si vous souhaitez payer d'une autre mani\232re (par exemple si vous \234tes en
Allemagne), demandez-moi d'abord :
.br
:hp1. nestel@am.uni-erlangen.de:ehp1.

:note. Je ne peux vous offrir aucune garantie de mise \224 jour, ni de documentation
imprim\233e, ni mes autres programmes pour le moment. La seule chose que je peux faire,
c'est rester en contact avec vous. Si cela fonctionne, j'ai beaucoup d'id\233es pour
d'autres petits programmes du m\234me genre, et peut-\234tre aussi quelques plus grands.

:p.
Merci pour tout !

:p.
:p. P.S. : Merci de me faire part de toutes les critiques et de toutes les
suggestions pour am\233liorer ce petit programme.

:euserdoc.