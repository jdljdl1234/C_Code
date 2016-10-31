#include <stdio.h>

#define MAXLINE 1000

/* James Lantos, CS240, HW2, No. 2 												*/

/* This is a summary of steps in a program which reads lines 					*/
/* froms stdin and writes reversed lines to stdout until it encounters an EOF. */
/* Basic code form has been adapted from K/R textbook code 						*/

/* ==== PSEUDOCODE: SUMMARY OF STEPS ============================= 				*/
/* Read the new line in 														*/
/* Copy the line to an array 													*/
/* Reverse the order of the characters in the line 								*/
/* Print out the reversed line 													*/

int mygetline(char s[], int max);
void reverse(char s[]);

int main(void)
{
    int length;							
    char line[MAXLINE];							

    while ((length = mygetline(line, MAXLINE)) != 0) {    /* get the line set return length value */
        if (length > 1) {								/* is there more than 1 char? */
            reverse(line);								/* if so, reverse the chars */
            printf("%s\n", line);						/* print the reversed line */
        }
    }

    return 0;
}

int mygetline(char s[], int max) {					
    int i, c;										
    for (i=0; i<max-1 && (c=getchar())!=EOF && c!='\n'; ++i) {  
        s[i] = c;									
    }
    if (c == '\n') {								/* if you read end of line char... */
        s[i] = c;									/* store end of line in array */
        ++i;										/* increment array position */
    }
    s[i] = '\0';									/* add trailing /0 to mark end of array */
    return i;
}

void reverse(char s[]) {							 /* perform reverse character method */
    int in, out;
    char holder;

    for (out = 0; s[out] != '\0'; ++out)
	; 												/* do nothing while you build up value of out */
    out--;											/*  decrement out */ 

    if (s[out] == '\n') {
        s[out] = '\0';
        out--;
    }

    for (in = 0; in < out; in++) {					/* perform character switch */
        holder = s[in];
        s[in] = s[out];
        s[out] = holder;
        out--;
    }
}