#include <stdio.h>
#include <stdlib.h>

void quickSort(int pole[], int levy, int pravy)
{
	if(levy < pravy)
	{
		int pivot = pole[(levy + pravy) / 2];
		int levy2 = levy;
		int pravy2 = pravy;

		do
		{
			while(pole[levy2] < pivot && levy2 < pravy)
			{
				levy2++;
			}

			while(pivot < pole[pravy2] && pravy > levy)
			{
				pravy2--;
			}

			if(levy2 < pravy2) //vymena cisla >= index levy2 <= index pravy
			{
				int pom = pole[levy2];
				pole[levy2] = pole[pravy2];
				pole[pravy2] = pom;
			}

			if(levy2 <= pravy2) //jen uprava indexu
			{
				levy2++;
				pravy2--;
			}
		}while (levy2 < pravy2);

		quickSort(pole, levy, pravy);
		quickSort(pole, levy, pravy);
	}
} 

int main()
{
	return 0;
}
