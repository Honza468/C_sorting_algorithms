#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct{
	char ucitel;
	char jmeno[30];
	char prijmeni[30];
	float prumer;
}Tzak;

int prepisDoPole(FILE * vstup, Tzak t[])
{
	int i = 0;
	while(i < MAX && fscanf(vstup, " %c;%[^;];%[^;];%f", &t[i].ucitel, t[i].jmeno, t[i].prijmeni, &t[i].prumer) == 4)
	{
		i++;
	}
	return i;
}

void vypisPole(Tzak t[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%c %s %s %.2f\n", t[i].ucitel, t[i].jmeno, t[i].prijmeni, t[i].prumer);
	}
}

void RippleSort(Tzak t[],int n)
{
  int indexPosledniVymeny;
  for(int d = 0; d < n - 1; d = indexPosledniVymeny)
  {
    indexPosledniVymeny = n;
    for(int i = n - 1; i > d; i--)
    {
      if (t[i-1].prumer > t[i].prumer)
      {
        Tzak pom = t[i-1];
        t[i-1] = t[i];
        t[i] = pom;
        indexPosledniVymeny = i;
      }
    }
  }
}

void SelectionSort(Tzak t[], int n)
{
  for(int d = 0; d < n - 1; d++) 
  {
    int min = d;
    for (int i = d + 1; i < n; i++)
    {
      if(t[i-1].prumer > t[i].prumer)
        min = i;
    }
    Tzak pom = t[d];
    t[d] = t[min];
    t[min] = pom;
  }
}

void SelectSortPrijmeni(Tzak t[], int n)
{
  for(int d = 0; d < n - 1; d++) 
  {
    int min = d;
    for (int i = d + 1; i < n; i++)
    {
      if(strcmp(t[min].prijmeni, t[i].prijmeni) > 0)
        min = i;
    }
    Tzak pom = t[d];
    t[d] =  t[min];
    t[min] = pom;
  }
}

int main()
{
	Tzak t[MAX];
	FILE * f=fopen("4f.csv", "r");
	if(f == NULL)
	{
		printf("Soubor se nepodarilo otevrit!\n");
		return EXIT_FAILURE;
	}
	int n = prepisDoPole(f, t);
	vypisPole(t, n);
	printf("\n");
	RippleSort(t, n);
	vypisPole(t, n);
	printf("\n");
	SelectionSort(t, n);
	vypisPole(t, n);
	printf("\n");
	SelectSortPrijmeni(t, n);
	vypisPole(t, n);
	return 0;
}
