class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // 룰 1 겹치는 비트부터 한다.
        // 룰 2 오른쪽부터 한다.
        int index = 0;
        int cnt = 0;
        int num3 = num1;
        while (num2 || num3)
        {
            cnt += num2 & 1;
            num3 >>= 1;
            num2 >>= 1;
            index++;
        }
        index--;
        int power = pow(2, index);
        int answer = 0;
        while (power && cnt)
        {
            if (power & num1)
            {
                answer += power;
                cnt--;
            }
            power >>= 1;
        }

        index = 1;
        while (cnt)
        {
            if (num1 & index) 
            {
                index <<= 1;
                continue;
            }
            answer += index;
            index <<= 1;
            cnt--;
        }

        return answer;
    }
};