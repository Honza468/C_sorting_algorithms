#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//----- Designove funkce, slouzi pro lepsi navigaci ve vypisech -----
void oddelovaciCara()
{
	printf("----------------------------------------------------\n");
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
	int vkladany = 0;
	int index = 0;
	for(int i = n - 1; i > 0; i--)
	{
		pole[i] = pole[i - 1];
	}
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

//------------------------------------

void rippleSort(int pole[], int n)
{
	printf("Ripple sort\n");
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
	potvrzujiciHlaska();
}

//------------------------------------

void shakerSort(int pole[], int n)
{
	printf("Shaker sort\n");
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
	char nazev[MAX];
	printf("Zadejte nazev souboru, ktery chcete otevrit a vyuzit pro zpracovani dat.\n");
	printf("Nazev souboru muze mit maximalne 100 znaku!\n");
	printf("Soubor musite zadat i s jeho priponou!\n");
	scanf("%s", nazev);
	FILE * f = fopen(nazev, "r");
	if(f == NULL)
	{
		printf("Soubor se nepodarilo otevrit!\n");
		return EXIT_FAILURE;
	}
	int pole[MAX];
	int n = prepisSouboru(f, pole);
	int volbaRA = 0;

	printf("Nabidka radicich algoritmu (vyberte, kterym algoritmem chcete radit).\n");
	oddelovaciCara();	
	printf(
		"(1) Selection sort\n"
		"(2) Insert sort (bez zarazek)\n"
		"(3) Insert sort (se zarazkou vlevo)\n"
		"(4) Insert sort (se zarazkou vpravo)\n"
		"(5) Bubble sort\n"
		"(6) Ripple sort\n"
		"(7) Shaker sort\n");
	printf("Zadejte cislo vasi volby.\n");
	scanf("%d", &volbaRA);
	oddelovaciCara();
	printf("Vybrana volba:\n");

	switch(volbaRA)
	{
		case 1:
			selectionSort(pole, n);
			vypisPole(0, pole, n);
		break;		
		case 2:
			insertSort(pole, n);
			vypisPole(0, pole, n);
		break;
		case 3:
			insertSortSeZL(pole, n + 1);
			vypisPole(1, pole, n + 1);
		break;
		case 4:
			insertSortSeZP(pole, n + 1);
			vypisPole(1, pole, n + 1);
		break;
		case 5:
			bubbleSort(pole, n);
			vypisPole(0, pole, n);
		break;
		case 6:
			rippleSort(pole, n);
			vypisPole(0, pole, n);
		break;
		case 7:
			shakerSort(pole, n);
			vypisPole(0, pole, n);
		break;
	}	
	return 0;
}
