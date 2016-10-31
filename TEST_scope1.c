/* Scope of variables- Example 1 */
#include <stdio.h>
int main(){
  int a=10;
  printf("a=%d\n", a);
  {
     int b=5;
     printf("b=%d\n", b);
     {
         int c=40;
         printf("c=%d\n",c);
      }
   }
   return 0;
}
