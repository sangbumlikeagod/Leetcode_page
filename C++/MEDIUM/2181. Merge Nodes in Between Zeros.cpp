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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *answerHead = new ListNode(0);
        ListNode *answerTail = answerHead;
        head = head->next;
        int mergedValue = 0;
        while (head)
        {
            if (head->val)
            {
                mergedValue += head->val;
            }
            else
            {
                // answerTail -> next = make_shared<ListNode>(ListNode(mergedValue));
                answerTail->next = new ListNode(mergedValue);
                mergedValue = 0;
                answerTail = answerTail->next;
            }
            head = head->next;
        }
        return answerHead->next;
    }
};