/*
    -------------------- ZADATAK 18 --------------------
    Napisite program koji ucitava prirodni broj n. Program
    treba ispisati sve prirodne brojeve m, strogo manje od n,
    za koje postoji multiplikativni inverz modulo n, tj.
    prirodni broj k < n, takav da vrijedi m * k = 1 mod n.
    Za svaki takav m, program treba ispisati i pripadni
    "inverz" k.
    Primjer: za n = 6, brojevi m iz {1,2,...,5} koji imaju
    inverz modulo 6 su 1 (inverz je 1) i 5 (inverz je 5),
    jer je 5 * 5 = 25 = 1 mod 6.
*/

#include<stdio.h>

int main(void){
    /* ucitamo prirodan broj n (=> cijeli!) */
    int n;
    printf("Unesite n: "); /* opcionalni ispis */
    scanf("%d", &n);

    /* provjeravamo sve prirodne brojeve (dakle => 1)
       koji su strogo manji od n (dakle, 1 <= m < n) */
    int m, k; /* trebamo ih kasnije */
    for(m = 1; m < n; ++m){
        /* provjeravamo postoji li neki prirodan broj
           k < n (dakle, 1 <= k < n), takav da vrijedi
           (m * k) % n == 1 (tj. m * k = 1 mod n) */

        for(k = 1; k < n; ++k){
            if((m * k) % n == 1){
                /* ako nasli ,,inverz'' ispisemo m i
                   njegov pripani inverz (pa '\n' kako
                   bi sljedeci ispis bio u novi redak) */
                printf("%d %d\n", m, k);
            }
        }
    }

    return 0;
}
