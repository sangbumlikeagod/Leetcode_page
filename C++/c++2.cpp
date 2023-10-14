#include <stdio.h>


int main() { 
    int a = 5;
    int b;
    b = ++a;
    printf("=== 전치 증가 연산 ===\n");
    printf("a = %d\n",a);
    printf("b = %d\n",b);

    b = a++;
    printf("=== 후치 증가 연산 ===\n");
    printf("a = %d\n",a);
    printf("b = %d\n",b);

    bool p = b>a;
    printf("불리언 후치 증가 연산을 한 a는 b보다 작다 %d\n",p);

    int c;
    c=3;
    bool t = c >= 1 && c<=10;
    bool q = c == 3 || c==7;
    bool r = !q; 

    printf("%d\n",t);
    printf("%d\n",q);
    printf("%d\n",r);

     
}
//
