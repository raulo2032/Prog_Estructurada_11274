#include <string.h>
#include <stdio.h>

int deados(char [], char []);

int main(void){ 
    char s1[10]="Male";
    char s2[10]="Male";
    
    int comparacion = deados(s1, s2);
    
    if(comparacion == 0){
        printf("Las cadenas son iguales \n");
           
    }
    else{
        printf("Las cadenas son distintas \n");
    }
    
    return 0;
}


int deados(char s1[], char s2[]){
    int res, i;
    while( (s1[i] == s2[i]) && i < strlen(s1) ){
        i++;
    }
    if (i == strlen(s1)){
        res = 0; 
    }
    else{ 
        res = 1; 
    } 
    return res;
}
