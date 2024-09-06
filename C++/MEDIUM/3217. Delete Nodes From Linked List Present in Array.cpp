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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        vector<int> flags(100001, 0);
        ListNode *answer = new ListNode(0);
        ListNode *answer_copy = answer;
        answer->next = head;
        for (int num : nums)
        {
            flags[num]++;
        }

        while (answer->next)
        {
            if (flags[answer->next->val])
            {
                answer->next = answer->next->next;
            }
            else
            {
                answer = answer->next;
            }
        }

        return answer_copy->next;
    }
};