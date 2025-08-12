  
float* leer_datos(float *cadena_entrada,FILE* p){
	float i;
	unsigned int alloc, used, c;
	char cadena[MAX_STR],*temporal;
      
	p=stdin;
	c=getchar();
	for(k=0; c!=EOF; k++){
		ungetc(c, stdin);
		fgets(cadena,ANCHO_CAMPO , stdin);
		i=strtod(cadena, &temporal);
		cadena_entrada[used]=i;
		c=getchar();
	}
	
	return cadena_entrada;

}
