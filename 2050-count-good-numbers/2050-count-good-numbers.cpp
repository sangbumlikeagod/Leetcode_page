class Solution {
    long long MODULO = 1e9 + 7;
public:
    int countGoodNumbers(long long n) {
        long long answer = 1;
        long long tim = 20;
        long long n1 = n / 2;
        int n2 = n % 2;
        if (n2)
        {
            answer *= 5;
        }
        // 그럼 10의 15승을 비트화해서 거듭제곱의 형식으로 계속 더하는 방법이있음
        long long answerLeft = 1;
        while (n1)
        {
            if (n1 & 1)
            {
                answerLeft = tim * answerLeft;
                answerLeft %= MODULO;;
            }
            n1 /= 2;
            tim *= tim;
            tim %= MODULO;
        }
        if (answerLeft)
        {
            answer *= answerLeft;
        }
        answer %= MODULO;
        return answer;
    }
};