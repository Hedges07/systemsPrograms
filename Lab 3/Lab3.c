#include <stdio.h>

int copyfile(const char *f1, const char *f2){
    FILE *inf, *outf;
    int c = 0;

    if ((inf = fopen(f1,"r")) == NULL){
        return (-1);
    }

    if ((outf = fopen(f2, "w")) == NULL){
        fclose(inf);
        return (-2);
    }
	int flag1,flag2,d=0;

    while ((c=getc(inf)) != EOF){
        if(c == '\n'){
            fprintf(outf," //End of line has been found");
        }
        if(c == ','){
            fprintf(outf," comma found");
        }
        if(c == '/') {
			fprintf(outf,"%c",c);
			if(c = getc(inf) != EOF) {
				if(c == '/') {
					fprintf(outf, "Comment");
				}
			}
		}
			
        fprintf(outf,"%c",c);
    }

    fclose(inf);
    fclose(outf);

    return (0);
}

int main(int argc, char * argv[]){
    copyfile(argv[1], argv[2]);
}