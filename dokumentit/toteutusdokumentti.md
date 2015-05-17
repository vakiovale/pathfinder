# Totetusdokumentti

Ohjelma tarjoaa välineet, joilla voidaan ratkaista helposti ja nopeasti lyhin polku kahden pisteen välissä, 
kun käytössä on 2-uloitteinen taulukko (esim. shakki-lauta).

Ohjelma koostuu kahdesta eri osasta:

* **libPathFinder**-kirjasto
* **PathFinder demo** – graafinen käyttöliittymä

## PathFinder-kirjasto

PathFinder-kirjasto koostuu useista eri luokista, joista tärkein on AStarPathFinder-luokka, jonka tehtävänä on etsiä verkon kahden solmun välillä lyhin polku. Kirjasto pitää sisällään myös apuluokat solmuille sekä verkoille. Kirjastoa
on mahdollisuus käyttää myös ilman A\*-algoritmia, mutta sen verkot ja solmut on tarkoituksenmukaisesti luotu sopimaan juuri A*-algoritmin käytön kanssa.

Kirjasto voidaan asentaa <code>./install</code> komennolla, joka kopioi tarvittavat tiedostot <code>libPathFinder/</code>-hakemistoon.

## Graafinen käyttöliittymä

Graafinen käyttöliittymä on erillinen ohjelma, joka käyttää SFML-kirjastoa. Demo käyttää PathFinder-kirjastoa visualisoimaan polunetsintää A*-algoritmin kanssa.

Polunetsintä onnistuu myös liikkuvan kohteen kanssa. Graafisessa käyttöliittymässä on mahdollisuus laittaa lähtöpiste kulkemaan lyhintä polkua pitkin kohti maalia. Myös pisteen liikkumisnopeutta pystyy säätämään. Algoritmi etsii jatkuvasti lyhintä polkua, joten ohjelmassa on helppo seurata, kuinka polku muuttuu, kun päätepistettä liikutetaan.

## Suorituskyky

Suorituskykyä testattiin useissa erilaisissa verkoissa:

<img src="https://github.com/valtteripyyhtia/pathfinder/blob/master/dokumentit/images/pathfinding35.png?raw=true" width="200px" />

Aluksi testasin kuinka verkon koko vaikuttaa suorituskykyyn, kun reitti on verkon kulmasta kulmaan. Verkon koko vaihteli 1x1-koosta -> 100x100. Suuremmillakin verkoilla suoritus onnistui, mutta suoritusajat kasvoivat omalla koneellani suuriksi.

<img src="https://github.com/valtteripyyhtia/pathfinder/blob/master/dokumentit/images/kaavio.png?raw=true" width="800px" />

Keskiarvosuoritusaikoja erilaisissa verkoissa (suorituksia noin 20 jokaista testitilannetta varten):

Tilanne   | A*-algoritmin suoritusaika (mikrosekunti)
------| -----------------
<img src="https://github.com/valtteripyyhtia/pathfinder/blob/master/dokumentit/images/pathfinding35.png?raw=true" width="200px" /> | 22388
<img src="https://github.com/valtteripyyhtia/pathfinder/blob/master/dokumentit/images/pathfindingtunnel.png?raw=true" width="200px" /> | 27066
<img src="https://github.com/valtteripyyhtia/pathfinder/blob/master/dokumentit/images/pathfindingrandom.png?raw=true" width="200px" /> | 28956
<img src="https://github.com/valtteripyyhtia/pathfinder/blob/master/dokumentit/images/pathfindinglabyrinth.png?raw=true" width="200px" /> | 30831
<img src="https://github.com/valtteripyyhtia/pathfinder/blob/master/dokumentit/images/pathfindingwatergrasstrap.png?raw=true" width="200px" /> | 42490
<img src="https://github.com/valtteripyyhtia/pathfinder/blob/master/dokumentit/images/pathfindingtrap.png?raw=true" width="200px" /> | 48465

## Puutteet ja parannusehdotukset

Jotta tuloksilla tekisi jotain, olisi hyödyllistä, jos A*-algoritmia verrattaisiin muihin polunetsintäalgoritmeihin. Graafinen käyttölittymä mahdollistaa onneksi helpon tavan vaihtaa algoritmia "lennosta", joten algoritmien vertailu samassa ympäristössä olisi helppoa. Hyvänä lisänä voisi olla myös lisätä useampi lähtöpiste, jotka voisivat käyttää eri algoritmeja ja näin nähdä reaaliajassa kumpi algoritemista löytää reitin nopeammin.

## Erityishuomio

Algoritmi suoriutui myös Tiralabrasta ennätysnopeasti:

<img src="https://github.com/valtteripyyhtia/pathfinder/blob/master/dokumentit/images/pathfindingtiralab.png?raw=true" width="400px" />
