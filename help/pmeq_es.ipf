:userdoc.
.* Get the C - Defines
.*--------------------------------------------------------------*\
.*  Main window extended help panel                             *
:h1 res=2100. Acerca de PM-Equator
:i1 id=aboutMain.Acerca de PM-Equator

:p.:hp2. PM-Equator :ehp2.-- \161un poco de gimnasia mental!
:artwork name='help\al0.bmp' runin.

:p.Este es un cl\225sico acertijo de n\243meros. Vamos, practique! Empiece con
un nivel bajo y obs\233rvese mejorar hasta que, al final, lo
domine por completo.

: El:hp1. objetivo :ehp1. del juego es reconstruir correctamente
la matriz secreta de c\225lculos. Se le muestra toda la matriz,
pero con cada d\237gito sustituido por un s\237mbolo \250nico y su meta es
identificar todos los s\237mbolos. 
Para m\225s detalles vea :link reftype=hd res=2000.C\243mo se juega. :elink.

: Muchas gracias a la revista :hp1.Games &amp. Puzzles:ehp1. y
especialmente a :hp2.Yerry Felix:ehp2. por inspirarme para este programa.

: \161Saludos!

:p.
:p. P.D.: Por favor, h\225ganme llegar todas las cr\237ticas y sugerencias
para mejorar este peque\241o programa. Env\237e un correo a :hp1. nestel@am.uni-erlangen.de:ehp1..

.*--------------------------------------------------------------*\
.*  How to                                                      *
:h1 res=2000. C\243mo se juega
:i2 refid=aboutMain.Las reglas

: Bien, supongo que ha le\237do :link reftype=hd res=2100.Acerca de PM-Equator :elink.
y conoce la idea del juego: descubrir los d\237gitos en algunos c\225lculos. Si a\243n est\225
confundido, eche un vistazo a :link reftype=hd res=7777.No tengo ninguna idea:elink..

: Recuerde que hay dos modos diferentes de jugar a este juego (vea
:link reftype=hd res=2220.Modo dif\237cil :elink.), pero lo
principal que querr\225 saber se responde aqu\237:

: :hp3. C\243mo puedo introducir el d\237gito para un s\237mbolo? :ehp3.

: Hay dos m\233todos diferentes para hacerlo: puede hacerlo mediante un di\225logo especial de
d\237gitos o mediante una especie de "arrastrar y soltar" (drag and drop) simulado.

: :hp1.El di\225logo de n\243meros:ehp1.
:p. Haga doble clic con el bot\243n izquierdo del rat\243n sobre un s\237mbolo de d\237gito del acertijo.
Aparecer\225 un cuadro de di\225logo donde podr\225 introducir su conjetura para el valor de este s\237mbolo.

: :hp1.Arrastrar y soltar:ehp1.
:p. Puede arrastrar un d\237gito desde la matriz de d\237gitos al acertijo, o un s\237mbolo
desde el acertijo a la matriz de d\237gitos: haga clic una vez sobre lo que quiera arrastrar.
Observe c\243mo cambia el cursor del rat\243n. Mu\233valo hasta donde quiera soltarlo y haga
clic de nuevo con el bot\243n izquierdo del rat\243n.

:note. Cuando quiera que haga clic en la matriz de d\237gitos obtendr\225 un d\237gito (incluso si hace clic
sobre un s\237mbolo), y cuando haga clic en el acertijo obtendr\225 un s\237mbolo (incluso si hace clic
sobre un d\237gito).

:p. Para detener este arrastrar y soltar, pulse una vez el bot\243n derecho del rat\243n.

:p.
:note. Tambi\233n puede echar un vistazo a
:link reftype=hd res=2220.Nivel:elink., sobre el ajuste de niveles,
y a :link reftype=hd res=4000.Puntuaci\243n:elink., para al m\225ximo
su rendimiento.

:h1 res=7770.Los acertijos
:i2 refid=aboutMain.Los acertijos

: Los acertijos generados por este programa tienen las siguientes
caracter\237sticas:
.br
:sbul. Hay al menos una operaci\243n de punto (multiplicaci\243n o divisi\243n) y al menos
una suma/resta.
.br
:sbul. Todos los n\243meros son positivos.
.ve
:sbul. Cada d\237gito del 0 al 9 aparece al menos una vez.

