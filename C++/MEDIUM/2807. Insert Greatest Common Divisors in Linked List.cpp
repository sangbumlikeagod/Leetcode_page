/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        vector<int> primes(1000, 0);
        vector<int> onlyPrimes{};

        for (int i = 2; i < 1000; i++)
        {
            if (!primes[i])
            {
                onlyPrimes.push_back(i);
                int iTimes = i;
                while (iTimes < 1000)
                {
                    primes[iTimes]++;
                    iTimes += i;
                }
            }
        }
        ListNode *answer = head;
        while (head && head->next)
        {
            int val = 1;
            int currents = head->val;
            int nexts = head->next->val;
            for (int prime : onlyPrimes)
            {
                if (currents == 1 || nexts == 1)
                {
                    break;
                }
                while (!(currents % prime) && !(nexts % prime))
                {
                    currents /= prime;
                    nexts /= prime;
                    val *= prime;
                }
            }
            ListNode *tmp = new ListNode(val, head->next);
            head->next = tmp;
            head = head->next->next;
        }
        return answer;
    }
};