/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return head;
        }
        int lx = 1;
        ListNode pointer = head;

        while (pointer.next != null)
        {
            lx++;

            pointer = pointer.next;
        }
        k %= lx;
        k = lx - k;

        if (k == 0)
        {
            return head;
        }
        ListNode tail = pointer;
        tail.next = head;
        pointer = head;
        while (k-- > 1)
        {
            pointer = pointer.next;
        }
        ListNode tmp = pointer.next;
        pointer.next = null;
        return tmp;
    }
}