:note. La soluci\243n de algunos de los acertijos m\225s f\225ciles puede ser :hp2. no \250nica :ehp2..
En ese caso, su tarea consiste en reconstruir el acertijo generado por el programa. Esto
introduce un poco de suerte en el juego, pero desaparece en los niveles m\225s altos.


:h1 res=7770.Pantalla principal
:i2 refid=aboutMain.Pantalla principal
La pantalla principal del programa se ve as\237
:p.
:artwork name='help\pmwin.bmp'.
:p.
:p.y est\225 dividida en tres partes mediante l\237neas horizontales.
:p.:hp1.Encima de la l\237nea superior:ehp1. se muestra el acertijo o su soluci\243n.

:p.:hp1.Debajo de la l\237nea inferior:ehp1. puede ver su puntuaci\243n y el tiempo restante.

:p.En la :hp1.parte central:ehp1. puede ver qu\233 d\237gitos ya ha descifrado y cu\225les
a\243n quedan por adivinar.

:note. Las :hp1.dos partes superiores:ehp1. de la ventana reaccionan a ciertas acciones del rat\243n!
(vea :link reftype=hd res=2000.C\243mo se juega :elink.)


:h1 res=7777. No tengo ninguna idea
:i2 refid=aboutMain sortkey='zzz'.No tengo ninguna idea

: Si nunca se ha encontrado con :ph2. Equators :ph1. todav\237a, echemos un vistazo a algunos
ejemplos. Cada s\237mbolo

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
o
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
simboliza un d\237gito.


As\237 pues, si observa este c\225lculo:
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
Puede concluir de inmediato
:artwork name='help\al1.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\nr1.bmp' runin.
ya que la suma de dos n\243meros de 3 d\237gitos debe tener un 0 o un 1 como cuarto d\237gito, y
el cero nunca se escribe a la izquierda de un n\243mero (como ocurre con cualquier n\243mero).
Adem\225s, se debe cumplir
:artwork name='help\al0.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\nr0.bmp' runin.
porque 
.br
:artwork name='help\al0.bmp' runin.
:artwork name='help\plus.bmp' runin.
:artwork name='help\al3.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\al3.bmp' runin.
debe cumplirse.

:p.
Un poco m\225s dif\237cil de ver es
:artwork name='help\al9.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\nr9.bmp' runin.
y finalmente
:artwork name='help\al8.bmp' runin.
:artwork name='help\gleich.bmp' runin.
:artwork name='help\nr8.bmp' runin.
pero es cierto! Y podemos concluir finalmente
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
:p. que se ve un poco menos cr\237ptico que el punto de partida.

Con dicha deducci\243n y algunas pruebas se pueden resolver todos los :hp2. Equators :ehp2.
generados por este programa. \161Buena suerte!

:note. Lo anterior es un ejemplo muy sencillo, s\243lo para que se haga una idea;
normalmente no se puede concluir tanto a partir de una \250nica operaci\243n.

Para obtener m\225s pistas iniciales, puede echar un vistazo a las 
:link reftype=hd res=2213.Soluciones:elink.
de algunos acertijos 


.*--------------------------------------------------------------*\
.*  Game menu                                                   *
:h1 res=2200. El men\250 Equator
:i1 id=Game sortkey='zzzzzzz'.Men\250 Equator
:p.El men\250 Equator contiene los comandos que usa para elegir el
nivel al que jugar y para salir de la aplicaci\243n.
Los siguientes comandos aparecen en el men\250 Equator:
:parml tsize=15 break=all.
:pt.Nivel
:pd.Aparece un cuadro de di\225logo en el que se pueden introducir dos niveles: uno como l\237mite
inferior y otro como l\237mite superior. Los niveles admitidos van del 1 al 50.
:pt.Nuevo
:pd.Se genera un nuevo acertijo al azar.
:pt.Soluci\243n
:pd.Muestra la soluci\243n del acertijo mostrado.
:pt.Puntuaciones altas
:pd.Muestra las puntuaciones m\225s altas.
:pt.Nivel
:pd.Cambie el ajuste de nivel (vea :link reftype=hd res=2220.Nivel :elink.).
:pt.Modo dif\237cil
:pd.Cambia al :link reftype=hd res=2223.Modo dif\237cil :elink.
:pt.Alfa
:pd.Cambia entre el modo Alfa y el conjunto de s\237mbolos para los d\237gitos codificados.
:pt.Erizo
:pd.Activa o desactiva el cursor especial del rat\243n.
:pt.Salir
:pd.Bueno, a veces uno tiene que dejar de jugar y ponerse a trabajar.
:eparml.

