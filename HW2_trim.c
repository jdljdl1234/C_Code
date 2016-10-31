#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

/* James Lantos, CS240, HW2, No. 1 											*/

/* This is a summary of key steps in a program which removes 				*/
/* blanks and tabs from the end of lines (before the EOF or /n) 			*/
/* which are read in from standard input, and which prints those lines 		*/
/* but doesnt print a line with just blanks/tabs 							*/
/* Basic code form has been adapted from K/R textbook code 					*/

/* ==== PSEUDOCODE: SUMMARY OF STEPS ============================= 			*/
/* 1. Read line into array.  												*/
/* 2. Step through the length of inputted line (while..)					*/
/* 2. 		Test for blanks/tabs. 											*/
/* 3. 		While blanks/tabs are found, keep going. No blanks/tabs,quit.	*/	
/* 4. 		If you find valid characters--then you have a line. 			*/
/* 5. 		Move to add trailing new line \n and \0; 						*/
/* 6. 		Otherwise if a line with just blanks/tab is 					*/
/*       		found .. do not print it. Go to retrieve next line.			*/

int mygetline(char line[], int maxline);

int main(void)
{
	int i, length; 							/* current line length */
	char line[MAXLINE];  					/* current input line */
	
    while ((length = mygetline(line, MAXLINE)) > 0) {  
        i = length - 2; 	/* Set i to be the length of line/array */
							/* excluding \n and \0			  		*/
	
	while (i >= 0 && (line[i] == ' ' || line[i] == '\t'))		
			--i;					
			if (i > 0) {				
										
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


#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int getline(char line[], int maxline);
void copy(char to[], char from[]);
/* print the longest input line */

main()
{
	int len; /* current line length */
	int max; /* maximum length seen so far */
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE]; /* longest line saved here */
	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
	if (len > max) {
	max = len;
	copy(longest, line);
	}

	if (max > 0) /* there was a line */
	printf("%s", longest);
	return 0;
}

/* getline: read a line into s, return length */

int getline(char s[],int lim)
{
	int c, i;
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
	s[i] = c;
	if (c == '\n') {
	s[i] = c;
	++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
	++i;
}