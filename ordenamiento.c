Hola a todos, tengo una pequeña duda, con respecto a los metodos de ordenamiento, bueno
suponiendo que tengo que ordenar un arreglo(utilizando dichos métodos); ¿se puede 
ordenar un arreglo creado dinamicamente?, es decir sin conocer la longitud del mismo,
o lo que tengo que hacer es crear una funcion que me entregue la cadena util, y 
trabajar con esta.
Gracias y disculpen las molestias                     Raquel
/**********************************/

Hola Raquel
Se me ocurre pensar que la cantidad de elementos a ordenar deber ser un 
dato que conozcas. Sino como se podría saber, sin conocer este dato, 
cuando hay que terminar de ordenar porque no hay mas elementos? Si no 
supieras este dato, y ejecutaras un método de ordenamiento, quizás 
termines sobreescribiendo un segmento de memoria donde guardabas otra 
información. Creo que esto vale tanto para arreglos "estáticos" (es 
decir  un char arreglo[256] por ej.) como para memoria dinámica.
Sino proba con incluir este pedacito de código en un main y fijate que 
pasa, esto creo que genera el mismo error que te podría generar un 
ordenamiento sin saber la cantidad de elementos a ordenar.

/* Intercambiemos elementos, los que tienen un "indice" par, van a 
pasar a reemplazar a sus consecutivos, y estos reemplazaran a sus anteriores
es decir, si teníamos 0,1,2,3,4,5,6,7  quedara   1,0,3,2,5,4,7,6.
 De alguna forma es un método de "ordenamiento" que lee y escribe como
lo haria cualquier otro método, y sin saber donde terminar.
El arreglo "arreglo[]" se carga con números de 0 al 19 para hacer la 
operación de intercambio*/

void main (void){
	int arreglo[20];
	int c,d;

	// Cargamos el arreglo con numeros
    for (c=0; c<=19; c++)
		arreglo[c]=c;

	// Aca empieza a intercambiar, pero...no sabemos donde terminar   
    c = 0;
    while(1){
		// Esto es una tipica operacion de Swapping
        d = arreglo[c+1]; 
        arreglo[c+1] = arreglo[c];
        arreglo[c] = d;

        printf("Par %i Impar %i\n",arreglo[c],arreglo[c+1]);
        c += 2;
	}
}
cuando veas lo que pasa en pantalla, vas a ver que hasta las primeras 
10 lineas esta todo mas que bien, claro es que hasta el indice 19, estamos 
en el arreglo, estamos haciendo una operacion valida sobre el. Pero como esto 
continua, el programa "toma" el elemento siguiente al 19 (aca el arreglo ya no 
existe mas) y va a continuar por siempre haciendo esta operación. 
Afortunadamente, a las pocas iteraciones el programa escapa sin dar 
errores... pero, escapa de un While(1) ! Asi que seguramente hubo un 
error dentro de la aplicación porque intento reescribir donde no debia. 
Con memoria dinámica esto creo que seria catastrófico, tu programa no 
para nunca, y creo que hasta te apaga la maquina....probalo!

Un saludo, espero haberte ayudado un poco
Ezequiel

/*****************/
	Si bien no está pensado inicialmente para eso, el HeapSort puede
servirte para realizarlo (el mismo no se da en el curso); es un método
con complejidad O(n*log(n)), por lo tanto, de los más veloces que 
pueden encontrarse. Lo que sí es que no tendrías ordenado el array a cada 
paso, sino preprocesado de tal modo que es posible finalizar el ordenamiento
al tenerlo completo en un tiempo breve.
	Sino, no se me ocurre ninguna manera de hacerlo que no sea O(n²); es
decir, podrías tener a cada paso el array ordenado insertando en orden
cada elemento a medida que lo leés; esto sería, buscar el lugar que le
corresponde (puede hacerse por búsqueda binaria -o secuencial, dado que
no disminuye su complejidad-) y luego desplazar todos los elementos
siguientes uno hacia la derecha dejando el lugar libre. Con algo así
tendrías a cada paso tu array completamente ordenado, pero la
complejidad se aleja de la óptima de O(n*log(n)).
	Selección también puede servirte.
	De todos modos, depende de para qué es que lo necesités.
	Saludos.

							Sebastián Santisi
							santisis@7502.com.ar
/********************/
Hola, Raquel, mirá, siempre que crees un arreglo(estático o dinámico) podés saber 
su longitud.

Si es un arreglo estático, lo debés haber declarado y
debés tener una variable que te indique cuánto llevás
utilizado---> conocés la longitud.

Para arreglos estáticos, si no lo conoces, podes
hacer:

unsigned int L =
sizeof(miarreglo)/sizeof(miarreglo[0]);

truquillo para saber el largo total, máximo, de
definición, no el real!
Si el arreglo era de MAX elementos, l valdrá MAX.
Para arreglos dinámicos, sizeof(miarreglo) te daría lo
ocupado por el puntero, no por lo apuntado ie el
contenido.
Saludos,
Martin
/*******************/
 Cuando _resuelvan_los_ejercicios que estaban
planteados con cadenas y arreglos de cadenas para
practicar, ... pueden incorporar la variante de
devolver arreglos de cadenas con el ultimo puntero en
NULL. Asi se independizan de su longitud :-)
Saludos,  Martin
