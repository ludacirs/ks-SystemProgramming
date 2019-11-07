#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int num;
	num = atoi(argv[1]);

	printf("Hello\n");
	sleep(num);
	printf("Bye\n");


	return 0;
}

