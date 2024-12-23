// ZADATAK 025

//Napisite program koji, jednu po jednu, ucitava znamenke binarnog broja, pocevsi od krajnje lijeve. Znamenke se ucitavaju
//kao brojevi, a ne kao znakovi. Ucitavanje prestaje kad se unese broj koji nije 0 ili 1. Program treba ispisati koji dekadski
//broj ima takav binarni zapis. Primjerice, ako je unos bio 1 0 0 1 1 2, program treba ispisati 19.

#include <stdio.h>

int powf(int a, int b)
{
    int pow = 1;
    for(int i = 0;i<b;i++) pow *= a;
    return pow;
}

int main(void)
{
    int broj_bin = 0, n;

    while(1)
    {
        scanf("%d", &n);

        if(n != 0 && n != 1) break;

        broj_bin = broj_bin*10 + n;
    }

    int sum = 0, i = 0;
    if(broj_bin == 0)
    {
        printf("0");
        return 0;
    }

    for(i = 0;broj_bin > 0; i++){
        sum += (broj_bin%10) * powf(2, i);
        broj_bin /= 10;
    }

    printf("%d", sum);

    return 0;
}
