/* James Lantos, CS240, HW5 */
/* April 14, 2013 */
/*
 * tail.c
 *
 *
 */

 // interprets the command line argument
 // calls init_lineholder (int nlines) with the number from the command line
 // does a loop calling getline and insert_line(char *line)
 // When getline returns 0 (indicating EOF on stdin), it calls print_lines()
 // delete_array - frees up memory

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 2000
#define MAXLINE 1000

main (int argc, char *argv[ ])
{  
	int i;
	char *ptr;
	char line[MAXLINE];
	int nlines = MAXLINES;
	nlines = atoi(argv[1]);
    nlines = -nlines; 

  while(mygetline(line, MAXLINE)) {
	    ptr = init_lineholder(line);
        strcpy(ptr, line);
		insert_line(ptr, nlines);	
	}
		print_lines(nlines);
 		delete_array(nlines);
}

