// Zadatak 105 [zad_105]:

// Napisite program koji ucitava prirodne brojeve n i d, te pomocu zvjezdica “crta” niz “praznih” kvadrata, cije stranice imaju
// duljine n, n − d, . . . , s tim da svaki kvadrat pocinje u novom retku.

// Primjer (brojeve linija NE treba ispisati): n = 5 i d = 2 (duljine stranica kvadrata su: 5, 3 i 1)
// 1: *****
// 2: *   *
// 3: *   *
// 4: *   *
// 5: *****
// 6: ***
// 7: * *
// 8: ***
// 9: *

#include <stdio.h>

int main(void)
{
    int n, d;
    scanf("%d %d", &n, &d);

    for(int i = n; i > 0;i-=d)
    {
        for(int j=0;j<i;j++)
        {
            if(j == 0 || j == i-1) for(int k = 0;k<i;k++) printf("*");
            else
            {
                printf("*");
                for(int k = 0;k<i-2;k++) printf(" ");
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}
