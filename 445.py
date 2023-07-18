# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1, l2):
        ans = ListNode(0)
        tmp = ans
        stack1 = []
        stack2 = []
        stack3 = []
        while l1.next != None:
            stack1.append(l1.val)
            l1 = l1.next
        while l2.next != None:
            stack2.append(l2.val)
            l2 = l2.next
        stack1.append(l1.val)
        stack2.append(l2.val)


        bo = 0
        while stack1 or stack2:
            
            arg1 = stack1.pop() if stack1 else 0
            arg2 = stack2.pop() if stack2 else 0
            bo , local_sum = (arg1 + arg2 + bo) // 10, (arg1 + arg2 + bo) % 10 

            stack3.append(local_sum)
        
        if bo == 1:
            stack3.append(bo)
        
        while stack3:
            a= stack3.pop()

            tmp.next = ListNode(a)
            tmp = tmp.next
        
        return ans.next