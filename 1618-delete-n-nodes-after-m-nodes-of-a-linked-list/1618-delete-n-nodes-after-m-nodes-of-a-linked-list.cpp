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
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* headC = head;
        while (head && head -> next)
        {
            for (int i = 0; i < m - 1; i++)
            {
                if (head -> next == nullptr) break;
                head = head -> next;
            }
            for (int j = 0; j < n; j++)
            {
                if (head -> next == nullptr) break;
                head -> next = head -> next -> next;
            }
            head = head -> next;
        }
        return headC;
    }
};