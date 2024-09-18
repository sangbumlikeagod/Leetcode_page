class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        string answer = "";
        vector<string> numsString{};
        for (int num : nums)
        {
            numsString.push_back(to_string(num));
        }
        sort(numsString.begin(), numsString.end(), [](string a, string b)
             {
            int indexA = 0, indexB = 0, count = a.length() * b.length();
            while(a[indexA] == b[indexB] && count)
            {
                indexA = (indexA + 1) % a.length();
                indexB = (indexB + 1) % b.length();
                count--;
            }
            return a[indexA] > b[indexB]; });
        for (string num : numsString)
        {
            if (num == "0" && answer == "0")
            {
                continue;
            }
            answer += num;
        }
        return answer;
    }
};