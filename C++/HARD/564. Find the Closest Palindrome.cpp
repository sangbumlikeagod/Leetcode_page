#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{

private:
    void revisionString(string &n, int isAdd, int index)
    {
        bool shouldMove = true;

        if (isAdd)
        {
            while (shouldMove)
            {
                if (n[index] == '9')
                {
                    n[index] = '0';
                    index--;
                }
                else
                {
                    n[index]++;
                    return;
                }
            }
        }
        else
        {
            while (shouldMove)
            {
                if (n[index] == '0')
                {
                    n[index] = '9';
                    index--;
                }
                else
                {
                    n[index]--;
                    return;
                }
            }
        }
    }

    long long getCost(string left, string right)
    {
        long long llLeft = stoll(left);
        long long llRight = stoll(right);
        cout << llLeft << ' ' << llRight << ' ' << abs(llLeft - llRight) << '\n';
        return abs(llLeft - llRight);
    }

public:
    string nearestPalindromic(string n)
    {
        if (n.length() == 1)
        {
            n[0]--;
            return n;
        }

        int isOdd = n.length() % 2;
        int isPalindrome = 1;
        int canBeLowerDigits = 1;
        string answer = "";

        for (int left = 0; left < n.length() / 2; left++)
        {
            if (n[left] != n[n.length() - 1 - left])
            {
                isPalindrome = 0;
                break;
            }
        }

        // cout << isPalindrome << '\n';
        if (isPalindrome)
        {
            long long cost;
            bool isNines = true;
            // 99999 파악.
            for (int i = 0; i <= (n.length() / 2) - 1; i++)
            {
                if (n[i] != '9')
                {
                    isNines = false;
                }
            }
            if (isNines)
            {
                answer = "1";
                for (int i = 0; i < n.length() - 1; i++)
                {
                    answer += '0';
                }
                answer += '1';
                return answer;
            }

            // 1000001 파악
            if (n[0] == '1')
            {
                for (int i = 1; i <= n.length() / 2 - 1; i++)
                {
                    if (n[i] != '0')
                    {
                        canBeLowerDigits = false;
                        break;
                    }
                }
            }
            else
            {
                canBeLowerDigits = false;
            }

            if (canBeLowerDigits)
            {
                for (int i = 0; i < n.length() - 1; i++)
                {
                    answer += '9';
                }
                return answer;
            }
            // 자리가 바뀔일은 없다 이제 그상태에서 두개 다 바꿔줘야함 여기서는

            // 왼쪽을 1 뺐을 때의 코스트 구하기
            // string halfLeft = n.substr(0, n.length() / 2);
            string changeLeft = n;
            revisionString(changeLeft, 0, n.length() / 2 - 1);

            for (int i = 0; i < n.length() - i - 1; i++)
            {
                changeLeft[n.length() - i - 1] = changeLeft[i];
            }
            cost = getCost(changeLeft, n);
            answer = changeLeft;

            // 더했을 때의 코스트 구하기
            // string halfLeft = substr(n.begin(), n.length() / 2);
            // halfLeft = n.substr(0, n.length() / 2);
            changeLeft = n;
            revisionString(changeLeft, 1, n.length() / 2 - 1);
            for (int i = 0; i < n.length() - i - 1; i++)
            {
                changeLeft[n.length() - i - 1] = changeLeft[i];
            }

            long long costAdd = getCost(changeLeft, n);

            if (costAdd < cost)
            {
                cost = costAdd;
                answer = changeLeft;
            }

            if (isOdd)
            {
                string substarctLeft = n;
                revisionString(substarctLeft, 0, n.length() / 2);
                for (int i = 0; i < n.length() - i - 1; i++)
                {
                    substarctLeft[n.length() - i - 1] = substarctLeft[i];
                }
                long long costAdd = getCost(substarctLeft, n);

                if (costAdd < cost)
                {
                    cost = costAdd;
                    answer = substarctLeft;
                }

                substarctLeft = n;
                revisionString(substarctLeft, 1, n.length() / 2);
                for (int i = 0; i < n.length() - i - 1; i++)
                {
                    substarctLeft[n.length() - i - 1] = substarctLeft[i];
                }
                costAdd = getCost(substarctLeft, n);
                if (costAdd < cost)
                {
                    cost = costAdd;
                    answer = substarctLeft;
                }
            }
        }
        else
        {
            long long cost;

            bool shoudLowerDigits = true;
            if (n[0] == '1')
            {
                for (int j = 1; j < n.length(); j++)
                {
                    if (n[j] != '0')
                    {
                        shoudLowerDigits = false;
                        break;
                    }
                }
            }
            else
            {
                shoudLowerDigits = false;
            }

            if (shoudLowerDigits)
            {
                for (int i = 0; i < n.length() - 1; i++)
                {
                    answer += '9';
                }
                return answer;
            }

            // 그냥 코스트 구하기
            // string halfLeft = substr(n.begin(), n.length() / 2);
            // string halfLeft = n.substr(0, n.length() / 2);

            // string reversedHalfLeft = halfLeft;
            // reverse(reversedHalfLeft.begin(), reversedHalfLeft.end());
            // string halfRight = n.substr(n.length() / 2 + n.length() % 2, n.length() / 2);

            // cost = getCost(reversedHalfLeft, halfRight);
            // answer = isOdd ? halfLeft + n[n.length() / 2] + reversedHalfLeft : halfLeft + reversedHalfLeft;

            string changeLeft = n;
            // revisionString(changeLeft, 0, n.length() / 2 - 1);

            for (int i = 0; i < n.length() - i - 1; i++)
            {
                changeLeft[n.length() - i - 1] = changeLeft[i];
            }
            cost = getCost(changeLeft, n);
            answer = changeLeft;

            if (isOdd)
            {
                string substarctLeft = n;
                revisionString(substarctLeft, 0, n.length() / 2);
                for (int i = 0; i < n.length() - i - 1; i++)
                {
                    substarctLeft[n.length() - i - 1] = substarctLeft[i];
                }
                long long costAdd = getCost(substarctLeft, n);

                if (costAdd <= cost)
                {
                    cost = costAdd;
                    answer = substarctLeft;
                }

                substarctLeft = n;
                revisionString(substarctLeft, 1, n.length() / 2);
                for (int i = 0; i < n.length() - i - 1; i++)
                {
                    substarctLeft[n.length() - i - 1] = substarctLeft[i];
                }
                costAdd = getCost(substarctLeft, n);
                if (costAdd < cost)
                {
                    cost = costAdd;
                    answer = substarctLeft;
                }
            }

            // 뺐을 때의 코스트 구하기

            changeLeft = n;
            revisionString(changeLeft, 0, n.length() / 2 - 1);

            for (int i = 0; i < n.length() - i - 1; i++)
            {
                changeLeft[n.length() - i - 1] = changeLeft[i];
            }
            if (isOdd)
            {
                changeLeft[n.length() / 2] = '9';
            }
            long long costAdd = getCost(changeLeft, n);

            if (costAdd <= cost)
            {
                cost = costAdd;
                answer = changeLeft;
            }
            // halfLeft = n.substr(0, n.length() / 2);

            // revisionString(halfLeft, 0, halfLeft.length() - 1);
            // reversedHalfLeft = halfLeft;
            // reverse(reversedHalfLeft.begin(), reversedHalfLeft.end());
            // long long costAdd = abs(getCost(halfLeft, halfRight) - pow(10, n.length() - n.length() / 2));
            // if (costAdd <= cost)
            // {
            //     cost = costAdd;

            //     answer = isOdd ? halfLeft + "9" + reversedHalfLeft : halfLeft + reversedHalfLeft;
            // }

            // 더했을 때의 코스트 구하기

            changeLeft = n;
            revisionString(changeLeft, 1, n.length() / 2 - 1);

            for (int i = 0; i < n.length() - i - 1; i++)
            {
                changeLeft[n.length() - i - 1] = changeLeft[i];
            }
            cout << changeLeft << '\n';
            if (isOdd)
            {
                changeLeft[n.length() / 2] = '9';
            }
            costAdd = getCost(changeLeft, n);
            if (costAdd < cost)
            {
                cost = costAdd;
                answer = changeLeft;
            }
            // halfLeft = n.substr(0, n.length() / 2);

            // revisionString(halfLeft, 1, halfLeft.length() - 1);
            // reversedHalfLeft = halfLeft;

            // reverse(reversedHalfLeft.begin(), reversedHalfLeft.end());
            // costAdd = getCost(halfLeft, halfRight) + pow(10, n.length() - n.length() / 2);

            // if (costAdd < cost)
            // {
            //     cost = costAdd;
            //     answer = isOdd ? halfLeft + "0" + reversedHalfLeft : halfLeft + reversedHalfLeft;
            // }
        }
        return answer;
    }
};