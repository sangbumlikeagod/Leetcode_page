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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {

        vector<ListNode *> answer(k, nullptr);
        int num = 0;
        ListNode *tmp = head;
        while (tmp)
        {
            num++;
            tmp = tmp->next;
        }

        vector<int> times(k, num / k);

        for (int i = 0; i < num % k; i++)
        {
            times[i]++;
        }

        for (int i = 0; i < k; i++)
        {
            answer[i] = new ListNode();
        }

        vector<ListNode *> answerCur(k, nullptr);

        for (int i = 0; i < k; i++)
        {
            answerCur[i] = answer[i];
        }

        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < times[i]; j++)
            {
                ListNode *tmp = answerCur[i];
                tmp->next = new ListNode(head->val);
                answerCur[i] = tmp->next;

                head = head->next;
            }
        }

        for (int i = 0; i < k; i++)
        {
            answer[i] = answer[i]->next;
        }

        return answer;
    }
};