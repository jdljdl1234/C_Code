/* scope of variables - Example 3 */
#include <stdio.h>
void func1(void); 
void func2(void); 
void func3(void);
int main(){
  int x=20;
  printf("x=%d\n", x);
  func1();
  x=x+10;
  printf("x=%d\n", x);
  func2();
  x=x+40;
  printf("x=%d\n",x);
  func3();      
  return 0;
}

int x;
void func1(void){
   x=5;
   printf("In func1 x=%d\n",x);
   return;
}

void func2(void){
  int x=0;
  printf("In func2 x=%d\n", x);
  return;
}

void func3(void){
  printf("In func3 x=%d\n", x);
  return ;
}

