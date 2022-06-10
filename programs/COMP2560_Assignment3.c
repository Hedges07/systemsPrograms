
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
char msg[50];
void childFunction(char *line);
int main(void) {
	strcpy(msg,"This program makes simple arithmetics\n");
	char ch;
	int i = 0;
	int pid;
	int status;
	write(1,msg,strlen(msg));
	for(;;){
		char line[100] = "";
		strcpy(msg,"Enter an arithmetic statement, e.g., 34 + 132 >");
		write(1,msg,strlen(msg));
		read(0,line,sizeof(line));
	//	printf("%s \n",line);
		pid = fork();
		if(pid < 0){
			perror("error happened during creating child process");
			exit(1);
		}
		if(pid == 0){
			//child doing
		//	printf("%s",line);
			childFunction(line);

		} else{
			//parent
			strcpy(msg,"Created a child to make your operation, waiting\n");
			write(1,msg,strlen(msg));
			wait(&status);
			if(WIFEXITED(status)){
				if(WEXITSTATUS(status) == 50){
					strcpy(msg,"Wrong statement\n");
					write(1,msg,strlen(msg));
				}else if(WEXITSTATUS(status) == 100){
					strcpy(msg,"Division by zero\n");
					write(1,msg,strlen(msg));
				}else if(WEXITSTATUS(status) == 200){
					strcpy(msg,"Wrong operator\n");
					write(1,msg,strlen(msg));
				}
			}
		}
	}
	//printf("%s",line);
}
void childFunction(char *line){
	int x,y,r;
	float cal;
	char operator;
	char result[100];
	strcpy(msg,"I am a child working for my parent\n");
	write(1,msg,strlen(msg));
//	write(1,line,strlen(line));
//	printf("value are %d %c %d\n",x,operator,y);
	r = sscanf(line,"%d %c %d",&x,&operator,&y);
//	printf("values are %d %c %d\n",x,operator,y);
//	printf("value of r is :%d\n",r);
	//printf("we did it! %d %c %d",x,operator,y);
	if(r != 3)
		exit(50);
	if(operator == '/' && y == 0)
		exit(100);
	if(operator != '+' && operator != '-' && operator != '*' && operator != '/')
		exit(200);
	if(operator == '+')
		cal =(float) x + y;
	else if(operator == '-')
		cal =(float) x - y;
	else if(operator == '*')
		cal =(float) x * y;
	else
		cal =(float) x / y;
	sprintf(result,"%d %c %d = %.2f\n",x,operator,y,cal);
	write(1,result,strlen(result));
	exit(0);
}
