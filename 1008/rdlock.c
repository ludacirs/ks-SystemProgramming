#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[]){
	int fd, id;
	struct student record;
	struct flock lock;

	if (argc <2){
		fprintf(stderr, "사용법 : %s 파일\n", argv[0] );
		exit(1);
	}
	if((fd = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		exit(2);
	}

	printf("\n검색할 학생의 학번 입력:");
	while(scanf("%d", &id) == 1){
		lock.l_type = F_RDLCK;
		lock.l_whence = SEEK_SET;
		lock.l_start = (id-START_ID)*sizeof(record);
		lock.l_len = sizeof(record);

		if(fcntl(fd,F_SETLKW, &lock) == -1){
			perror(argv[1]);
			exit(3);
		}
	}
}