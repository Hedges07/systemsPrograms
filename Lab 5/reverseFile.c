#include<stdio.h>
#include<sys/file.h>

int main(int argc, char *argv[]){
    char c;
    if(argc !=3) {
        printf("Call model: reverseFile <inputFileName> <outputFileName>\n");
        return 0;
    }

    int inf = open(argv[1], O_RDONLY);
    int outf = open(argv[2], O_WRONLY | O_CREAT, 0666);

    if(inf<0){
        printf("%s cannot be opened",argv[1]);
    }  
    
    if(outf<0){
        printf("%s is not found, or cannot be created",argv[2]);
    }


    int fileLength=lseek(inf,0,SEEK_END);

    for(int i=fileLength-1; i >= 0; i--){
        lseek(inf,i,SEEK_SET);
        read(inf,&c,1);
        write(outf,&c,1);
    }
    close(inf);
    close(outf);
    return 0;
}