# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # 포인터 두개를 만든다 상대적으로 
        
        #처음 n 개에 대해서 만큼 먼저 이동하고 (오류가 일어날 일은 없음)
        
        initial = before_change = head
        for i in range(n):
            initial = initial.next
            
        while initial.next:
            initial = initial.next
            before_change = before_change.next
        before_change.next = before_change.next.next
        
        return head
            
        