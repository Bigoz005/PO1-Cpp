
/*Funkcja łącząca łańcuchy tekstowe
Napisz w języku C funkcję przyjmującą dwa łańcuchy tekstowe, alokującą pamięć
i zwracającą konkatenację tych łańcuchow.
Wykorzystaj tą funkcję w przykładowym programie, pamiętając o właściwym zarządzaniu pamięcią.
Zwróć uwagę na różnicę działania (w zakresie dostępu do pamięci)
napisanej funkcji i standardowej funkcji strcat.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* stringmerge(char* str1, char* str2){

    int n1,n2,i=0,j=0;
    char* str3;

    n1=strlen(str1);
    n2=strlen(str2);

    str3=malloc(sizeof(char)*(n1+n2+1));

        do{
           str3[i]=str1[i];
           i++;
       }while(str1[i]!='\0');

       do{
           str3[i]=str2[j];
           i++;
           j++;
       }while(str2[j]!='\0');

    str3[i]='\0';
    return str3;
}

int main(){

    char str1[30] = "string1";
    char *str2 = "string2";
    char *wynik = 0;

    wynik= stringmerge(str1, str2);
    printf("Polaczono lancuchy : %s.", wynik);
    free(wynik);

return 0;
}
