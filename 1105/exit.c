#include<stdio.h>

static void my_exit1(void),
	    my_exit2(void);

int main(void){
	if(atexit(exit_handler1) !=0) perror("exit_handler 1등록할수없음");
	if(atexit(exit_handler2) !=0) perror("exit_handler 2등록할수없음");
	print("main 끝");
	exit(0);
}
static void exit_handler1(void){
	printf("첫번째 처리기");
}
static void exit_handler2(void){
	printf("두번째 처리기");
}
