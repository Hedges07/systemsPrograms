//**************************************************************************************************************************************************
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

#define BUFSIZE 512

int main(int argc, char *argv[])
{
	char buffer[BUFSIZE];

	int filedes;
	ssize_t nread;
	long total = 0;

	if ((filedes = open("filesize.c", O_RDONLY)) == -1)
	{
		printf("error in openning anotherfile\n");
		exit(1);
	}

	//loop until end of file
	while ((nread = read(filedes, buffer, BUFSIZE)) > 0)
	{
		total += nread; //increment total
	}

	printf("total chars in anotherfile: %d\n", total);

	exit(0);
}

