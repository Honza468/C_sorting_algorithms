#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void selectionSort(int pole[], int n)
{
	for(int i = 0; i < n - 2; i++)
	{
		int minIndex = i;
		for(int d = i + 1; d < n - 1; d++)
		{
			if(pole[minIndex] > pole[d])
			{
				minIndex = d;
			}
		}
		int pomocna = pole[i];
		pole[i] = pole[minIndex];
		pole[minIndex] = pomocna;
	}
}

void insertSort(int pole[], int n)
{

}

void potvrzujiciHlaska()
{
	printf("Serazeni probehlo uspesne!\n");
}

int prepisSouboru(FILE * vstup, int pole[])
{
	int i = 0;
	int znak = 0;
	while(i < MAX && fscanf(vstup, "%d", &znak) != EOF)
	{
		pole[i] = znak;
		i++;
	}
	return i;
}

void vypisPole(int pole[], int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		printf("%d ", pole[i]);
	}
	printf("\n");
}

int main()
{
	int testovaci1[12] = {12, 1, 3, 0, 65, 8, 7, 6, 11, 3, 2};
	//char nazev[MAX];
	//printf("V souboru, ktery chcete nacist a seradit muze byt maximalne 100 znaku!\n");
	//printf("Zadejte nazev souboru, ktery chcete otevrit a vyuzit pro zpracovani dat.");
	//printf("Nazev souboru muze mit maximalne 100 znaku!");
	//printf("Soubor musite zadat i s jeho priponou!");
	//scanf("%s", nazev);
	//FILE * f = fopen(nazev, "r");
	//if(f == NULL)
	//{
	//	printf("Soubor se nepodarilo otevrit!\n");
	//	return EXIT_FAILURE;
	//}
	//int pole[MAX];
	//int n = prepisSouboru(f, pole);
	selectionSort(testovaci1, 11);
	potvrzujiciHlaska();
	vypisPole(testovaci1, 11);
	return 0;
}
