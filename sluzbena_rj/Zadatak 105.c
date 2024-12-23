/*
    -------------------- ZADATAK 105 --------------------
    Napisite program koji ucitava prirodne brojeve n i d,
    te pomocu zvjezdica "crta" niz "praznih" kvadrata,
    cije stranice imaju duljine n, n - d, ... , s tim da
    svaki kvadrat pocinje u novom retku.
    Primjer (brojeve linija NE treba ispisati):
    n = 5 i d = 2 (duljine stranica kvadrata su: 5, 3 i 1)

    1: *****
    2: *   *
    3: *   *
    4: *   *
    5: *****
    6: ***
    7: * *
    8: ***
    9: *
*/

#include<stdio.h>

int main(void){
    /* ucitamo prirodne brojeve n i d (=> cijeli!) */
    int n, d;
    printf("Unesite n: "); /* opcionalni ispis */
    scanf("%d", &n);
    printf("Unesite d: "); /* opcionalni ispis */
    scanf("%d", &d);

    int i, j; /* ove varijable trebamo kasnije */

    /* prvo crtamo kvadrat cija je stranica duljine
       n, zatim kvadrat cija je stranica duljine
       n - d, pa (n - d) - d, itd. Kako bismo znali
       koliko je duga stranica kvadrata kojeg trenutno
       crtamo, tu duljinu spremimo u varijabli duljina */
    int duljina;

    /* Dakle, duljina je pocetno n, a svaki puta se
       smanji za d (tj. duljina -= d), jer duljina
       stranice kvadrata kojeg sljedeceg crtamo je
       za d manja od duljine stranice prethodnog kvadrata
       - uocimo da crtamo kvadrate sve dok je duljina
         stranice >= 1, jer ne crtamo kvadrate duljine
         stranice 0 ili negativne duljine! */
    for(duljina = n; duljina >= 1; duljina -= d){
        /* za kvadrat sa stranicom duljina treba nacrtati
           ukupno duljina redaka - varijabla i ce biti
           koji redak po redu crtamo (prvi, drugi, itd.
           sve dok ne nacrtamo (duljina)-ti redak) */
        for(i = 1; i <= duljina; ++i){
            /* u svakom od tih redaka je tocno duljina
               znakova (pri cemu je svaki od tih znakova
               ili zvjezdica (*) ili praznina ( ))
               - koji znak po redu u tom retku crtamo ce
                 biti pamcen u varijabli j (prvi, drugi,
                 itd. sve do (duljina)-tog znaka) */
            for(j = 1; j <= duljina; ++j){
                /* uocimo u ispisu da su u svakom retku
                   prvi i zadnji znak obavezno * - kako
                   u j imamo koji po redu u tom retku
                   crtamo znak, onda za j == 1 (prvi!) ili
                   j == duljina (zadnji u retku!) znak
                   ispisemo * */
                if(j == 1 || j == duljina)
                    printf("*");
                else {
                    /* ostali znakovi (za j = 2, 3, itd. sve
                       do predzadnjeg, tj. (duljina - 1)-tog)
                       su ili * ili praznina - no, to ovisi
                       jesmo li u prvom ili zadnjem retku
                       (tj. ako i == 1 (prvi redak!) ili
                       i == duljina (zadnji redak kvadrata!)
                       onda ispisujemo *), ili nismo
                       (ako nismo ni u prvom ni u zadnjem
                       ispisujemo razmake) */
                    if(i == 1 || i == duljina)
                        printf("*");
                    else
                        printf(" ");
                }
            } /* ova zagrada } je kraj for petlje po j, tj.
                 tu smo zavrsili s ispisom jednog retka
                 kvadrata pa kako bismo presli u novi redak
                 ispisemo '\n' */
            printf("\n");
        }
    }

    return 0;
}
