//mycat.c
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
int fd;
void filecopy(int, int);
if (argc == 1)
{
filecopy(STDIN_FILENO, STDOUT_FILENO);
}
else
{
while(--argc >0)
{
if ((fd = open(argv[1], O_RDONLY))<0)
{
printf("cat: can not open %s\n", argv[1]);
return 1;
}
else
{
filecopy(fd, STDOUT_FILENO);
close(fd);
}
}
}
return 0;
}
void filecopy(int ifp, int ofp)
{
ssize_t n;
unsigned char buf[1024];
while((n=read(ifp,buf,1024))>0)write(ofp,buf,n);
}
