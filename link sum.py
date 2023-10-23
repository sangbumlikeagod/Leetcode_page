# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# 단일 연결리스트 
class Solution:
    def addTwoNumbers(self, l1, l2):
        l3 = ListNode(0)
        
        sch1=True
        sch2=True
        while sch1 is True or sch2 is True:  
            try:
                l3.val+=(l1.val+l2.val)%10
                if l1.next is not None:
                    l1=l1.next
                else: sch1 = False
                if l2.next is not None:
                    l2=l2.next
                else: sch2 = False
                
                l3.next=ListNode(val=(l1.val+l2.val)//10)

                l3=l3.next
                
            except: pass
            
        return l3