# TP-Note
#include <stdio.h>

int* repeat ( int *t1, int *t2 ) {
	int t[20];
	int somme = 0;
	int n =0;
	for (int i =0; i< sizeof(t2);i++) {
		for (int j =0; i< 4;i++){
			somme= t2[i];
		}
	}
	
	
	
		printf("%d",somme);
	
}

int main () {
	int t1[3] = {1,2,4};
	int t2[3] = {10,3,8};
	repeat(t1, t2);
}
