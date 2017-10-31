/* Program liczacy wyznacznik macierzy dowolnego wymiaru z kontrola bledow alokcji pamieci */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double **alokacja(int n){
	int i,j;
	double **macierz = (double **)malloc(n * sizeof(double*));
	if(macierz==NULL){
		printf("Blad alokacji");
		return 0;
	}
	for(i = 0; i < n; i++){
		macierz[i] = (double *)malloc(n * sizeof(double));
		if(macierz[i]==NULL){
		  printf("Blad alokacji");
		  for(j=0; j < i ;j++){
			free(macierz[j]);
		  }
		  free(macierz);
		  return 0;
		}
	}
	return macierz;
}
void matrix_free(double** minor, int n){
	int i;
	for (i=0; i<n; i++){
		free(minor[i]);
	}
	free(minor);
}

double det(double ** matrix, int n)
{
	double ** minor;
	double sum=0.0;
	double sign=1.0;
	int i,j,k;

	if(n==1){
		return matrix[0][0];
	}
	if(n==2){
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}

	minor = alokacja(n-1);

	for(i=0;i<n;i++){
		for(j=0; j<n-1; j++){
			for(k=0; k<n-1;k++){
				if(i>k){
					minor[j][k]=matrix[j+1][k];
				}else{
					minor[j][k]=matrix[j+1][k+1];
				}
			}
		}
		sum+=sign*matrix[0][i]*det(minor,n-1);
		sign=-sign;
	}
	matrix_free(minor, n-1);
	return sum;
}

int main(){
	double **minor;
	FILE *p;
	int n = 0, i,j;
	p = fopen ("matrix.txt","rt");
	if (p!=NULL)
	{
		fscanf(p, "%d", &n);
		minor = alokacja(n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				fscanf(p, "%lf", &minor[i][j]);
			}
		}
	fclose (p);
	printf("%lf", det(minor, n));
	matrix_free(minor, n);
	}
	else{
		fclose (p);
		printf("Nie mozna otworzyc pliku");
	}
	return 0;
}