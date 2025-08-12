/*--Esta funcion se encarga de ordenar los elementos, de acuerdo a el criterio
     elegido, devuelve el arreglo ordenado                                           */

void burbuja_entero(int *v, int n){
	int i, j;
	bool flag;

	for(i=0; i<n; i++){
		flag=FALSE;
		for(j=0; j<n-1; j++){
			if(v[j]>v[i]){
				swap(&v[j], &v[i]);
				flag=TRUE;
			}
		}
		if(flag==FALSE)
			return;
	}
}

void swap_int(int *x , int *y){
	 int aux;
	 
	 aux= *x;
	 *x= *y;
	 *y= aux;
}
