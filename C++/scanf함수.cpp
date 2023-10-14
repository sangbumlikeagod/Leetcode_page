#include <stdio.h>

int main(){
    int a;
    float b;
    scanf("%d %f" ,&a , &b);
    printf("%d + %f = %f\n", a,b, a * b);
}

// 놀라운 건 a * b를 객체로 받았다는거 어떻게 받은거냐? 객체가 아니라 그냥 값만 출력해주는 것일수도