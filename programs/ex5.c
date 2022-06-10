//ex5.c
#include <stdio.h>

int main(int argc, char *argv[]) {
	  FILE *f;
	  int c;

	  f=fopen(argv[1], "w");  

	  while((c=getchar()) != EOF)
		fputc(c, f);
	  
          fclose(f);   //do I need this sentence or not? ctl+D   
}

