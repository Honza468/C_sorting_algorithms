#include <stdio.h>
#include <stdlib.h>

void shakerSort(int pole[], int n)
{
    int pocitadlo = 0;
    int posledni_VymenaP = n - 1;
    int posledni_VymenaL = 0;
    int pomocna = 0;
    while(posledni_VymenaL < posledni_VymenaP)
    {
        pocitadlo = posledni_VymenaL;
        for(int i = posledni_VymenaL; i < posledni_VymenaP; i++)
        {
            if(pole[i] > pole[i + 1])
            {
                pomocna = pole[i];
                pole[i] = pole[i + 1];
                pole[i + 1] = pomocna;
                pocitadlo = i; 
            }
        posledni_VymenaP = pocitadlo;
            
        pocitadlo = posledni_VymenaP;
        for(int i = posledni_VymenaP; i > posledni_VymenaL; i--)
        {
            if(pole[i - 1] > pole[i])
            {
                pomocna = pole[i];
                pole[i] = pole[i - 1];
                pole[i - 1] = pomocna;
                pocitadlo = i; 
            }
        }
        posledni_VymenaL = pocitadlo;
    }
}

void vypisPole(int pole[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", pole[i]);
    }
}

int main()
{
    int n = 9;
    int pole[9] = {9, 0, 6, 7, 4, 9, 3, 7, 2};
    shakerSort(pole, n);
    vypisPole(pole, n);
    return 0;
}