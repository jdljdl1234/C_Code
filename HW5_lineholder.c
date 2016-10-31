/* James Lantos, CS240, HW5 */
/* April 14, 2013 */
/*
 * lineholder.c
 *
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 
#define MAXLINES 2000
#define MAXLINE 1000

 
static char *ptrarray[MAXLINES];
static int loop;
static char *ptrtemp;


// take the current line from getline and allocates space for it with malloc

char * init_lineholder(char *a) {

	
	ptrtemp = (char *) malloc(strlen(a)+1);
	if (!ptrtemp) {
			fprintf(stderr, "Out of memory\n");
			return NULL;
	}
	return ptrtemp;
}	

// takes the malloc'd line, puts it in  ptrarray
// if you have cycled past the "-n" value (loop), set index value to 0
// free up the first value, and so forth


void insert_line(char *y, int z) {     
   static int index;
	
   if(ptrarray[index]) {
    if (loop)	
		{	
			free(ptrarray[index]);
			ptrarray[index] = NULL;
		}
    }
   ptrarray[index] = y;
   index++;
	
   
   // printf("%d\n", index); 
	if (index >= z) {
      index = 0;
	  loop++;
	}
}	

// print the -n lines from the array 

void print_lines(int q)
{
   int i;
   	for (i=0; i < q && ptrarray[i] != NULL; i++)  
	printf("%s\n", ptrarray[i]);
   
}

// free the memory

void delete_array(int q)
{
  int i;
  for (i = 0; i < q && ptrarray[i] != NULL; i++)   
	free(ptrarray[i]);
}

int mygetline(char s[], int lim)
{
   int c, i;
   i = 0;
   while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
      s[i++] = c;
    if (c == '\n')
      s[i++] = c;
    s[i] = '\0';
    return i;
}

