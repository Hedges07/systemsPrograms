#include<stdio.h>

int copyfile(const char *f1, const char *f2) {
	FILE *inf, *outf;
	int c;

	if ((inf = fopen(f1,"r")) == NULL){
		return (-1);
	}

	if ((outf = fopen(f2, "w")) == NULL) {
		fclose(inf);
		return (-2);
	}

	int flag1=0,flag2=0;
	int flag3=0,flag4=0;

	while ((c=getc(inf)) != EOF){
		if(flag1 == 0 && c == '/') {
			flag1 = 1;
		}
		else if(flag1 == 1 && c == '/') {
			flag2 = 1;
		}
		else if(flag1 == 1){
			flag1 = 0;
		}
		else{
			flag1 = 0;
			flag2 = 0;
			putc(c, outf);
		}
		if (flag2 == 1) {
			commentState(inf,outf);
			flag2 = 0;
		}

		//Block comments 
		
		if(flag3 == 0 && c =='/') {
			flag3 = 1;
		}
		else if(flag3 == 1 && c == '*') {
			flag4 =1;
		}
		else if(flag3 ==1) {
			flag3 = 0;
		}
		else{
			flag3 = 0;
			flag4 = 0;
		}
		if(flag4 == 1) {
			blockState(inf);
			flag4 = 0;
		}
	}

	fclose(inf);
	fclose(outf);

	return (0);
}

int main(int argc, char * argv[]){
	copyfile(argv[1], argv[2]);
}

void commentState(FILE* inf,FILE* outf){ 
	int c = 0; 
	while((c=getc(inf)) != '\n');
	fprintf(outf,"\n");
}

void blockState(FILE* inf) {
	int c = 0; 
	int flag1=0,flag2=0;
	while(flag1 != 1 && (c=getc(inf)) != '/') {
		if(flag1 == 0 && c == '*') {
			flag1 = 1;
		}
	}
}