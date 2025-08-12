#include <stdio.h>

int main(void){
	int i;
	for(i=0; i<256; i++)
		printf("%2i%s%2X\t", i, "=", i);
	
	return 0;
}
