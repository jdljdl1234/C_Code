/* James Lantos, CS240, HW4 */
/* March 26 2013 */
/* 
 * getop.c
 *
 * gets next token: operator or numeric operand
 */

/* Program getop.c is part of the polish calculator program  			*/
/* Some code adapted from K/R textbook code 						*/
/* ..and code supplied by professor 								*/

/* ===== PSEUDO CODE ======											*/
/*  while (get the operators and operands )							*/
/*  select the correct case 										*/
/*  	push and pop from stack as appropriate as per code			*/
/*  print out answer or error										*/

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
	;

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
      return c;  /* not a number */

    /* collect integer part in string s */
    i = 0;
    if (isdigit(c))
      while (isdigit(s[++i] = c = getch()))
	    ;

    /* collect fractional part in string s */
    if (c == '.')
      while (isdigit(s[++i] = c = getch()))
	;
    
    s[i] = '\0';
    if (c != EOF)
      ungetch(c);
    
    return NUMBER;
}


