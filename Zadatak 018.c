// Zadatak 18 [zad_018]:

// Napisite program koji ucitava prirodni broj n. Program treba ispisati sve prirodne brojeve m, strogo manje od n, za koje
// postoji multiplikativni inverz modulo n, tj. prirodni broj k < n, takav da vrijedi
// m · k = 1 mod n.
// Za svaki takav m, program treba ispisati i pripadni “inverz” k.
// Primjer: za n = 6, brojevi m element {1,... , 5} koji imaju inverz modulo 6 su 1 (inverz je 1) i 5 (inverz je 5), jer je 5 · 5 = 25 =
// 1 mod 6.

#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int m = 1; m<n; m++)
    {
        int postoji = 0;
        for(int k = 1;k<n;k++) if ((1 - m*k) % n == 0) postoji = 1;

        if(postoji == 1) printf("%d ", m);
    }

    return 0;
}
