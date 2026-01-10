#include <stdio.h>
#include <string.h>

#define SIZE 15

int main(void){
	
	char buf1[SIZE] = "hello, ";
	char buf2[] = "world!djaskldjalskjksajdlkajsdl";

	unsigned int available = SIZE - strlen(buf1) - 1;
	const char *res = strncat(buf1, buf2, available); 
	puts(res);
	return 0;
}
