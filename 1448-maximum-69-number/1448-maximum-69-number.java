class Solution {
    public int maximum69Number (int num) {
        int answer = num;
        if (6000 < num && num < 7000)
        {
            answer += 3000;
        }
        else if ( num % 1000 < 700 && num % 1000  > 600)
        {
            answer += 300;
        }
        else if (num % 100 < 70 && num % 100  > 60)
        {
            answer += 30;
        }
        else if (num % 10 < 7 && num % 10  >= 6)
        {
            answer += 3;
        }
        return answer;
    }
}