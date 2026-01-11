#include <stdio.h>
#include <string.h>


int main(void){
	const char *s1 = "zello";
	const char *s2 = "wello";
	printf("The return value of strcmp() is: %d\n", strcmp(s1, s2));
	return 0;
}
