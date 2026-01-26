#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <windows.h>
#define MAX 7000

int nactiDoPole(FILE *vstup, int pole[])
{
	int i = 0;
	int znak = 0;
	while(i < MAX && fscanf(vstup, "%d", &znak) != EOF)
	{
		pole[i] = znak;
		i++;
	}
	return 0;
}

bool serazenoVZ(int pole[], int n)
{
	int i = 0;
	while(i < MAX)
	{
		if(pole[i] < pole[i + 1])
		{
			i++;
		}
		else
		{
			return false;
		}
	} 
  return true;
}

void pauza_konzole() {
    printf("Stiskněte ENTER pro pokračování...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    getchar();
}

int sekvencniVyhledavani(int pole[], int n, int klic)
{
	int i = 0;
	while(i < n && pole[i] != klic)
	{
		i++;
	}
	if(i < n)
	{
		return i;
	}
	else
	{
		return -1;
	}
}

int sekvencniSeZarazkou(int pole[], int n, int klic)
{
	pole[n - 1] = klic;
	int i = 0;
	while(pole[i] != klic)
	{
		i++;
	}
	if(i < n)
	{
		return i;
	}
	else
	{
		return -1;
	}
}

int sekvencniSerazene(int pole[], int n, int klic)
{
	int i = 0;
	while(i < n && pole[i] < klic)
	{
		i++;
	} 
	if(i < n && pole[i] == klic)
	{
		return i;
	}
	else
	{
		return -1;
	}
}

int SekvencniSerazeneSeZarazkou(int pole[], int n, int klic)
{
	int posledni = pole[n - 1];
	pole[n] = klic;
	int i = 0;
	while(pole[i] != klic)
	{
		i++;
	}
	if(i < n && pole[i] == klic)
	{
		return i;
	}
	else
	{
		return -1;
	}
}

int BinarniVyhledavani(int pole[], int l, int p, int klic)
{
	while(l <= p)
	{
		int stred = (l + p)/2;
		if(pole[stred] == klic)
		{
			return stred;
		}
		if(pole[stred] < klic)
		{
			l = stred + 1;
		}
		else
		{
			p = stred + 1;
		}
	}
	return -1;
}

int menu()
{
  printf("1....... neserazene pole\n");
  printf("2....... neserazene pole se zarazkou\n");
  printf("3....... serazene pole\n");
  printf("4....... serazene pole se zarazkou\n");
  printf("5....... binarni vyhledavani\n");
  printf("0....... konec\n");
  printf("Zvol si metodu: ");
  int volba;
  scanf("%d", &volba);
  while (volba <0 || volba >5)
  {
    printf("Zvol si 0-5: ");
    scanf("%d", &volba);
  }
  return volba;
}

int nactiKlic()
{
  int klic;
  printf("Zadej klic, ktery chces vyhledat: ");
  scanf("%d", &klic);
  return klic;
}

int main()
{
    printf("Vyhledavaci algoritmy!\n");
    char soubor[20];
    printf("Zadej nazev souboru i s priponou: ");
    scanf("%19s", soubor);
    FILE *f=fopen(soubor, "r");
    if (f==NULL) return -1;
    int pole[MAX];	
    int pocet = nactiDoPole(f,pole);
    printf("Pocet nactenych klicu je %d.\n", pocet);
    int volba = 1,klic;
    while (volba != 0)
    {
      klic = nactiKlic();
      volba = menu();
      switch(volba)
      {
        case 1:
					sekvencniVyhledavani(pole, pocet, klic);
				break;
        case 2:
					sekvencniSeZarazkou(pole, pocet, klic);
				break;
        case 3:
					sekvencniSerazene(pole, pocet, klic);
				break;
        case 4:
					SekvencniSerazeneSeZarazkou(pole, pocet, klic);
				break;
        case 5:
					BinarniVyhledavani(pole, 0, pocet, klic);
				break;
        case 0: printf("No konecne!");
      }
      pauza_konzole();
			system("clear");
    }


    fclose(f);
    return 0;

}
