#include <stdio.h>
#include <stdlib.h>

void insertSort(int pole[], int n)
{
    int vkladany = 0;
    int i = 0;
    for(int d = 1; d < n; d++)
    {
        vkladany = pole[d];
        i = d;
        while((i > 0) && (pole[i - 1] > vkladany))
        {
            pole[i] = pole[i - 1];
            i = i - 1;
        }
        pole[i] = vkladany;
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
    insertSort(pole, n);
    vypisPole(pole, n);
    return 0;
}