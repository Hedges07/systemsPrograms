//copy file f1 to f2 using standard I/O

#include<stdio.h>

int copyfile(const char *f1, const char *f2)
{
	FILE *inf, *outf;
	int c;

	if ((inf = fopen(f1,"r")) == NULL)
	{
		return (-1);
	}

	if ((outf = fopen(f2, "w")) == NULL)
	{
		fclose(inf);
		return (-2);
	}


	while ((c=getc(inf)) != EOF)
	{
		putc(c, outf);
	}

	fclose(inf);
	fclose(outf);

	return (0);
}

int main(int argc, char * argv[])
{
	copyfile(argv[1], argv[2]);
}
