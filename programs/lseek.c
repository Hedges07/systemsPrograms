#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>
#include <stdlib.h>

static void error(int exitc,int errn,const char* fmt,...){
    va_list list;
    va_start(list,fmt);
    vfprintf(stderr,fmt,list);
    va_end(list);
    if(errn)
        fprintf(stderr,": %s",strerror(errn));
    fprintf(stderr,"\n");
    if(exitc)
        exit(exitc);
}


int main(int argc,char** argv){
    if(argc==1)
        error(1,0,"Usage: %s <file>",argv[0]);
    int fd = openat(AT_FDCWD,argv[1],O_RDONLY); // I never use raw `open` syscalls, except with absolute paths
    if(fd<0)
        error(1,errno,"Could not open %s for reading",argv[1]);
    off_t size = lseek(fd,0,SEEK_END);
    if(size<0)
        error(1,errno,"Could not seek to end of %s",argv[1]);
    printf("Size of %s: %" PRIdMAX "\n",argv[1],(intmax_t)size); // No portable way to format off_t, need to cast to intmax_t and use PRIdMAX
    close(fd);
}
