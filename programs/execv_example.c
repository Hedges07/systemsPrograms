#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char * const av[] = { "ls","-l",(char *)0 };
	execv("/bin/ls", av);

	perror("execv failed");
	exit(1);
}

