
class listnode:
    def __init__(self,value):
        self.value=value
        self.next=None
    def __str__(self):
        return "value= {}, next={}".format(self.value,self.next.value)
    
    def assignnext(self,node):
        self.next=listnode(node)

class Solution:
    def addTwoNumbers(self, l1, l2):
        for i in range(max(len(l1),len(l2))):
            if i==0:
                node=listnode((l1[i]+l2[i])%10)
                node.assignnext((l1[i]+l2[i])//10)
                result=node
                continue
            node=node.next
            try:
                if l1[i]:
                    node.value+=l1[i]
                if l2[i]:
                    node.value+=l2[i]
            except:pass
            node.next=listnode(node.value//10)
            node.value=node.value%10
        return self.Make_it_list(result)
    def Make_it_list(self,result):
        lst=[]
        try:
            while True:

                lst.append(result.value)
                result=result.next
        except: pass
        if lst[-1]==1:
            return lst
        else:
            return lst[:-1]
        
        
        
                # 둘중에 하나만 있으면 어떻게할건데 

                




l1 = [2,4,3]
l2 = [5,6,4]
# def lst(l1):
#     for i in range(len(l1)): # i가 순서를 나타내는 숫자여야 초회를 구분할 수 있음 enumerate로 안되는가 
#         if i==0:
#             node=listnode(0)
#             node.assignnext(l1[i])
#             result=node
#             print(node)
#             continue
#         node=node.next
#         node.assignnext(l1[i])
#         print(node)
#     return result

# print(lst(l2))
    

    
a= Solution()
print(a.addTwoNumbers(l1,l2))
print(10//10)

l1 = [9,9,9,9,9,9,9]
l2 = [9,9,9,9]
print(a.addTwoNumbers(l1,l2))
print(id(0),id(None), id(False))