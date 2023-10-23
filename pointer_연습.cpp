
#include <stdio.h>


int main(){
    int a(5);
    int  *b = &a;
    a=3;
    // a는 다시 배열하는데 문제가 있니 ? 
    printf("%d ,%d\n", *b , a);

    int c(3);
    int d = c;
    c=5;
    printf("%d,%d\n",c,d);







}