.*--------------------------------------------------------------*\
.*  Game menu Choose Level command help panel                   *
:h1 res=2220. Nivel
:i2 refid=Game.Nivel
:p. Aparece un cuadro de di\225logo donde puede introducir los dos niveles
deseados. Los niveles admitidos van del 1 al 50. El nivel superior debe
ser :hp1. mayor :eph1. que el inferior!

:note. Hay otra forma de hacer el juego m\225s f\225cil o m\225s dif\237cil:
vea :link reftype=hd res=2223.Modo dif\237cil :elink.

El ajuste del nivel se guarda en el archivo :hp2. .ini :ehp2. .

\161Vamos! Practique y aumente el nivel de vez
en cuando. Ver\225 c\243mo su puntuaci\243n mejora con el tiempo.

:note. Fijar un nuevo nivel genera inmediatamente un nuevo acertijo,
proceso que puede llevar unos segundos en una m\225quina lenta (
cf. :link reftype=hd res=2210.Nuevo :elink.)

.*--------------------------------------------------------------*\
.*  Game menu Next Level command help panel                     *
:h1 res=2210. Nuevo
:i2 refid=Game.Nuevo
:p.Con la opci\243n de men\250 :hp1.Juego-Nuevo:ehp1. se genera un nuevo :hp2. Equator:ehp2..

:note. Esto puede llevar unos segundos en un ordenador lento, ya que el
programa genera muchos acertijos y los descarta si no
se ajustan a ciertos criterios (:hp1. principalmente su ajuste de nivel:ehp1.; generar
problemas muy f\225ciles o muy dif\237ciles puede llevar tiempo).

:h1 res=2213. Soluci\243n
:i2 refid=Game.Soluci\243n
:p. Con la opci\243n de men\250 :hp1. Equator-Soluci\243n:ehp1. se muestra la soluci\243n del acertijo.

:note. Si no sabe c\243mo aprender :hp2. Equator:ehp2., puede generar
algunos acertijos con :link reftype=hd res=2210.Nuevo:elink. y mirar
las soluciones.

:h1 res=2216.Puntuaciones altas
:i2 refid=Game.Puntuaciones altas
:p. Puede ver las puntuaciones altas seleccionando esta opci\243n.

:note. Se guardan tres tipos de puntuaciones altas: las 4 puntuaciones m\225s altas del
modo dif\237cil, las 4 m\225s altas del modo f\225cil y las 2 soluciones m\225s r\225pidas del modo f\225cil.

:note. Las puntuaciones altas se guardan en el archivo .ini del programa, todas excepto la \250ltima
de cada tipo. Esto le permite comprobar su rendimiento cada
vez que juega.

:h1 res=2226.Alfa
:i2 refid=Game.Alfa
:p. Puede alternar entre dos conjuntos de s\237mbolos distintos con esta
opci\243n de men\250 con marca de verificaci\243n.

:note. Si juega en :link reftype=hd res=2223.Modo dif\237cil:elink.,
s\243lo puede jugar en modo alfa. Los cursores de arrastrar y soltar 
(vea :link reftype=hd res=2000.C\243mo se juega:elink.) s\243lo corresponden a los
s\237mbolos del modo alfa.

:h1 res2227.Cursor erizo
:i2 refid=Game.Cursor del erizo
:p. :ph2. Equator :ehp2. incluye un cursor de rat\243n especial; si no
le gusta, puede desactivarlo aqu\237. Por cierto, la nariz es el :ph1. punto
caliente:hp2., pero resulta un poco confuso...

.*--------------------------------------------------------------*\
.*  Game menu Hardmode                                         *
.*--------------------------------------------------------------*/
:h1 res=2223.Modo dif\237cil
:i2 refid=Hardmode.Modo dif\237cil

:p. Al hacer clic en esta opci\243n de men\250 se activa o desactiva la marca del 
:ph1. modo dif\237cil :ehp1.. \161No recomiendo el modo dif\237cil para principiantes!

:p. Hay dos formas diferentes de jugar a :ph2. Equator :ehp2..

