#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//----- Designove funkce, slouzi pro lepsi navigaci ve vypisech -----
void oddelovaciCara()
{
	printf("----------------------------------------------------\n");
}

void zacatkovaHlaska()
{
	printf("Zacatek radiciho programu.\n");
}

void potvrzujiciHlaska()
{
	printf("Serazeni probehlo uspesne!\n");
}
//----- Konec sekce designovych funkci -----

//----- Sekce radicich algoritmu -----
void selectionSort(int pole[], int n)
{
	printf("Selection sort algoritmus.\n");
	zacatkovaHlaska();
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
	potvrzujiciHlaska();
}

//------------------------------------

void insertSort(int pole[], int n)
{
	printf("Insert sort algoritmus (verze bez zarazek).\n");
	zacatkovaHlaska();
	int vkladany = 0;
	int index = 0;
	for(int i = 1; i < n - 1; i++)
	{
		vkladany = pole[i];
		index = i;
		while((index > 0) && (pole[index - 1] > vkladany))
		{
			pole[index] = pole[index - 1];
			index--;
		}
		pole[index] = vkladany;
	}
	potvrzujiciHlaska();
}

//------------------------------------ 

void insertSortSeZL(int pole[], int n)
{
	//Zacatek - posun pole o jednu pozici na pravou stranu
	printf("Insert sort se zarazkou vlevo.\n");
	zacatkovaHlaska();
	int vkladany = 0;
	int index = 0;
	for(int i = n - 1; i > 0; i--)
	{
		pole[i] = pole[i - 1];
	}
	printf("Posunuti pole probehlo uspesne!\n");
	for(int d = 2; d < n - 1; d++)
	{
		vkladany = pole[d];
		pole[0] = vkladany;
		index = d;
		while(pole[index - 1] > vkladany)
		{
			pole[index] = pole[index - 1];
			index--;
		}
		pole[index] = vkladany;
	}
	potvrzujiciHlaska();
}

//------------------------------------ 

void insertSortSeZP(int pole[], int n)
{
	printf("Insert sort se zarazkou vpravo.\n");
	zacatkovaHlaska();
	for(int i = n - 3; i >= 0; i--)
	{
		pole[n - 1] = pole[i];
		int index = i;
		while(pole[n - 1] > pole[index + 1])
		{
			pole[index] = pole[index + 1];
			index++;
		}
		pole[index] = pole[n - 1];
	}
	potvrzujiciHlaska();
}

//------------------------------------

void bubbleSort(int pole[], int n)
{
	printf("Bubble sort\n");
	zacatkovaHlaska();
	int pomocna = 0;
	for(int i = 0; i < n - 2; i++)
	{
		for(int d = n - 1; d > i; d--)
		{
			if(pole[d - 1] > pole[d])
			{
				pomocna = pole[d - 1];
				pole[d - 1] = pole[d];
				pole[d] = pomocna;
			}
		}
	}
	potvrzujiciHlaska();
}

//----- Konec sekce radicich algoritmu -----

//-----Sekce pomocnych funkci pro spravnou funkci algoritmu -----
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

void vypisPole(int pocatek, int pole[], int n)
{
	for(int i = pocatek; i < n - 1; i++)
	{
		printf("%d ", pole[i]);
	}
	printf("\n");
}
//----- Konec sekce pomocnych funkci -----

int main()
{
//----- Sekce testovaci poli -----
	int testovaci1[12] = {12, 1, 3, 0, 65, 8, 7, 6, 11, 3, 2};
	int testovaci2[12] = {12, 1, 3, 0, 65, 8, 7, 6, 11, 3, 2};
	int testovaci3[13] = {12, 1, 3, 0, 65, 8, 7, 6, 11, 3, 2}; 
	int testovaci4[13] = {12, 1, 3, 0, 65, 8, 7, 6, 11, 3, 2};
	int testovaci5[12] = {12, 1, 3, 0, 65, 8, 7, 6, 11, 3, 2};
//----- Konec sekce testovacich poli -----

//----- Zakomentovana sekce, bude zprovoznena v budoucnu -----
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
//----- Konec zakomentovane sekce -----

//----- Selection sort -----
	oddelovaciCara();
	selectionSort(testovaci1, 12);
	vypisPole(0, testovaci1, 12);

//----- Insert sort bez zarazek -----
	oddelovaciCara();
	insertSort(testovaci2, 12);
	vypisPole(0, testovaci2, 12);

//----- Insert sort se zarazkou vlevo -----
	oddelovaciCara();
	insertSortSeZL(testovaci3, 13);
	vypisPole(1, testovaci3, 13);

//----- Insert sort se zarazkou vpravo -----
	oddelovaciCara();
	insertSortSeZP(testovaci4, 13);
	vypisPole(1, testovaci4, 13);

//---- Bubble sort -----
	oddelovaciCara();
	bubbleSort(testovaci5, 11);
	vypisPole(0, testovaci5, 12);
	return 0;
}
