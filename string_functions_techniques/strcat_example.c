#include <stdio.h>
#include <string.h>

#define SIZE 15

int main(void){
	char str1[SIZE] = "hello, ";
	char str2[] = "world!";
	if (strlen(str1) + strlen(str2) + 1 <= SIZE){
		const char *res = strcat(str1, str2);
		puts(res);
	}else 
		puts("The memory space is not sufficient!");
	return 0;
}
