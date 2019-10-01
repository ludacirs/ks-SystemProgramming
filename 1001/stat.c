#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	struct stat buf;

	if(stat(argv[1], &buf) ==-1){
	perror("stat");
	return 1;
	}

	printf("i-node number : %ld\n", (long)buf.st_ino);
	printf("Link count : %ld\n",(long)buf.st_nlink);
	printf("UID : %ld GID : %ld\n", (long)buf.st_uid, (long)buf.st_gid);

	return 0;
}

