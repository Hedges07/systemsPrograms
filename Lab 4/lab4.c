#include <stdio.h>

int main(){
    FILE *inf;
    int count;
    if ((inf = fopen("a.txt", "r")) == NULL){
        return (-1);
    }
    fseek(inf,0, SEEK_END);
    count = ftell(inf);
    fclose(inf);
    printf("Number of character is %d", count);
}