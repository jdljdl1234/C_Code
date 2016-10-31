
/* James Lantos, CS240, HW3, No. 2a Integer -> Dec to Hex Conversion  	*/
/* March 9 2013 */
/* showxbits.c 	*/

/* Program main takes integer values and converts to hex 	 		*/
/* Some code adapted from K/R textbook code 						*/
/* ..and code supplied by professor 								*/

/* ===== PSEUDO CODE ======											*/
/*  Read from scanf input variables(works for !> than ENOUGH_SPACE)	*/
/*  hexstring and hexstring1 array size set to ENOUGH_SPACE 		*/
/*  itox does integer to hex conversion								*/
/*  reverse - reverses string chars in array						*/
/*  xtoi does hex to decimal conversion								*/
/*  Print result 													*/	

#include <stdio.h>
#include "xbits.h"


int main() {

    char hexstring[ENOUGH_SPACE];
    char hexstring1[ENOUGH_SPACE];
	int n;
	
	while(scanf("%d", &n)==1) {
	int m=0;
	
	itox(hexstring, n);  
	reverse(hexstring, ENOUGH_SPACE);
	printf("Integer: %d equals hex string: %s\n", n, hexstring);
	printf("The %%x representation of %%d string matches: %x\n", n);
	
	strcpy(hexstring1, hexstring);
    m= xtoi(hexstring1, ENOUGH_SPACE);

	printf("Hexstring: %s equals original decimal value %d\n\n", hexstring1, m);

}
  return 0;  /* everything is just fine */
}

