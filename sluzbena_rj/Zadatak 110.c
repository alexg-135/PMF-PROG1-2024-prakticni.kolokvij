/*
    -------------------- ZADATAK 110 --------------------
    Napisite program koji ucitava prirodne brojeve sve dok
    se ne ucita troznamenkasti broj. Program, za svaki
    ucitani broj osim tog zadnjeg), treba ispisati sumu
    njegove prve i zadnje znamenke. Ako je prvi ucitani
    broj troznamenkast, onda treba ispisati poruku.
    Na primjer, za ulaz: 8234 2391 432957 5 234, program
    staje i ispisuje 12 3 11 10.
*/

#include<stdio.h>

int main(void){
    /* ucitani broj spremati cemo u varijablu broj */
    int broj;

    int kopija, prva; /* ove varijable trebamo kasnije */

    /* ponavljamo sljedeci postupak:
       - ucitamo sljedeci broj
       - izracunamo sumu
       - ako to nije troznamenkasti broj, ispisemo
         trazenu sumu i nastavljamo dalje
       - kako se gornje ponavlja na nacin da na kraju
         provjeravamo uvjet - koristimo do...while() */

    /* uocimo: ako je prvi uneseni broj bio troznamenkast
       onda necemo imati niti jednu sumu za ispisati
       - zato koristimo varijablu bilo_ispisa koja je
         pocetno stavljena na 0, a kada nesto ispisemo
         ju stavimo na 1 - tako na kraju, ako nije prvo
         unesen troznamenkasti broj, bilo je nekog ispisa
         pa je ta varijabla jednaka 1, a inace (ako je
         ostala jednaka 0) ispisemo poruku */
    int bilo_ispisa = 0;

    do {
        /* ucitamo sljedeci broj */
        scanf("%d", &broj);
        /* zadnju znamenku lako dobijemo kao: broj % 10
           - kako dobiti prvu znamenku:
           - najprije iskopiramo vrijednosti od broj u
             varijablu kopija (jer ce nam vrijednost
             od broj trebati kasnije pa da ju ne unistimo)
           - zatim redom dobivamo znamenke od kopija, od
             zadnje, kao kopija % 10 - uklonimo tu
             znamenku s kopija /= 10, pa ako jos ima
             znamenki (tj. ako kopija > 0) nastavljamo
             dalje: kopija % 10 daje zadnju od toga sto
             nam je ostalo itd.
           - uocimo da ta petlja zavrsi kad kopija == 0
             (tj. nije vise > 0), a u varijabli prva
             je ostala prva znamenka (npr. za 4235 bi
             redom uklanjali 5, 3, 2 i prije nego smo
             uklonili i prvu, tj. 4, ona je bila ostala
             kao zadnja koja je spremljena u prva */
        kopija = broj;
        while(kopija > 0){
            prva = kopija % 10;
            kopija /= 10;
        }
        /* ako broj nije bio troznamenkast treba ispisati
           sumu (i kasnije u while petlji nastaviti dalje)
           - kako znamo da prirodan broj (kakav je po
             pretpostavci ucitan) nije troznamenkast?
             - pa, za njega vrijedi < 100 ILI > 999 */
        if(broj < 100 || broj > 999) { /* nije troznam. */
            printf("%d\n", prva + broj % 10);
            /* gore smo ispisali sumu prve i zadnje
               znamenke unesenog netroznamenkastog broja
               broj (u novi red (\n)) */
            bilo_ispisa = 1;
        }
    } while(broj < 100 || broj > 999); /* dok je broj
                                          troznamenkast */

    /* ako nije bilo ispisa (tj. bilo_ispisa ostao 0)
       to je zato jer je prvo bio unesen troznamenkasti
       broj pa u tom slucaju ispisemo poruku */
    if(bilo_ispisa == 0)
        printf("Nema trazenih brojeva.");

    return 0;
}
