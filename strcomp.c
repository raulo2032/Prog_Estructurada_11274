#include <string.h>
#include <stdio.h>

int iguales(char [], char [], char []);
int deados(char [], char []);

int main(void){ 
    char s1[10]="Male";
    char s2[10]="Mals";
    char s3[10]="Mala"; 
    
    printf("La salida de la funcion es %i \n", iguales(s1,s2,s3));
    
    return 0;
}

int iguales(char s1[], char s2[], char s3[]){
    int retorno;
    printf("%c%c%c\n", s1[0],s2[0], s3[0]);

    if(deados (s1,s2)==0){
        if(deados(s1,s3)==0){
            retorno = 3;
        }
    }
    else if(deados(s2,s3)==0){          
        retorno = 2;
    } 
    else if(s1[0]==s2[0]){
        retorno = 0;
    }
    else if ( (s1[0]!=s2[0]) && (s1[0]!=s3[0]) && (s2[0]!=s3[0]) ){
        retorno = 4; 
    }
    return retorno;
}

int deados(char s1[], char s2[]){
    int res, i;
    while( (s1[i] == s2[i]) && i < strlen(s1) ){
        i++;
    }
    if ( i == strlen(s1)){
        res = 0; 
    }
    else{ 
        res = 1; 
    } 
    return res;
}

 