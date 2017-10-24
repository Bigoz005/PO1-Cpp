#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD

double** alokacja (int wymiar) {
  int k=0;
  double **macierz=NULL;
  macierz=(double**)malloc(wymiar*sizeof(double*));
  if(macierz==NULL){
  free(macierz);
  printf("blad przypisania pamieci");
  return 0;}
    for (k=0; k<wymiar;k++) {
     		macierz[k]=(double*)malloc(wymiar*sizeof(double));
      if(macierz[k]==NULL){
        free(macierz[k]);
        printf("blad przypisania pamieci");
        return 0;
      }
  }
return macierz;
}

int wyznacznik (double **tab, int size)
=======
/*
void alokacja (double ***macierz, int wymiar) {
  int k=0;
  macierz=(double**)malloc(sizeof(double*)*(wymiar));
  for (k=0; k<wymiar;k++) {
    macierz[k]=(double*)malloc(sizeof(double)*(wymiar));
  }
}
*/

double** alokacja (int wymiar) {
  int k=0;
  double **macierz = NULL;
  macierz=(double**)malloc(sizeof(double*)*(wymiar));
  
  if("blad malloca"){
    free(macierz);
    return 0;
  }
  
  for (k=0; k<wymiar;k++) {
    macierz[k]=(double*)malloc(sizeof(double)*(wymiar));
    
    if("bald malloca){
    free(macierz[k]);
    return 0;
    }
  }
  return macierz;
}


int wyznacznik (double **tab, double size)
>>>>>>> cee1e993cf617044976355e009a7f7a82a85ab27
{
       int i=0, j=0, k=0, l=0;
       double **min=NULL;
       int znak=1, sum=0;

       if(size==1)
       {
               return tab[0][0];
       }
<<<<<<< HEAD

       if(size==2)
       {
        sum = tab[0][0]*tab[1][1]-tab[0][1]*tab[1][0];
        return sum;
       }

	min=alokacja(size-1);

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
		    printf("\nsuma=%d\n", sum);
		    sum+=znak*tab[0][l]*wyznacznik(min, (size-1));
		    znak=-znak;
=======
       if(size==2)
       {
		sum = tab[0][0]*tab[1][1]-tab[0][1]*tab[1][0];
		return sum;
       }
       min = alokacja(size-1);
       
       for(l=0; l<(size); l++){
	  for(i=0; i<(size-1); i++){		/*pomocnicza tablica 'podmacierz'*/
	      for(j=0; j<(size-1); j++){
		    if (j<l)			/* zaleznie od wartosci kolumny przesuwa odpowiednio wartosci*/
		    min[i][j]=tab[i+1][j];
		    else
		    min[i][j]=tab[i+1][j+1];
	      }
>>>>>>> cee1e993cf617044976355e009a7f7a82a85ab27
	  }
	  printf("suma=%d\n", sum);
	  sum+=znak*tab[0][l]*wyznacznik(min, (size-1));
	  znak=-znak;
	}
	for (k=0; k<(size-1);k++){	/*przechodze po komorkach zalokowanej pamieci pierwszego wymiaru*/
	  free(min[k]);
	  }
	free(min);
return sum;
}

int main (void)
{
    FILE *f;
<<<<<<< HEAD
    double **macierz=NULL;
    int wymiar=0, wynik=0, i=0, j=0;
    if( (f=fopen("plik.txt", "rt")) !=NULL){
              fscanf(f, "%d", &wymiar);
              printf("rozmiar macierzy: %d", wymiar);
              macierz = alokacja(wymiar);

               for(i=0; i<wymiar; i++) {
                    for(j=0; j<wymiar; j++) {
                    fscanf(f, "%lf", &macierz[i][j]);
                       }
               }
       }
       else
       {
         printf("nie mozna otworzyc pliku");
         return 0;
       }
       fclose(f);
       wynik=wyznacznik(macierz, wymiar);
       printf("Wyznacznik: %d\n", wynik);

    	for(i=0;i<wymiar;i++){
    		free(macierz[i]);
    	}
       free(macierz);
       return 0;
=======
    int wymiar=0, wynik=0, i=0, j=0;
    double **macierz=NULL;
    if( (f=fopen("matrix.dat", "rt")) !=NULL){
	  fscanf(f, "%d", &wymiar);
	  printf("rozmiar macierzy: %d", wymiar);
	  macierz = alokacja(wymiar);

	  for(i=0; i<wymiar; i++) {
	      for(j=0; j<wymiar; j++) {
		  fscanf(f, "%lf", &macierz[i][j]);
		  printf("%f ", macierz[i][j]);
	      }
	  }
       }
      else{
      printf("Nie mozna otworzyc pliku");
      }
    fclose(f);
    wynik=wyznacznik(macierz, wymiar);
    printf("Wyznacznik: %d\n", wynik);

    for(i=0;i<wymiar;i++){
    free(macierz[i]);
    }
    free(macierz);
return 0;
>>>>>>> cee1e993cf617044976355e009a7f7a82a85ab27
}
