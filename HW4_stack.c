/* James Lantos, CS240, HW4 */
/* March 26 2013 */
/*
 * stack.c
 *
 * stack routines
 */

/* Program stack.c is part of the polish calculator program  			*/
/* Some code adapted from K/R textbook code 						*/
/* ..and code supplied by professor 								*/

/* ===== PSEUDO CODE ======											*/
/*  push - push the next value onto the stack array 				*/
/*  pop - get the first value back from the stack array				*/

#include <stdio.h>
#include "calc.h"
#define MAXVAL 100  /* maximum depth of val stack */

/* even better, we could make the following two defines "static"
   and thus hide these data structures from the rest of the sources */
static int sp = 0;         /* next free stack position */
static int val[MAXVAL]; /* value stack */


/* push: push f onto value stack */
void push(int f)
{
    if (sp < MAXVAL)
	val[sp++] = f;
    else
	printf("error: stack full, can't push %d\n", f);
}

/* pop: pop and return top value from stack */

int pop(void)
{
    if (sp > 0)
	return val[--sp];
    else
      {
	printf("error: stack empty\n");
	return 0;
      }
}

