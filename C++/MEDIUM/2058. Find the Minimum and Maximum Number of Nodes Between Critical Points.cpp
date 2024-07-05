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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        int firstCritical = -1;
        int lastCritical = -1;
        int lastValue = -1;
        int minPath = 100001;
        int index = 0;

        while (head)
        {
            if (lastValue != -1 && head->next)
            {
                if ((head->val > lastValue && head->val > head->next->val) || (head->val < lastValue && head->val < head->next->val))
                {
                    minPath = lastCritical != -1 ? min(index - lastCritical, minPath) : 100001;
                    firstCritical = firstCritical == -1 ? index : firstCritical;
                    lastCritical = index;
                }
            }
            lastValue = head->val;
            index++;
            head = head->next;
        }

        if (firstCritical == -1 || firstCritical == lastCritical)
        {
            return {-1, -1};
        }
        else
        {
            return {minPath, lastCritical - firstCritical};
        }
    }
};