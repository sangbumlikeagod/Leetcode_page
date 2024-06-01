class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, list1: [ListNode], list2: [ListNode]) -> [ListNode]:
        if not list1 and not list2:
            return None
        elif not list2:
            return list1
        elif not list1:
            return list2
        
        merge_origin = merge
        if list1.val <= list2.val:
            merge  = list1
            list1 = list1.next
        else:
            merge = list2
            list2 = list2.next
        while list1 and list2:
            if list1.val < list2.val:
                merge.next = list1
                list1 = list1.next
            else:
                merge.next = list2
                list2 = list2.next
            merge = merge.next
        if list1:
            merge.next = list1
        if list2:
            merge.next = list2
        
        return merge_origin