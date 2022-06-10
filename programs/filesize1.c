//filesize1.c
#include <stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]){  
	FILE *fd;
	
	//unsigned char ch;  //what will happen if you uncomment this line and comment the 		//next line
        char ch;

	int fileSize=-1;

	fd = fopen(argv[1], "r");  

	do{
		ch=getc(fd);  //0xFF
		fileSize++;
	//	printf("fileSize=%d\n", fileSize);
	//	printf("ch=%x EOF=%#x\n", ch, EOF);
	//	sleep(1);
	} while( ch != EOF);  //ch =0x FF, 0x FF FF   EOF=0x FFFF
	
	printf("ch=%d EOF=%#x\n", ch, EOF);
	printf("size of char =%ld size of EOF=%ld\n", sizeof(char), sizeof(EOF));
	
	printf("Size of %s is %d\n", argv[1], fileSize);
}

