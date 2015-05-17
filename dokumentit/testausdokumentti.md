# Testausdokumentti

Testauksessa käytetään Catchia (https://github.com/philsquared/Catch). Catch mahdollistaa helpon tavan BDD-tyylin 
mukaiseen testaukseen (http://dannorth.net/introducing-bdd/).

Projektiin on lähestytty sillä tavalla, että jokaista metodia ja toiminnalisuutta kohden on kirjoitettu ensiksi testit,
jotka eivät mene läpi. Tämän jälkeen on koodattu mahdollisimman yksinkertainen toteutus, jolla testit menevät läpi.
Samaa toistetaan uudelleen ja uudelleen.

Tällä tavalla koodi on pyritty pitämään jatkuvasti ehjänä ja mahdollisimman helposti muutettavissa ilman pelkoa, että
jotain tärkeää menee rikki.

## Catch

Projektin juurikansiosta lötyy skripti <code>test</code>, jonka avulla on mahdollista suorittaa kaikki kirjoitetut testit. Jokainen testi on merkattu omalla *tagilla*, joiden avulla eri ohjelman osa-alueita on helppo testata erikseen. Kaikki mahdolliset tagit saa näkyviin komennolla <code>./test --list-tags</code>. Suorittamalla <code>./test --help</code> komennon, näkee kaikki Catchin tarjoamat parametrit testien suorittamista varten. Hyödyllisimpiä ovat olleet <code>./test --success</code>, joka tulostaa tarkat tiedot myös onnistuneista testeistä, sekä esimerkiksi <code>./test [graph]</code>, joka suorittaa vain *graph*-tagilla varustetut testit. Testeistä saa näkyviin myös niiden suoritusajat, joiden avulla on helposti ja nopeasti pystynyt katsomaan kuinka muutokset koodissa ovat vaikuttaneet ohjelman suorituskykyyn.

## Algoritmien testaus

A*-algoritmin testaus on tehty testaamalla mahdollisimman täydellisesti jokainen erillinen osa ja funktio, jota algoritmi käyttää. Vasta viimeisimpänä kirjoitin testit, jotka tarkistivat onko haettu reitti oikeasti lyhin. Tälllä tavoin työskennellessä monimutkaisten kokonaisuuksien testaaminen osoittautui lopulta helpoksi, kun yksinkertaisimmat palikat oli ensiksi testattu riittävän kattavasti.

## Testaus graafisessa käyttöliittymässä

Pelkillä testeillä oli vaikea todeta algoritmin toimivan kunnolla ja sitä varten toteutin algoritmin lisäksi sitä käyttävän käyttöliittymän. Visuaalisessa ympäristössä oli näin ollen helpompi *nähdä* algoritmin toimivan halutulla tavalla. Onnekseni eteen ei toistaiseksi ole tullut tilanteita, joissa vasta graafisessa käyttöliittymässä olisin huomannut algoritmin toimivan väärin.

Graafinen käyttöliittymä on myös mahdollistanut testaamisen monimutkaisemmissa verkoissa, joissa on paljon esteitä ja eri painoja solmujen välillä, sillä tällaisten verkkojen kirjoittaminen suoraan koodiin olisi paljon vaivalloisempaa.
