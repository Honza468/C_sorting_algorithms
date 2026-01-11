#include <stdio.h>
#include <stdlib.h>

void selectionSort(int pole[], int n)
{
    int pomocna = 0;
    int minIndex = 0;
    for(int d = 0; d < n - 1; d++)
    {
        minIndex = d;
        for(int i = d + 1; i < n; i++)
        {
            if(pole[minIndex] > pole[i])
            {
                minIndex = i;
            }
        }
        pomocna = pole[d];
        pole[d] = pole[minIndex];
        pole[minIndex] = pomocna;
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
    selectionSort(pole, n);
    vypisPole(pole, n);
    return 0;
}