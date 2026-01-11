#include <stdio.h>
#include <stdlib.h>

void rippleSort(int pole[], int n)
{
    int posledni_Vymena = n;
    int pomocna = 0;
    for(int d = 0; d < n - 1; d = posledni_Vymena)
    {
        posledni_Vymena = n - 1;
        for(int i = n - 1; i > d; i--)
        {
            if(pole[i - 1] > pole[i])
            {
                pomocna = pole[i - 1];
                pole[i - 1] = pole[i];
                pole[i] = pomocna;
                posledni_Vymena = i;
            }
        }
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
    rippleSort(pole, n);
    vypisPole(pole, n);
    return 0;
}