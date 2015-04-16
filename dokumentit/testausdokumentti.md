# Testausdokumentti

Testauksessa käytetään Catchia (https://github.com/philsquared/Catch). Catch mahdollistaa helpon tavan BDD-tyylin 
mukaiseen testaukseen (http://dannorth.net/introducing-bdd/).

Projektiin on lähestytty sillä tavalla, että jokaista metodia ja toiminnalisuutta kohden on kirjoitettu ensiksi testit,
jotka eivät mene läpi. Tämän jälkeen on koodattu mahdollisimman yksinkertainen toteutus, jolla testit menevät läpi.
Samaa toistetaan uudelleen ja uudelleen.

Tällä tavalla koodi on pyritty pitämään jatkuvasti ehjänä ja mahdollisimman helposti muutettavissa ilman pelkoa, että
jotain tärkeää menee rikki.

## Algoritmien testaus

TODO: Tähän itse algoritmien testauksesta, käytetyistä syötteistä ja algoritmien vertailuista

## Muuta

TODO: Tähän testien suorittamisesta komentorivillä <code>./test</code> sekä mahdollisten tagien käyttämisestä 
<code>./test [node]</code> tai <code>./test [graph]</code>
