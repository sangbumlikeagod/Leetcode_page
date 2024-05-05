/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* pointer = node;
        while (pointer -> next -> next)
        {
            pointer -> val = pointer -> next -> val;
            pointer = pointer -> next;
        }
        pointer -> val = pointer -> next -> val;
        pointer -> next = nullptr;
    }
};