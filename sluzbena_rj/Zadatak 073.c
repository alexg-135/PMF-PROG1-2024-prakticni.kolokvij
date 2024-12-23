/*
    ------------------- ZADATAK 73 --------------------
    Napisite program koji ucitava prirodni broj n, a
    zatim niz od n realnih brojeva (tipa double).
    Program treba ispisati sve "stroge" lokalne ekstreme
    u tom nizu i njihove redne brojeve, po redoslijedu
    ucitavanja. Clan niza je "strogi" lokalni ekstrem
    ako je, ili strogo veci, ili strogo manji od susjednih
    clanova niza (oba susjeda moraju biti prisutna u nizu).
    Ako u nizu nema "strogih" lokalnih ekstrema, treba
    ispisati odgovarajucu poruku.
    Na primjer, za n = 10 i ucitani niz brojeva
            2, 4, 5, 3, 1, 0, 3, 3, 2, 3,
    strogi lokalni ekstremi su 5 (na mjestu 3), 0 (na
    mjestu 6) i 2 (na mjestu 9). Uocite da uzastopne
    clanove 3, na mjestima 7 i 8, ne brojimo kao strogi
    lokalni maksimum, jer su jednaki,
    tj. nemamo "strogi" ekstrem.
    Uputa: Dovoljno je pamtiti samo tri uzastopna clana.
*/

#include<stdio.h>

int main(void){
    /* ucitamo prirodan broj n (=> cijeli!) */
    int n;
    /* opcionalni ispis: */
    printf("Unesite prvo n pa zatim jos n clanova niza: ");
    scanf("%d", &n);

    /* varijabla bilo_ekstrema ce nam sluziti tome da
       znamo jesmo li nasli koji strogi lokalni ekstrem
       - pocetno ju stavimo na 0 - ako cemo naci neki
         strogi lokalni ekstrem, postaviti cemo ju na 1
       - tako na kraju programa, ako je njena vrijednost
         ostala 0, znamo da nije bilo tih ekstrema pa cemo
         ispisati odgovarajucu poruku */
    int bilo_ekstrema = 0;

    /* koristimo varijable prethodni, sljedeci, trenutni
       kako bi pamtili prethodni, sljedeci i trenutni
       clan niza za odredjivanje ekstrema - ideja je
       ilustrirana u komentaru na samom kraju!
       - kako su clanovi niza tipa double, onda su i ove
         varijable u koje spremamo neke od tih clanova
         takodjer tipa double */
    double prethodni, trenutni, sljedeci;

    /* ucitavamo n realnih brojeva */
    int i;
    for(i = 1; i <= n; ++i){
        /* uocite da sad i predstavlja koji je po redu
           broj kojeg ucitavamo (npr. kada je i jednak 5
           to upravo znaci da ucitavamo peti po redu broj)
           - ako je i == 1, ucitavamo prvi broj - on nije
             ekstrem (fali mu susjedni (preciznije prethodni
             clan u ucitanom nizu)), ali ga spremimo kao
             prethodni clan za ovog sljedeceg kojeg cemo
             ucitati */
        if(i == 1)
            scanf("%lf", &prethodni);
        else if(i == 2)
            /* ako ucitavamo drugi element po redu, on jos
               nema sljedeceg (ima samo prethodnog) pa ga
               spremimo kao trenutnog (kad ucitamo sljedeci
               element provjeriti cemo je li on ekstrem) */
            scanf("%lf", &trenutni);
        else {
            /* ucitavamo sljedeceg - on dolazi nakon
               prethodnog kojeg smo ranije ucitali */
            scanf("%lf", &sljedeci);
            /* provjerimo je li trenutni strogi ekstrem: */
            if((prethodni < trenutni && trenutni > sljedeci)
                || (prethodni > trenutni && trenutni < sljedeci)){
                /* ako je ekstrem, onda ispisemo njega i njegov
                   redni broj (a kako je i-ti ucitan sljedeci,
                   taj prethodni je imao broj i-1)
                   - ispis u novi red => \n */
                printf("%g (na mjestu %d)\n", trenutni, i - 1);
                bilo_ekstrema = 1; /* zabiljezili da nasli
                            neki strogi lokalni ekstrem */
            }
            /* za sljedeci koji cemo ucitati, moramo ove
               vrijednost pomaknuti - trenutni postaje
               prethodni, a trenutni postaje sljedeci
               (tocno tim redoslijedom postavljamo!!!!!!) */
             prethodni = trenutni;
             trenutni = sljedeci;
        }
    }

    /* ako nije bilo strogih lokalnih ekstrema, tada je
       varijabla bilo_eksrema ostala jednaka 0 pa ispisemo
       odgovarajucu poruku */
    if(bilo_ekstrema == 0)
        printf("Nije bilo lokalnih ekstrema.");

    return 0;
}


/* Ilustracija ideje (za ucitani n = 10; radi lakseg zapisa
   je trenutni oznacen s t, prethodni s p, a sljedeci sa s):

   p  t  s
   2, 4, 5, 3, 1, 0, 3, 3, 2, 3 (t nije lok. ekstr.)

      p  t  s  (vrijedi: p < t i t > s)
   2, 4, 5, 3, 1, 0, 3, 3, 2, 3 (t je lok. ekstr.)

         p  t  s
   2, 4, 5, 3, 1, 0, 3, 3, 2, 3 (t nije lok. ekstr.)

   itd.
*/
