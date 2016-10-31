/* James Lantos, CS240, HW4 */
/* March 26 2013 */
/*
 * getch.c
 *
 * getch  returns one  character from stdin 
 * or from the buffer buf if it is not empty
 * ungetch puts one character in the buffer buf 
 */

/* Program getch.c is part of the polish calculator program  			*/
/* Some code adapted from K/R textbook code 						*/
/* ..and code supplied by professor 								*/

/* ===== PSEUDO CODE ======											*/
/*  getch / ungetch tests for maxing out size of the buffer (BUFSIZE) */


#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];        /* buffer for ungetch */
int  bufp = 0;            /* next free position in buf */

int getch(void)           /* get a (possibly pushed back) character */
{
    return(bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)        /* push character back on input */
{
    if (bufp >= BUFSIZE)
	printf("ungetch: too many character \n");
    else
	buf[bufp++] = c;
}
