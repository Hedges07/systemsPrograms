#include <stdio.h>

int copyfile(const char *f1, const char *f2){
    FILE *inf, *outf;
    int c = 0;
    int d = 0;  //the character currently read, d will be used to not overwrite c

    if ((inf = fopen(f1,"r")) == NULL){
        return (-1);
    }

    if ((outf = fopen(f2, "w")) == NULL){
        fclose(inf);
        return (-2);
    }

    while ((c=getc(inf)) != EOF){
        if(c == '\n'){
            fprintf(outf,"New line found\n");
        }
        if(c == ','){
            fprintf(outf,"comma found\n");
        }
        if(c == '/') {
            if((d = getc(inf) != EOF)){ //populate d instead of c incase we dont want to read c
                if(d =='/') {
                    c = d;
                    fprintf(outf,"Double slashes found\n");
                }
                if(d == '*') {
                    c = d;
                    fprintf(outf,"Block comment found\n");
                }
            }
        }
        if(c == '*') {
            putc(c, outf);
            if((c = getc(inf)) != EOF){
                if(c =='/') {
                    fprintf(outf,"Block comment ended\n");
                }
                else{
                    c = ungetc(c,inf);
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