:p. En el :ph1.modo f\225cil:ehp1. su entrada se comprueba cada vez que introduce
un d\237gito. Si acierta, perfecto; si se equivoca, sufre una
penalizaci\243n (vea: :link reftype=hd res=4000.Puntuaci\243n:elink.).

:p. En el :ph1.modo dif\237cil:ehp1 puede introducir todos los d\237gitos. El programa
s\243lo comprueba la correcci\243n de su teor\237a cuando introduce el :ph2. \250ltimo d\237gito
:ehp2.. Esto es, naturalmente, mucho m\225s dif\237cil.

:note. Hay otra forma de hacer el juego m\225s f\225cil o m\225s dif\237cil:
vea :link reftype=hd res=2220.Nivel :elink.

El ajuste del modo dif\237cil se guarda en el archivo :hp2. .ini :ehp2. .

P\243ngase a prueba: juegue al modo dif\237cil.

:note. Alternar el modo dif\237cil genera inmediatamente un nuevo acertijo,
proceso que puede llevar unos segundos en una m\225quina lenta (
cf. :link reftype=hd res=2210.Nuevo :elink.)


.*--------------------------------------------------------------*\
.*  Game menu Exit command help panel                           *
:h1 res=2230 PANEL_Exit.Salir
:i2 refid=Game.Salir
:p. A veces llega el momento de ponerse a trabajar de nuevo, as\237 que use este
comando, si as\237 lo desea:

:p. Saldr\225 de la aplicaci\243n mediante el comando Salir. Para
salir de la aplicaci\243n Equator, haga lo siguiente:

:p. Seleccione el men\250 Juego y elija el comando Salir.

.*--------------------------------------------------------------*\
.*  Main Help menu                                              *
:h1 res=2910. Men\250 Ayuda
:p.\161Aqu\237 obtendr\225 ayuda!

.*--------------------------------------------------------------*\
.*  Help menu Save As command help panel                        *
:h1 res=2920. \205ndice
:p.Coloque aqu\237 la informaci\243n para la opci\243n de men\250 \205ndice de la ayuda.

.*--------------------------------------------------------------*\
.*  Help menu General help help panel                           *
.*      res = PANEL_HELPGENERAL                                 *
.*--------------------------------------------------------------*/
:h1 res=2930. Ayuda general
:p.Coloque aqu\237 la informaci\243n para la opci\243n de men\250 Ayuda general.
:note.Normalmente, esta pantalla la muestra el sistema por defecto.

.*--------------------------------------------------------------*\
.*  Help menu Using help help panel                             *
:h1 res=2940. Uso de la ayuda
:p. \191Qu\233 puedo decir?

:p. \161Es la ayuda para usar la ayuda!


.*--------------------------------------------------------------*\
.*  Help menu Product information help panel                    *
:h1 res=2970.Informaci\243n del producto
:p.PM :ph2. Equator:ehp2. fue escrito por Frank Sven Nestel
:p.(:hp1. nestel@am.uni-erlangen.de :ehp1.).

:p.\161Le rogamos que eche un vistazo a la informaci\243n del producto!

:p.\161Si le gusta este programa, no dude en registrarlo!

.*--------------------------------------------------------------*\
.*  Help for Product information                                *
:h1 res=3100.Cuadro de informaci\243n del producto
:p.Este cuadro muestra informaci\243n sobre la aplicaci\243n, como el
    n\250mero de versi\243n y el aviso de copyright.

:p. ;-)


.*--------------------------------------------------------------*\
.*  About Box Dialog Ok button                                  *
:h1 res=3110.Continuar
:p.El bot\243n Continuar cierra el cuadro de informaci\243n del producto.

.*--------------------------------------------------------------*\
:h1 res=4000.Puntuaci\243n
:i1 id=Scoring.Puntuaci\243n
:p. Bien, la puntuaci\243n es un poco complicada. Hay dos esquemas de
puntuaci\243n distintos. Uno para el :link reftype=hd res=7002.Modo f\225cil:elink..
y otro para el :link reftype=hd res=2223.Modo dif\237cil:elink..

