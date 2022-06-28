#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main() {
	srand(time(NULL));	//設定亂數種子
	unsigned int a = rand()%10;
	unsigned int b = rand()%10;
	unsigned int c = rand()%10;
	int count = 0;
	// printf("%d, %d\n", a, RAND_MAX);
	while(count <= 66){
		if(a+b+c==10)	count++;
		else	continue;
	}
}