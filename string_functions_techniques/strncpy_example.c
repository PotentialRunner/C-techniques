#include <stdio.h>
#include <string.h>


int main(void){
	char buf[20] = {0};
	puts(strncpy(buf, "hello", sizeof(buf)));
	return 0;
}
