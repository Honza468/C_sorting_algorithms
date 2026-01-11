#include <stdio.h>
#include <stdlib.h>

void insertSortZL(int pole[], int n)
{
    int vkladany = 0;
    int i = 0;
    for(int i = n; i > 0; i--)
    {
        pole[i] = pole[i - 1];
    }

    for(int d = 1; d <= n; d++)
    {
        vkladany = pole[d];
        pole[0] = vkladany;
        i = d;
        while(pole[i - 1] > vkladany)
        {
            pole[i] = pole[i - 1];
            i = i - 1;
        }
        pole[i] = vkladany;
    } 
}

void insertSortZP(int pole[], int n)
{
    int vkladany = 0;
    int i=0;
    for(int d = n - 1; d >= 0; d--)
    {
        vkladany = pole[d];
        pole[n] = vkladany;
        i = d;
        while(vkladany > pole[i + 1])
        {
            pole[i] = pole[i + 1];
            i++;
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
    printf("\nZarazka je zde: %d\n", pole[n]);
}

void vypisPoleZL(int pole[], int n)
{
    printf("\nZarazka je zde: %d\n", pole[0]);
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", pole[i]);
    }
}

int main()
{
    int n = 9;
    int pole1[10] = {9, 0, 6, 7, 4, 9, 3, 7, 2};
    int pole2[10] = {9, 0, 6, 7, 4, 9, 3, 7, 2};
    insertSortZL(pole1, n);
    vypisPoleZL(pole1, n);
    printf("\n");
    insertSortZP(pole2, n);
    vypisPole(pole2, n);
    return 0;
}