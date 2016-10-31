/* explore.c: program to explore memory locations via pointers
   bob wilson
   03/13/2003
   modified by Ron Cheung 7/8/2003
   */
   
/* James Lantos, CS240, HW5 */
/* April 11, 2013 */
/* Note: I used different combinations of %x,%d and %p to test output */

#include <stdio.h>

int a = 0x13579753;
static int b = 0x24680864;

void foobar(int, int, int *, int *);
 
int main(void) 
{
	static int c = 0xaaaa5555;
	int d = 0x5555aaaa;
	int *ap = &a;
	int *bp = &b;
	int *cp = &c;
	int *dp = &d;
	int array[1] = {0x01010101};

/* add code here to print the address of array[0]  */

printf("Address of automatic variable array[0]:%x\n", &array[0]);
printf("Address of automatic variable array[1]:%x\n", &array[1]);

/* add code here to print the variables a, b, c, d and pointers  */

printf("\nPrinting variables: a, b, c, d...\n");
printf("(Note: automatic variables are c, d)\n");
printf("%9x %9x %9x %9x\n\n", a, b, c, d);

printf("\nPrinting pointers (automatic variables): *ap, *bp, *cp, *dp...\n"); 
printf("%9p %9p %9p %9p\n", *ap, *bp, *cp, *dp);


/* add code here to print array[i] for i = 0 to high enough value */

printf("\n\nPrinting array values...\n"); 
int i;
for (i=0; i<6; i++)
	printf("array[%d] %p (ptr)array(%d) %p\n", i, &array[i], i,(*array+i));
printf("\n\n");
	


/* call subroutine foobar and pass arguments  */
	foobar(a, d, &a, &d);

	return;
}

void foobar(int x, int y, int *xp, int *yp)
{
	int array[1] = {0x10101010};
	
	printf("Entering foobar\n");

/* add code here to print address of array[0]  */

printf("Printing auto variable array address...\n");
printf("array[0] %p\n", &array[0]);
	

/* add code here to print array[i] for i = 0 to high enough value */

printf("\nPrinting array value...\n");
int i;
for (i=0; i<45; i++)
	printf("array[%d] %p\n", i,&array[i]);

	return;
}

