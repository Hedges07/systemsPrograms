#include "dict.h"

int writedict(const char *dictname, struct dict_elem *elist){

	int j;
	FILE *outf;

	if ((outf = fopen(dictname, "w")) == NULL){
		return ERROR;
	}

	for (j = 0; elist[j].d_length != 0; j++)
		;

	if (fwrite((void*)elist, sizeof(struct dict_elem), j, outf)<j){
		fclose(outf);
		return ERROR;
	}


	fclose(outf);
	return SUCCESS;
}

//**************************************************************************


struct dict_elem * readdict(const char *dictname, 
  				     struct dict_elem *inlist, int maxlength)
{

	int i;
	FILE *inf;

	if ((inf = fopen(dictname, "r")) == NULL){
		return NULL;
	}

	for (i = 0; i < maxlength - 1; i++)
	{
		if (fread((void*)&inlist[i], sizeof(struct dict_elem), 1, inf)<1)
		{
			break;
		}
	}


	fclose(inf);

	inlist[i].d_length = 0;

	return inlist;
}


// your main function goes here.
int main(void)
{

struct dict_elem array[3] ={   {}, {},{} , {}  }




}
