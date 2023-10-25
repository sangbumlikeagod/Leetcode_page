// n - 1 번째 어떤 인덱스의 값은 n번 째 2n - 2 , 2n - 1번째 요소에 절대적인 영향을 준다 따라서 전체 배열과 상관없이 이거만 알면 문제를 풀 수 있을 것이다.
// 1이라고 설정을 한다면 


class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1){
            return 0;
        } else {
            if (k % 2 == 1){
                int a = kthGrammar(n - 1, (k + 1) / 2);
                if (a == 1){
                    return 0;
                } else {
                    return 1;
                }
            } else {
                int a = kthGrammar(n - 1, (k) / 2);
                if (a == 1){
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }
};