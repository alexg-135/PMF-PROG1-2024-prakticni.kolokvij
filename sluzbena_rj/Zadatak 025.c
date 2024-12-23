/*
    -------------------- ZADATAK 25 --------------------
    Napisite program koji, jednu po jednu, ucitava znamenke
    binarnog broja, pocevsi od krajnje lijeve. Znamenke se
    ucitavaju kao brojevi, a ne kao znakovi. Ucitavanje
    prestaje kad se unese broj koji nije 0 ili 1. Program
    treba ispisati koji dekadski broj ima takav binarni
    zapis. Primjerice, ako je unos bio 1 0 0 1 1 2, program
    treba ispisati 19.
*/

#include<stdio.h>

int main(void){
    /* koristimo Hornerov algoritam:
       - npr. (1 0 0 1 1)
           = (((1 * 2 + 0) * 2 + 0) * 2 + 1) * 2 + 1
       - ukratko, algoritam je: pocnemo od broja 0,
         te svaki put kad korisnik unese novu znamenku,
         pomnozimo broj koji imamo s bazom (ovdje: 2),
         te dodamo sljedecu znamenku (ovdje: 0 ili 1) */
    int broj = 0;
    /* broj koji ucitamo spremamo u znamenka */
    int znamenka;
    scanf("%d", &znamenka);
    /* ucitali prvu, te sad izvrsavamo program dok
       god ce korisnik unositi 1 ili 0 */
    while(znamenka == 0 || znamenka == 1){
        broj = broj * 2 + znamenka;

        scanf("%d", &znamenka); /* ucitamo sljedecu znamenku,
               pa opet ide while petlja ako ucitano 0 ili 1*/
    }

    /* na kraju ispisemo dobiveni broj */
    printf("%d", broj);

    return 0;
}
