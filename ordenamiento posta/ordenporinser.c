/* andaba mal, pero le cambie lo del j+1, que yo puse j++, pero ahora lo deje en j+1... */











/******************orden por insercion******************************/
/******************pag 154 users************************************/

#include<stdio.h>
#define MAX 5

void orden_insercion(int *vec, int cant);

int main(void){
	int vector[MAX];
    vector[0]=10;
    vector[1]=2;
    vector[2]=1;
    vector[3]=16;
    vector[4]=4;

    orden_insercion(vector, MAX);
	return 0;
}

void orden_insercion(int *vec, int cant){
	int i, j, t;
    for(i=1; i<cant; i++){
		t=vec[i];
		for( j= i- 1 ; (j>=0) && (t<vec[j]); j--)
			/****aca no se que es lo que dice el libro**/
        vec[ j+1 ] = vec[j];
        vec[ j+1 ] = t;
    }

    for(i=0; i<cant; i++)
		printf("%d\n", vec[i]);
}
