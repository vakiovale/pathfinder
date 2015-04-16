# Määrittelydokumentti

## Polunetsintä

Projektin tavoitteena on ratkaista lyhin polku pisteestä toiseen. Työ toteutetaan C++-kielellä. Pääpaino projektissa on toimivan A\*-polunetsintäalgoritmin sekä siihen liittyvien tietorakenteiden toteuttaminen.

## Algoritmit ja tietorakenteet

### A\*-algoritmi
Keskeinen osa työtä on toimiva polunetsintäalgoritmi. Valitsin toteutettavaksi algoritmiksi A\*-algoritmin, sillä siinä on mukavasti uusia haasteita ja sen toteutuksessa käytetään useita eri komponentteja ja tekniikoita. Algoritmi on suosittu ja siitä löytyy helposti tietoa verkosta.

### Muita algoritmeja
Vertailun vuoksi toteutan A\*-algoritmin lisäksi myös Dijkstran algoritmin vertailun vuoksi.

### Tietorakenteet
A\*-algoritmin toteutuksessa yhtenä tärkeimpänä tietotyyppinä tulen käyttämään prioriteettijonoa. Algoritmin toiminnan kannalta on tärkeää, että saatavilla on aina paras mahdollinen ehdokas seuraavaksi solmuksi lyhyimmän reitin etsinnässä. Tähän tarkoitukseen prioriteettijono on luonteva valinta. Prioriteettijono on tarkoitus toteuttaa keon avulla.

## Ohjelman toiminta

Algoritmit suunnitellaan toimimaan yksinkertaisessa 2x2-ruudukossa (grid map), jossa reittiä voi kulkea ylä- ja alasuunnassa, sivuttain sekä diagonaalisesti. Tavoitteena on, että projektin lopussa käyttäjällä olisi käytettävissään graafinen käyttöliittymä. Käyttöliittymässä voi hiirellä painaen valita kartasta alku- ja loppupisteet ja ohjelma etsii näiden välille lyhyimmän reitin. Karttaan tulisi voida myös laittaa esteitä, jotta polunetsintä olisi mielekkäämpää. Mikäli projekti lähtee hyvin etenemään, on tarkoitus saada nopeasti sellainen käyttöliittymä, jonka avulla on helppo visualisoida algoritmin toimintaa.

Käyttöliittymästä riippumatta algoritmien tulee toimia sillä tavalla, että ne saavat tiedon alku- ja loppupisteistä sekä tiedon käytössä olevasta verkosta. Näiden perusteella algoritmi palauttaa lyhyimmän reitin esimerkiksi listana, jossa on järjestyksessä lyhimmässä polussa olevat solmut.

## Lähteet

Työn toteutuksessa käytetään apuna ainakin seuraavia lähteitä:

[Introduction to A\*](http://theory.stanford.edu/~amitp/GameProgramming/AStarComparison.html)

[A\* Pathfinding for Beginner](http://www.policyalmanac.org/games/aStarTutorial.htm)
