#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void alokacja (int **macierz, int wymiar) {
  int k;
  macierz=(int**)malloc(wymiar*sizeof(int*));
               for (k=0; k<wymiar;k++) {
               		macierz[k]=(int*)malloc(wymiar*sizeof(int));
       }
}

int wyznacznik (int **tab, int size)
{
       int i, j, k, l;
       int **min;
       int znak=1, sum=0;

       if(size==1)
       {
               return tab[0][0];
       }

	alokacja(min, size-1);

	  for(l=0; l<(size); l++)								//iteruje kazdy kolejny element macierzy, l-do liczenia przekatnej
	  {
		    for(i=0; i<(size-1); i++)					//pomocnicza tablica
		    {
			    for(j=0; j<(size-1); j++)
			    {
				      if (j<l)				// zaleznie od wartosci kolumny przesuwa odpowiednio wartosci
						     min[i][j]=tab[i+1][j];
						      else
				         min[i][j]=tab[i+1][j+1];
			    }
		    }
		    printf("suma=%d\n", sum);
		    sum+=znak*tab[0][l]*wyznacznik(min, (size-1));
		    znak=-znak;
	  }
	  for (k=0; k<(size-1);k++){					//przechodze po komorkach zalokowanej pamieci pierwszego wymaru
			    free(min[k]);
	  }
	  free(min);
	  return sum;
}


int main (void)
{
    FILE *f;
    int **macierz,wymiar, wynik, i, j, k;
    if( (f=fopen("plik.txt", "rt")) !=NULL){
               fscanf(f, "%d", &wymiar);
               alokacja(macierz, wymiar);
               for(i=0; i<wymiar; i++) {
                       for(j=0; j<wymiar; j++) {
                      fscanf(f, "%d", &macierz[i][j]);
                       }
               }
       }
       fclose(f);
       wynik=wyznacznik(macierz, wymiar);
       printf("Wyznacznik: %d\n", wynik);

    	for(k=0;k<wymiar;k++){
    		free(macierz[k]);
    	}
       free(macierz);
       return 0;
}
