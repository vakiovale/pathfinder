# Viikkoraportti 3-4 

Viikoilla 3-4 olen keskittynyt enimmäkseen tutkimaan A\*-algoritmin toiminnan yksityiskohtiin ja sen eri vaatimuksiin. Tärkeimpiä uusia asioita:

- toiminnallisuus lyhimpien reittien etäisyyksien arvioimiseen
- prioriteettijonon toteuttamista ja testausta
- solmujen lisätoiminnalisuudet

## Projektin edistyminen

Projekti etenee pienin askelein, mutta koodi on jatkuvasti tuntunut melko valmiilta. Isojenkin muutoksien tekeminen on testien ansiosta ollut helppoa, sillä testien avulla on nopeasti huomannut onko matkan varrella tullut rikottua mitään. Testaamisesta on muutenkin saanut nyt paremmin kiinni. Nyt projektissa on löytynyt sopiva työskentelytapa, jotta testaamisen ja koodaamisen vuorottelu etenee sopivan pienin askelein.

Nämä viikot ovat kuluneet A\*-algoritmin apufunktioiden suunnitteluun ja toteutukseen. Itse algoritmin toimintaa en ole päässyt vielä testaamaan, mutta onneksi se hetki tuntuu olevan koko ajan lähempänä.

Olen aloittanut myös algoritmissa tarvittavan prioriteettijonon toteuttamista. Toistaiseksi käytän apuna C++:n tarjoamia omia tietorakenteita, mutta olen valmiiksi piilottanut niiden toiminnalisuuden oman prioriteettijono-luokan sisään. Olen myös samalla kirjoittanut testejä, joilla olen aluksi testannut, että käytän C++:n omia tietorakenteita ja algoritmeja oikein.

## Ongelmat

Projektissa ei ole ollut suurempia ongelmia. Melko paljon aikaa menee suunnitteluun ja pohdiskeluun, jotta turhaa koodia ei tulisi kirjoitettua. Hieman on ollut vaikeuksia hahmottaa minkälaisia solmuja ja verkkoja tässä työssä kannattaisi käyttää, joita voisi hyödyntää mahdollisimman monilla eri polunetsintäalgoritmeilla. Esimerkiksi Primin ja Kruskalin toteutus tuntuu jotenkin hankalalta verkon kanssa, jota olen nyt käyttänyt. Lopullisen deadlinen lähestyessä päätinkin, että otan tavoitteeksi aluksi toteuttaa vain A\*-algoritmin ja Dijkstran.

## Mitä seuraavaksi?

Seuraavaksi jatkan ExtendedNode-luokan toteutusta, jota voin hyödyntää algoritmissa prioriteettijonossa. Luokan on tarkoitus tarjota apumuuttujia, joita erityisesti A\*-algoritmi tarvitsee.
