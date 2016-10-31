/* scope of variables - example 5 file 2 */
int x;
void func1(void){
 printf("In func1 x=%d\n",x);
 x=5;
}
void func2(void){
  x=x+10;
  printf("In func2 x=%d\n", x);
}
