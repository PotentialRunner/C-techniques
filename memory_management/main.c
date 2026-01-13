#include <stdio.h>
#include <stdlib.h>

int main(void){
	int *p = (int*)malloc(sizeof(int));
	*p = 10;
	printf("%d\n", *p);
	free(p);
	return 0;
}
