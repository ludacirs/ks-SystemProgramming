#include<stdio.h>
#include<stdlib.h>
int main(){
	printf("부모 프로세스 시작\n");
	if(fork() ==0){
		execl("/bin/echo", "echo", "hello", NULL);
		fprintf(stderr, "첫번째 실패\n");
		exit(1);
	}

	printf("부모 프로세스 끝\n");
}