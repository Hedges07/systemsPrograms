//******************************************

#include<stdio.h>
#include<ctype.h>

#define YES 1
#define NO 0
#define ANSWERZ 80

static char *pdefault = "Type 'y' for YES, 'n' for NO";
static char *error = "unexpected repsonse";

int yesno(char *prompt)
{
	char buf[ANSWERZ], *p_use, *p;
	p_use = (prompt != NULL) ? prompt : pdefault;

	for (;;)
	{
		printf("%s >", p_use);

		if (fgets(buf, ANSWERZ, stdin) == NULL)
			return EOF;

		for (p = buf; isspace(*p); p++)
			;

		switch (*p)
		{
		case'Y':
		case'y':
			return (YES);
		case 'N':
		case 'n':
			return (NO);
		default:
			printf("/n%s/n", error);
		}
	}
}

int main(int argc, char *argv[]) {

	printf("%d",yesno("My personal prompt:"));


}

