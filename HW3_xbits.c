/* James Lantos, CS240, HW3, No. 2a Integer -> Dec to Hex Conversion  	*/
/* March 9 2013 */
/* xbits.c 	*/

/* Program has functions called from main to take integer value		*/
/* 	 and converts to  hex string 									*/
/* Some code adapted from K/R textbook code 						*/
/* ..and code supplied by professor 								*/

/*  itox function   							 					*/
/*  initialize variables			 							*/
/*  while 							 							*/
/*     	cycle integer through n%16 remainder calcs until n < 15	*/
/* 		declare hexstring array items = i++ values  			*/
/*      set hesxtring array elements to hexvalue array elements */
/* 		while 													*/
/*  		once done, if any space left in array, fill with zeros */

/* 	reverse function	 										*/
/* 	perform string reversal 									*/

/*  xtoi function   							 				*/
/*  initialize variables			 							*/
/*  while 							 							*/
/*     	cycle through each value in the hex string 				*/
/* 		perform multiplier algorithm on each as per professor  	*/
/*      call power function to perform expoential conversions  	*/
/* 		sum up the decimal value of each converted hex value 	*/
/* 		return the sum value to main 							*/


#include <stdio.h>
#include "xbits.h"


void itox(char hexstring[], int n) { 

   printf("\n...in itox, processing %d\n",n);
    int i=0;
    char hexvalues[16] =  {"0123456789ABCDEF"};
	hexstring[i]= 0x00;
    i++;        
    while (n>15) {
          hexstring[i]=hexvalues[n%16];
          n=n/16;
		  i++;
          }
		hexstring[i] = hexvalues[n%16];
		while (i != ENOUGH_SPACE) {
		hexstring[++i] = 0x30;		
	}
}

int xtoi(char hexstring1[], int s) { 

   printf("\n...in xtoi, processing %s\n",hexstring1);
    int i=s-2, j=0, k=0;
	while (k < s) {
		if (k==0)
		j += (hexstring1[i]-'0');
		else {
			if (hexstring1[i] >= '0' && hexstring1[i] <= '9')
			j+= ((hexstring1[i]-'0')*power(16,k));
				else 
					switch (hexstring1[i]) {
					case 'A': j+= (10*power(16,k));
						break;
					case 'B': j+= (11*power(16,k));
						break;
					case 'C': j+= (12*power(16,k));
						break;
					case 'D': j+= (13*power(16,k));
						break;
					case 'E': j+= (14*power(16,k));
						break;
					case 'F': j+= (15*power(16,k));
					default:
						break;
					}
			}
		  i--;
		  k++;
		  }
	      return j;
}
	

/* reverse: reverse's characters; from HW2 */

void reverse(char s[], int n) {							 
    int in, out=n-1;
    char holder;

    for (in = 0; in < out; in++) {					
        holder = s[in];
        s[in] = s[out];
        s[out] = holder;
        out--;
    }
}


/* power: raise base to nth power; n>=0 from K/R */

int power(int base, int n)
{
	int p;
		
	for (p=1; n>0; --n)
		p=p*base;
	return p;
}

