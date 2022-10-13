#include <stdio.h>

void echange_contenu ( int *a, int *b) {
	int c= *a;
	*a=*b; 
	*b=c	;

}
int main() {
	int a =10;
	int b=20;
	printf("a =%d, b= %d \n",a,b);
	echange_contenu (&a,&b);
	printf("Apreès échange, \n a =%d, b= %d",a,b);
						
}			
