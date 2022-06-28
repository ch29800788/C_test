#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetMemory(char **p,int num) {
	*p=(char *)malloc(num);//这段代码后面未进行内存申明成功的判断
}
void main() {
	char *str=NULL;
	GetMemory(&str,100);
	strcpy(str,"hello");
	printf("%s\n", str);
}