/* James Lantos, CS240, HW4 */
/* March 26 2013 */
/*
 * main.c
 *
 * reverse polish calculator
 */

/* Program main is part of the polish calculator program  			*/
/* Some code adapted from K/R textbook code 						*/
/* ..and code supplied by professor 								*/

/* ===== PSEUDO CODE ======											*/
/*  while (get the operators and operands )							*/
/*  select the correct case 										*/
/*  	push and pop from stack as appropriate as per code			*/
/*  print out answer or error										*/

#include <stdio.h>
#include "calc.h" /* header file */
#include <math.h>
#include <stdlib.h>

#define MAXOP 100

main()
{
  int type;
  int op2, op3, op4;
  char s[MAXOP];
  
  while ((type = getop(s)) != EOF) 
    {
      switch(type) 
	{
	case NUMBER:
	  push(atoi(s));
	  break;
	case '+':
	  push(pop() + pop());
	  break;
	case '*':
	  push(pop() * pop());
	  break;
	case '-':
	  op2 = pop();
	  push(pop() - op2);
	  break;
	case '/':
	  op2 = pop();
	  if (op2 != 0.0)
	    push(pop() / op2);
	  else 
	    {
	      printf("error : zero divisor\n");
	      exit(1);
	    }
	  break;
	  case '^':
	  push(pop() ^ pop());
	  break;
	case '%':
	  op3 = pop();
	  push(pop() % op3);
	  break;
	case '~':
	  op4 = pop();
	  push(~op4);
	  break;
		
	case '\n':
	  printf("The answer is %8d\n", pop());
	  break;
	default:
	  printf("error: unknown command %s\n", s);
	  exit(1);
	}
    }
}
