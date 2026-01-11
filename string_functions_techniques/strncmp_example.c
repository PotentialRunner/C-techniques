#include <stdio.h>
#include <string.h>


int main(void){
	const char *s1 = "zello";
	const char *s2 = "wello";
	printf("The return value of strcmp() is: %d\n", strncmp(s1, s2, strlen(s1)));
	return 0;
}
