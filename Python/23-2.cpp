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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> Q;
        for (ListNode* node: lists){
            while (node != nullptr){
                Q.push(node -> val);
                node = node -> next;
            }
        }
        ListNode* ans = new ListNode();
        ListNode* ret = ans;
        while (!Q.empty()){
            ans -> next =  new ListNode(Q.top());
            ans = ans -> next;
            Q.pop();
        }
        return ret -> next;
    }
};