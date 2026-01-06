#include <stdio.h>
#include <stdlib.h>

char* s_gets(char* dst, int n){
	if(!dst)
		return NULL;
	char* res = fgets(dst, n, stdin);
	int i = 0;
	if(res){
		while(dst[i] != '\n' && dst[i] != '\0')
			++i;
		if(dst[i] == '\n')
			dst[i] = '\0';
		else{
			while(getchar() != '\n')
				continue;
		}
	}
	return res;
}

int main(void){
	char buf[10] = {0};
	s_gets(buf, 10);
	puts(buf);
	return 0;
}
