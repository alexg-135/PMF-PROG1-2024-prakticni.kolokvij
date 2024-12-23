/*
    --------------- ZADATAK 108 ---------------

    Napisite program koji ucitava prirodne brojeve n i d,
    te pomocu zvjezdica "crta" ljestve: dvije okomite crte
    udaljene za 2d znakova, ispresijecane poprecnim linijama
    duljine 4d + 2. Poprecne linije se trebaju pojavljivati
    svakih d linija na ekranu i treba ih biti n.
    Na vrhu i na dnu trebaju strsati vertikalne linije duljine d.
    Primjer (brojeve linija NE treba ispisati): n = 3 i d = 2
        1:    *   *
        2:    *   *
        3:  **********
        4:    *   *
        5:    *   *
        6:  **********
        7:    *   *
        8:    *   *
        9:  **********
        10:   *   *
        11:   *   *
*/

#include<stdio.h>

int main(void){
    /* ucitamo prirodne brojeve n i d (=> cijeli!) */
    int n, d;
    printf("Unesite n: "); /* opcionalan ispis */
    scanf("%d", &n);
    printf("Unesite d: "); /* opcionalan ispis */
    scanf("%d", &d);

    int i, j, k; /* pomocne varijable potrebne u nastavku */

    /* radimo ovako: prvo ispis d linija do prve poprecne */
    for(j = 1; j <= d; ++j){
        /* ispred prve * je d razmaka, zatim *, pa onda
           2d razmaka, zatim druga * i idemo u novu liniju
           (jer smo u ovoj iscrtali obje * koje trebamo */
        for(k = 1; k <= d; ++k)
            printf(" ");
        printf("*"); /* prva zvjezdica */
        for(k = 1; k <= 2 * d; ++k)
            printf(" ");
        printf("*\n"); /* druga zvjezdica i idemo u novi red */
    }

    /* ponavljamo n puta: crtaj poprecnu, pa opet gornji kod */
    for(i = 1; i <= n; ++i){
      /* nacrtamo poprecnu liniju duljine 4d+2 */
        for(k = 1; k <= 4 * d + 2; ++k)
            printf("*");
        printf("\n"); /* prelazimo u novi red, te ponovimo
           gornji kod: */
            for(j = 1; j <= d; ++j){
                for(k = 1; k <= d; ++k)
                    printf(" ");
                printf("*"); /* prva zvjezdica */
                for(k = 1; k <= 2 * d; ++k)
                    printf(" ");
                printf("*\n"); /* druga zvjezdica i idemo u novi red */
            }
    }



    return 0;
}
