// esto explicado por Juan Carlos
// para archivos de registro y binarios, Gustavo explica fpinrtf y para archivos de texto

void agregarRegustro( regCliente * reg){

    
    
    FILE * fd = fopen   ("nombre",        wb)     // write binario
    // ab   append binario 
    
    
    if(fd != NULL){
        int err = fwrite(reg, sizeof(reg), 1, fd);        //donde esta, tamanio, cantidad, donde escribe

        if(err == -1)
            printf("Error de escritura")
            
        fclese(fd);
    }
    else
        printf("Error de apertura")

}

int buscarRegustro(int codigo, regCliente * reg){

    
    
    FILE * fd = fopen   ("nombre",        rb)     // write binario
    // ab   append binario 
    
    
    if(fd != NULL){

        int pos = -1;
        int err = 
        while (err = (fread(reg,sizeof(reg),1, fd)) > 0  && reg.codigo != codigo  );    // aca va iterando registro ++ pero no hay que especificarlo
                                                                // por lo general, recorriendo un vector, pondriamos i++, pero en regitros va avanzando solo
        
        // fread(posicion leido,tamanio,cantidad, de que archivo  )
        if (err > 0 && reg.codigo = codigo){    /* encontro  */
                    /* hay que calcular el valor de pos*/

                    pos = ftell(fd) - sizeof(reg);  // ftell me manda a EOF, entonces le resto la long del reg y estoy uno antes del EOF

        }
        
            
        fclese(fd);
    }
    else
        printf("Error de apertura")

    return pos;

}


// UN ARCHIVO DE LECTURA LO LEEMOS SIEMPRE CON WHILE

WHILE ( != EOF)...

si abrimos un archivo para cargar. si se puede con un for ( , , )
//  scanf es el que genera probelma con el \n

// para agregar, tenemos que leer, e ir copiando hasta lo que queremos agregar y seguimos copiando
// despues podemos renombrar el nuevo archivo con el nomnbre del viejo
