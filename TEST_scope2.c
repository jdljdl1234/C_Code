/* Scope of Variables -Example 2 */
#include <stdio.h>
int main(){
  int x=10;
  printf("x=%d\n", x);
  {
     int x=5;
     printf("x=%d\n", x);
     {
         int x=40;
         printf("x=%d\n",x);
      }
       x=x+4;
       printf("x=%d\n",x);
   }
   x=x+15;
   printf("x=%d\n",x);
   return 0;
}
