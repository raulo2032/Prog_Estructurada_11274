/*anda mal/*

/*******************************orden por seleccion**************************/
/******************************pagina 149-150 users******************************/

#include<stdio.h>
#define MAX 5
  void orden_seleccion(int *vec, int cant);
  int menor(int *vec, int inicio, int candidato, int cant);

int main(void){
	int vector[MAX];
 
    vector[0]=3;
    vector[1]=2;
    vector[2]=8;
    vector[3]=5;
    vector[4]=4;

    orden_seleccion(vector, MAX);
	return 0;
}

void orden_seleccion(int *vec, int cant){
	int i, m, t;
    for(i=0; i<(cant -1); i++){
		m=menor(vec, (i++), i, cant);
		if(m!=i){
			t=vec[i]; 
			vec[i]=vec[m];
			vec[m]=t;
        }
	}
	for(i=0; i<cant; i++)
		printf("%d\n", vec[i]);
}

int menor(int *vec, int inicio, int candidato, int cant){
	int i;
    for(i=inicio; i<cant; i++)
		if(vec[candidato]>vec[i])
		   candidato=i;
    return(candidato);
}