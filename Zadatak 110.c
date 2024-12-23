// Zadatak 110 [zad_110]:

// Napisite program koji ucitava prirodne brojeve sve dok se ne ucita troznamenkasti broj. Program, za svaki ucitani broj
// (osim tog zadnjeg), treba ispisati sumu njegove prve i zadnje znamenke. Ako je prvi ucitani broj troznamenkast, onda treba
// ispisati poruku.

// Na primjer, za ulaz: 8234 2391 432957 5 234, program staje i ispisuje 12 3 11 10.

#include <stdio.h>

int duljina(int n)
{
    int i = 1;
    if(n == 0) return 1;
    for(i = 1;n > 0;i++) n /= 10;
    return i-1;
}

int powf(int a, int b)
{
    int pow=1;
    for(int i = 0;i<b;i++) pow *= a;
    return pow;
}

int main(void)
{
    int n, prvi = 1;

    while(1)
    {
        scanf("%d", &n);
        int duljina_n = duljina(n);

        if(duljina_n == 3 && prvi == 1)
        {
            printf("Unijeli ste prvo troznamenksati broj.");
            return 0;
        }

        if(duljina_n == 3) break;

        prvi = 0;
        printf("%d ", n/powf(10, duljina_n - 1) + n%10);
    }

    return 0;
}
