/*  dict.h  header for data dictionary routines. */

#include <stdio.h>

struct dict_elem{
	char d_name[15];
	int d_start;
	int d_length;
	int d_type;
};

#define ERROR (-1)
#define SUCCESS 0

