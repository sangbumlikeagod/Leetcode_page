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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int bef = head.val;
        head = head.next;
        int lo = head.val;
        if (head.next == null)
        {
            return new int[] {-1, -1};
        }
        int nex = head.next.val;

        
        
        int idx = 1;
        
        int lastIdx = -1;
        int firstIdx = -1;
        int[] answer = new int[] {200000, -1};

        while (head.next != null)
        {
            nex = head.next.val;
            if (
                (bef < lo && lo > nex) ||
                (bef > lo && lo < nex)
            )
            {
                System.out.println(idx);
                if (firstIdx == -1)
                {
                    firstIdx = idx;
                }
                if (lastIdx != -1)
                {
                    answer[0] = Math.min(answer[0], idx - lastIdx);
                    answer[1] = Math.max(answer[1], idx - firstIdx);
                }
                lastIdx = idx;
            }
            idx++;
            bef = head.val;
            head=head.next;
            lo = head.val;
        }
        if (answer[0] == 200000)
        {
            answer[0] = -1;
        }

        return answer;
    }
}