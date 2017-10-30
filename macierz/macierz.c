gcc/* Program liczacy wyznacznik macierzy dowolnego wymiaru z kontrola bledow alokcji pamieci */

#include <stdio.h>
#include <stdlib.h>

/* double alokacja (double ***matrix, int wymiar){

  int k=0;
  matrix=(double**)malloc(sizeof(double*)*(wymiar));

  if(matrix==NULL){
    free(matrix);
    printf("blad alokacji");
    return 0;
  }

  for (k=0; k<wymiar; k++){
    matrix[k]=(double*)malloc(sizeof(double)*(wymiar));
      if(matrix[k]==NULL){
        free(macierz[k]);
        printf("blad alokacji");
        return 0;
      }
  }
} */

double** alokacja (int wymiar){

  int k=0;
  double **macierz=NULL;
  macierz=(double**)malloc(sizeof(double*)*(wymiar));

  if(macierz==NULL){
    free(macierz);
    printf("blad alokacji");
    return 0;
  }

  for (k=0; k<wymiar; k++){
    macierz[k]=(double*)malloc(sizeof(double)*(wymiar));
      if(macierz[k]==NULL){
        free(macierz[k]);
        printf("blad alokacji");
        return 0;
      }
  }
  return macierz;
}

double wyznacznik (double **tab, int size){

  int l=0,i=0,j=0, znak=1;
  double **min=NULL,sum=0;

  if(size==1){
    return tab[0][0];
  }

  if (size==2){
    sum = tab[0][0]*tab[1][1]-tab[0][1]*tab[1][0];
  return sum;
  }

  min=alokacja(size-1);

  for(l=0;l<(size);l++){
    for(i=0; i<(size-1); i++){
      for(j=0; j<(size-1);j++){
        if(j<1)
          min[i][j]=tab[i+1][j];
        else
          min[i][j]=tab[i+1][j+1];
        }
      sum+=znak*tab[0][1]*wyznacznik(min, (size-1));
      znak=-znak;
    }
    sum+=znak*tab[0][1]*wyznacznik(min, (size-1));
    znak=-znak;
  }

  for(l=0; l<(size-1); l++){
     free(min[l]);
  }

  free (min);
  return sum;
}

int main(void){

  FILE *f;
  double **macierz=NULL, wynik=0;
  int wymiar=0, i=0, j=0;

  if( (f=fopen("matrix.txt", "rt")) != NULL){
    fscanf(f, "%d", &wymiar);
    macierz = alokacja(wymiar);

    for(i=0; i<wymiar; i++){
      for(j=0; j<wymiar; j++){
        fscanf(f, "%lf", &macierz[i][j]);
        printf("%f\n", macierz[i][j]);
      }
    }
  }
  else{
    printf("nie mozna otworzyc pliku");
    fclose(f);
    return 0;
  }

  fclose(f);
  wynik=wyznacznik(macierz, wymiar);
  printf("wyznacznik: %d\n", wynik);

  for(i=0; i<wymiar; i++){
    free(macierz[i]);
  }

  free(macierz);
return 0;
}
