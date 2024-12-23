// Zadatak 73 [zad_073]:

// Napisite program koji ucitava prirodni broj n, a zatim niz od n realnih brojeva (tipa double). Program treba ispisati sve
// “stroge” lokalne ekstreme u tom nizu i njihove redne brojeve, po redoslijedu ucitavanja. Clan niza je “strogi” lokalni ekstrem
// ako je, ili strogo veci, ili strogo manji od susjednih clanova niza (oba susjeda moraju biti prisutna u nizu). Ako u nizu nema
// “strogih” lokalnih ekstrema, treba ispisati odgovarajucu poruku.
// Na primjer, za n = 10 i ucitani niz brojeva 2, 4, 5, 3, 1, 0, 3, 3, 2, 3, strogi lokalni ekstremi su 5 (na mjestu 3), 0 (na mjestu 6)
// i 2 (na mjestu 9). Uocite da uzastopne clanove 3, na mjestima 7 i 8, ne brojimo kao strogi lokalni maksimum, jer su jednaki,
// tj. nemamo “strogi” ekstrem.

// Uputa: Dovoljno je pamtiti samo tri uzastopna clana.

#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int prvi = 2;
    int n3, n2, n1, ima = 0;
    for(int i = 0;i<n;i++)
    {
        scanf("%d", &n1);
        if(prvi > 0)
        {
            n3 = n2;
            n2 = n1;
            prvi--;
            continue;
        }

        if(n2 > n3 && n2 > n1)
        {
            printf("%d ", n2);
            ima = 1;
        }
        else if(n2 < n3 && n2 < n1)
        {
            printf("%d ", n2);
            ima = 1;
        }

        n3 = n2;
        n2 = n1;
    }

    if(ima == 0) printf("Nema takvih brojeva u nizu.");

    return 0;
}
