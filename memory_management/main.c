#include <stdio.h>


int main(void){
	register int a = 10;
	int *p = &a;
	printf("register int a is %d\n", a);
	return 0;
}
