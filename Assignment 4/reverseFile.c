#include <stdio.h>
#include <sys/file.h>

int main(int argc, char *argv[]) {
    if (argc != 3){
        printf("Call model: reverseFile <inputFileName> <outputFileName>\n");
        return 0;
    }

    int inf = open(argv[1], O_RDWR);
    int outf = open(argv[2], O_WRONLY | O_CREAT, 0666);
    
    if (inf < 0){
        printf("%s cannot be opened", argv[1]);
    }
    if (outf < 0){
        printf("%s is not found, or cannot be created", argv[2]);
    }

    int characters = lseek(inf, 0, SEEK_END);
    write(inf,"\n",1);
    int var;
    char buffer;
    char end = characters;
    char lineBuffer[100];

    for(int i = characters-1; i >= 0; i--) {
        lseek(inf, i, SEEK_SET);
        read(inf, &buffer, 1);
        if (buffer == '\n' | buffer == '\0') {
            var = i - 1;
            read(inf, lineBuffer, end - var);
            write(outf, lineBuffer, end - var);
            end = var;
        }
    }

    lseek(inf, 0, SEEK_SET);
    read(inf, lineBuffer, end);
    write(outf, lineBuffer, end);
    close(inf);
    close(outf);

    return 0;
}