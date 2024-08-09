class Solution
{
    string oneDigit[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string tenthDigit[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string nTenth[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string thousands[4] = {"", "Thousand", "Million", "Billion"};
    int index = 0;
    vector<string> answerList{};
    string hundreds(int num)
    {
        string answer = "";
        if (num / 100)
        {
            answer += oneDigit[num / 100] + " " + "Hundred";
            if (num % 100)
            {
                answer += " ";
            }
        }

        int tenth = num / 10 % 10;
        if (tenth == 1)
        {
            answer += tenthDigit[num % 10];
        }
        else if (tenth)
        {
            answer += nTenth[tenth];
            if (num % 10)
            {
                answer += " ";
            }
            answer += oneDigit[num % 10];
        }
        else
        {
            answer += oneDigit[num % 10];
        }
        return answer;
    }

public:
    string numberToWords(int num)
    {
        if (!num)
        {
            return "Zero";
        }
        while (num)
        {
            if (num % 1000)
            {
                string tmp = hundreds(num % 1000);
                if (index)
                {
                    tmp += " " + thousands[index];
                }
                answerList.push_back(tmp);
            }
            index++;
            num /= 1000;
        }

        string answer = "";
        bool isFisrt = true;
        while (!answerList.empty())
        {
            answer += answerList[answerList.size() - 1];
            if (answerList.size() != 1)
            {
                answer += " ";
            }
            answerList.pop_back();
        }
        return answer;
    }
};