:h2 res=7002.Modo f\225cil
:i2 refid=Scoring.Modo f\225cil
:p. Al principio recibe una puntuaci\243n base y algo de :hp1.tiempo libre :ehp1.
Cuanto m\225s alto es el nivel (vea :link reftype=hd res=2220.Nivel:elink.),
mayor es la puntuaci\243n base que recibe. Mientras est\225 dentro de su tiempo libre, su
puntuaci\243n aumenta lentamente; si se le acaba el tiempo libre, su puntuaci\243n disminuye. Esta
disminuci\243n est\225 ligeramente ligada al n\250mero de d\237gitos que ya ha identificado.
Cada vez que identifica un d\237gito recibe nuevo tiempo libre. Cuando comete un error
al identificar un d\237gito sufre una penalizaci\243n y pierde algo de tiempo libre. Esta 
penalizaci\243n aumenta con cada error, as\237 que vaya con cuidado.

:p. Puede ver su puntuaci\243n, errores, tiempo y tiempo libre en la parte inferior de
la ventana.

:note. Hay dos modos distintos, pero tres puntuaciones altas; vea
:link reftype=hd res=2216.Puntuaciones altas:elink.

:p. Hay un m\233todo de puntuaci\243n diferente para el
:link reftype=hd res=7001.Modo dif\237cil:elink.

:h2 res=7001.Modo dif\237cil
:i2 refid=Scoring.Modo dif\237cil
:p.El modo dif\237cil es m\225s simple que el :link reftype=hd res=7002.Modo f\225cil:elink..
Como no hay conjeturas intermedias de d\237gitos
(si acierta al final, perfecto; si no, est\225 completamente perdido), sufre
una penalizaci\243n constante en tiempo. Aunque empieza con una mayor cantidad de tiempo libre, no
recibe tiempo libre nuevo durante la partida, de modo que la puntuaci\243n depende sobre todo del tiempo.

:p. Puede ver su puntuaci\243n, errores, tiempo y tiempo libre en la parte inferior de
la ventana.

:note. Hay dos modos distintos, pero tres puntuaciones altas; vea
:link reftype=hd res=2216.Puntuaciones altas:elink.


:h1 res=9990.. Algo m\225s de publicidad
:i1 id=ads sortkey='zzzz'.Algo m\225s de publicidad

:p. Quiz\225 haya reconocido un erizo de vez en cuando
en este programa. 
.br 
:artwork name='help\igel3.bmp' runin.
.br 
es el logotipo de una peque\241a empresa de juegos del sur de Alemania:
.br
Nos llamamos Doris &amp. Frank o, m\225s brevemente, D&amp.F, y ya hemos publicado
algunos juegos de :hp2. tablero:ehp2. hasta ahora; este programa es el primer intento de Frank de producir
algo de shareware.

Si le interesan los :hp1. juegos de tablero :ehp1. (sobre todo los peque\241os),
eche un vistazo a las p\225ginas WWW de Ken Tidwell o a las m\237as&colon.
.br
:hp1. http&colon.//www.kaleida.com/u/tidwell/GameCabinet.html :ehp1.
.br
all\237 encontrar\225 informaci\243n muy, muy buena, y nos encontrar\225
a nosotros entre los editores.

:p.
Tambi\233n puede escribir una carta por correo postal a:
:p.
Doris &amp. Frank
.br 
Obere Bach 24
.br 
D-91054 Buckenhof
.br 
Alemania
:p.
\161Gracias!


:h1 res=9990.. Registrar?
:i1 id=reg sortkey='zzzz'.Registro

:p. Si tiene la amabilidad de querer registrar este programa, por favor
env\237eme un eurocheque con 10 DM (es la \250nica manera de cobrarlo
sin comisiones de 30 DM) a
:p.
Frank Sven Nestel
.br 
Obere Bach 24
.br 
D-91054 Buckenhof
.br 
Alemania
:p.
Si quiere pagar de otra manera (p. ej., si es de
Alemania), preg\250nteme antes:
.br
:hp1. nestel@am.uni-erlangen.de:ehp1.

:note. Todav\237a no puedo ofrecerle garant\237as de actualizaciones, documentaci\243n impresa
ni otros programas m\237os por ahora. Lo \250nico que puedo hacer es mantenerme en contacto con usted.
Si esto funciona, tengo muchas ideas para m\225s peque\241os programas como \233ste, y
quiz\225 alguno m\225s grande.

:p.
\161Gracias por todo!

:p.
:p. P.D.: Por favor, h\225ganme llegar todas las cr\237ticas y sugerencias
para mejorar este peque\241o programa. 

:euserdoc.