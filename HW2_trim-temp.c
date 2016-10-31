#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

/* James Lantos, CS240, HW2, No. 1 */

/* This is a summary of key steps in a program which removes */
/* blanks and tabs from the end of lines (before the EOF or /n) */
/* which are read in from standard input, and which prints those lines */
/* but doesnt print a line with just blanks/tabs */
/* Basic code form has been adapted from K/R textbook code */

/* ==== SUMMARY OF STEPS ==== */
/* 1. Step through the length of line. */
/* 2. Test for blanks/tabs. */
/* 3. If blanks/tabs are found, decrement i. */	
/* 4. If another character is encountered other than 
/*        blanks/tabs, quit while loop. */
/* 5. Test to see if there is a line with characters; */
/* 6. If so move to add trailing new line \n and \0; */
/* 7. Otherwise if i=0, a line with just blanks/tab is */
/*       found .. do not print it */

int mygetline(char line[], int maxline);

int main(void)
{
	int i, length; 							/* current line length */
	char line[MAXLINE];  					/* current input line */
	
    while ((length = mygetline(line, MAXLINE)) > 0) {  
        i = length - 2; 	/* Set i to be the length of line/array */
							/* excluding \n and \0			  */
	
	while (i >= 0 && (line[i] == ' ' || line[i] == '\t'))		
			--i;						/* if you find a blank or tab, decrement i */
			if (i > 0) {				/* if the line contains any non blank/tab characters  */
										/*    add new line /n and trailing /0 */ 
			line[i+1] = '\n';		
            line[i+2] = '\0';
            printf("%s", line);			/*  ..and print the line */
		}						       
	}
	return 0;
}

/* mygetline: read a line into char [s] and return length */
int mygetline(char s[], int lim)
{ 
	int c, i;
	
	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) /* read from stdin */
		s[i] = c;							/* copy the characters into the array */
		
	if (c == '\n') {						/* if new line char reached.. */
		s[i] = c;							/* copy to array */
		++i;								/* increment i */
	}
	s[i] = '\0';							/* copy null string - mark end of array  */
	return i;								/* length of the line/array is the return value */
}



