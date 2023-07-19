
# 모듈 생성 
# self.log = {
#     'f' : None,
#     'l' : None 
# }

# def put(k):
#     ex_new = self.log['f']
#     if ex_new != None:
#         self.log[ex_new][0] = k
#     else:
#         self.log['l'] = k
#     self.log[k] = [0,ex_new] if ex_new != None else [0,0]
#     self.log['f'] = k
    
# def pull(k):
#     if k in self.log:
#         left , right = self.log[k][0], self.log[k][1]
        
#         if left == 0:
#             self.log['f'] = right
#             self.log[right][0] = 0
#         elif right == 0:
#             self.log['l'] = left
#             self.log[left][1] = 0
#         else:
#             self.log[left][1], self.log[right][0] = right, left
#         self.log.pop(k)

    # def get(self, key: int) -> int:
    #     print('으악1')
    #     if key in self.LRU:
    #         if self.LRU['new'] == key:
    #             pass
    #         elif self.LRU['LRU'] == key:
    #             self.LRU['LRU'] = self.LRU[self.LRU['LRU']][0]


    #         else: 
    #             self.LRU[self.LRU[key][0]][1] , self.LRU[self.LRU[key][1]][0] = self.LRU[self.LRU[key][1]][0] , self.LRU[self.LRU[key][0]][1]

    #     if self.LRU['new'] != 0:
    #         self.LRU[self.LRU['new']][0] = key
            
    #     self.LRU[key] = [0,self.LRU['new']]
    #     self.LRU['new'] = key
    #     return self.table.get(key, -1)
    #     print(self.LRU)

        

    # def put(self, key: int, value: int) -> None:
    #     print('으악2')
    #     if self.size_available == 0:
    #         self.table.pop(self.LRU['LRU'])
    #         self.LRU['LRU'] = self.LRU[self.LRU['LRU']][0]
    #         self.table[key] = value
            
            
    #     else:
    #         self.table[key] = value

    #         self.size_available -= 1


    #     if key in self.LRU:
    #         if self.LRU['new'] == key:
    #             pass
    #         elif self.LRU['LRU'] == key:
    #             self.LRU['LRU'] = self.LRU[self.LRU['LRU']][0]
    #         else: 
    #             self.LRU[self.LRU[key][0]][1] , self.LRU[self.LRU[key][1]][0] = self.LRU[self.LRU[key][1]][0] , self.LRU[self.LRU[key][0]][1]
        

        
    #     if self.LRU['new'] != 0:
    #         self.LRU[self.LRU['new']][0] = key
    #     self.LRU[key] = [0,self.LRU['new']]
    #     if self.LRU['LRU'] == 0:
    #         self.LRU['LRU'] = key

    #     self.LRU['new'] = key
    #     print(self.LRU)



# class LRUCache:

#     def __init__(self, capacity: int):

#         self.log = {
#             'f' : None,
#             'l' : None 
#         }
#         self.table = {}
#         self.size_available = capacity
        

#     def get(self, key: int) -> int:
        
#         self.log_pull(key)
#         self.log_put(key)
        
#         return self.table.get(key,-1)
        

#     def put(self, key: int, value: int) -> None:
        
#         if self.size_available == 0:
#             self.log_pull(self.log['l'])
#         self.table[key]=value
#         self.log_pull(key)
#         self.log_put(key)
        
        
        



#     def log_put(self, k):
#         ex_new = self.log['f']
#         if ex_new != None:
#             self.log[ex_new][0] = k
#         else:
#             self.log['l'] = k
#         self.log[k] = [0,ex_new] if ex_new != None else [0,0]
#         self.log['f'] = k

#     def log_pull(self,k):
#         if k in self.log:
#             left , right = self.log[k][0], self.log[k][1]
            
#             if left == 0:
#                 self.log['f'] = right
#                 self.log[right][0] = 0
#             elif right == 0:
#                 self.log['l'] = left
#                 self.log[left][1] = 0
#             else:
#                 self.log[left][1], self.log[right][0] = right, left
#             self.log.pop(k)   

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

'''

4차 시도 

'''
class LRUCache:

    def __init__(self, capacity: int):

        self.log = {
            'f' : None,
            'l' : None 
        }
        self.table = {}
        self.size_available = capacity
        self.i=1

    def get(self, key: int) -> int:
        if key in self.log:
            self.log_pull(key)
            self.log_put(key)
        # print('get 한다', key)
        print(self.log)

        print(self.table)
        print(self.i)
        self.i += 1
        return self.table.get(key,-1)
        

    def put(self, key: int, value: int) -> None:
        
        if self.size_available == 0 and key not in self.table:
            self.table.pop(self.log['l'])
            self.log_pull(self.log['l'])
        self.table[key]=value
        self.log_pull(key)
        self.log_put(key)
        if self.size_available > 0:
            self.size_available -= 1
        # print('put한다', key)
        print(self.log)
        print(self.table)
        print(self.i)
        self.i+=1
        
        



    def log_put(self, k):
        # print(k , self.log)
        ex_new = self.log['f']
        if ex_new !=  None:
            self.log[ex_new][0] = k
        else:
            self.log['l'] = k
        self.log[k] = [None,ex_new] if ex_new != None else [None,None]
        self.log['f'] = k

    def log_pull(self,k):
        if k in self.log:
            left , right = self.log[k][0], self.log[k][1]
            
            if left == None:
                self.log['f'] = right
                if right != None:
                    self.log[right][0] = None
            elif right == None:
                self.log['l'] = left
                if left != None:
                    self.log[left][1] = None
            else:
                self.log[left][1], self.log[right][0] = right, left
            self.log.pop(k)