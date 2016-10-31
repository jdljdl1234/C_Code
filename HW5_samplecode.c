
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000
#define MAX_BUFFER 10

char *ptr_array[MAX_BUFFER];
void insert_line(char *);
int mygetline(char s[], int lim);
void print_lines(char** ptr);


main (int argc, char *argv[ ])
{
  int c, number = 0;
  
  int i, optn;
  char * ptr;
  char line[MAXLINE];
  char * temp_ptr_array[MAX_BUFFER];
        
/* code to enter data */
  
  while(mygetline(line, MAXLINE)){
        ptr = (char *) malloc(strlen(line +1));
	
		printf("%p\n", ptr);
        strcpy(ptr, line);
        insert_line(ptr);
 }
/* print customer data */
  for (i = 0; i < MAX_BUFFER; i++)
        temp_ptr_array[i] = ptr_array[i];
  
  print_lines(temp_ptr_array);
        
}
/* function to update the buffer with new customer data */
void insert_line(char * y)
{
   static int new_index;

   if(ptr_array[new_index])
   {
      free(ptr_array[new_index]);
      ptr_array[new_index] = NULL;
   }
   ptr_array[new_index] = y;
   new_index ++;
    printf("%d\n", new_index);
   if (new_index >= MAX_BUFFER)
       
      new_index = 0;
}

/* function to print data */
void print_lines(char **ptr)
{
  int i,j;
  char * temp;
  for (i = 0; i < MAX_BUFFER && ptr[i] != NULL ; i++)
     printf("%s", ptr[i]);
}

/* function to get a line */
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