// Zadatak 108 [zad_108]:

// Napisite program koji ucitava prirodne brojeve n i d, te pomocu zvjezdica “crta” ljestve: dvije okomite crte udaljene za 2d
// znakova, ispresijecane poprecnim linijama duljine 4d + 2. Poprecne linije se trebaju pojavljivati svakih d + 1 linija na ekranu
// i treba ih biti n. Na vrhu i na dnu trebaju str¡sati vertikalne linije duljine d.

// Primjer (brojeve linija NE treba ispisati): n = 3 i d = 2
// 1:   *    *
// 2:   *    *
// 3: **********
// 4:   *    *
// 5:   *    *
// 6: **********
// 7:   *    *
// 8:   *    *
// 9: **********
// 10:  *    *
// 11:  *    *

#include <stdio.h>

int main(void)
{
    int n, d;

    scanf("%d %d", &n, &d);

    for(int i = 0;i<n*d+n+d;i++)
    {
        if((i+1)%(d+1) == 0)
        {
            for(int j = 0;j<4*d+2;j++) printf("*");
        }
        else
        {
            for(int j = 0;j<(4*d - 2*d)/2;j++) printf(" ");
            printf("*");
            for(int j = 0;j<(2*d);j++) printf(" ");
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
