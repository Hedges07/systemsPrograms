#include <stdio.h>

int copyfile(const char *f1, const char *f2){
    FILE *inf, *outf;
    int count = 0;

    if ((inf = fopen(f1,"r")) == NULL){
        return (-1);
    }

    if ((outf = fopen(f2, "w")) == NULL){
        return (-2);
    }
	fseek(inf,0, SEEK_END);
    count = ftell(inf);
    printf("Number of character is %d", count);

    int i = 1,c = 0;
    while(i <= count) {
        fseek(inf,-i, SEEK_END);
        c = fgetc(inf);
        putc(c,outf);
        i++;
    }


    fclose(inf);
    fclose(outf);
    return (0);
}

int main(int argc, char * argv[]){
    copyfile(argv[1], argv[2]);
}