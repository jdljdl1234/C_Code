/* scope of variables- example 6 file 1 */
#include <stdio.h>
void func1(void); 
void func2(void); 
int main(){
  extern int x;
  x=1;
  printf("x=%d\n", x);
  func1();
  x=x+6;
  printf("x=%d\n", x);
  func2();
  x=x+7;
  printf("x=%d\n",x);
  return 0;
}
