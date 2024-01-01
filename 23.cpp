
// #Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode();
        ListNode* ret = ans;
        while (true){
            bool isempty = true;
            int val = 10001;
            int idx = -1;
            int now = 0;
            for(ListNode* node: lists){
                if (node != nullptr)
                {
                    isempty = false;
                } 
                else { 
                    now++;
                    continue; 
                    }
                if (node->val < val){
                    val = node->val;
                    idx = now;
                }
                now++;
                
            }   
            if (isempty) {
                break;
            } 
            ans->next = new ListNode(lists[idx] -> val);
            ans = ans->next;
            lists[idx] = lists[idx] -> next;
        }
        return ret -> next;
    }
};