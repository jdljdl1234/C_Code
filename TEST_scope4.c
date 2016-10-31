/* scope of variables - Example 4 */
#include <stdio.h>
void func1(void); 
void func2(void); 
int main(){
  int x=5;
  printf("x=%d\n", x);
  func1();
  x=x+5;
  printf("x=%d\n", x);
  func2();
  x=x+5;
  printf("x=%d\n",x);
  return 0;
}

int x;
void func1(void){
   x=6;
   printf("In func1 x=%d\n",x);
}
void func2(void){
  x=x+10;
  printf("In func2 x=%d\n", x);
}
