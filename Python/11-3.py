# class Solution:
#     def maxArea(self, height):
#         max_area=0
        
#         for i in range(len(height)):
#             for j in range(i+1,len(height)):
#                 max_area=max(max_area,(j-i)*min(height[i],height[j]))
                    
#         return max_area
    

ddd={}
ddd[1]=2

ddd[99]=100
print(type(sorted(ddd.keys(),reverse=True)))


# class Solution:
#     def maxArea(self, height):
#         table={}
#         max_int=0
#         i=-1
#         j=-1
#         for k in range(len(height)):
#             if height[k] not in table:
#                 table[height[k]]=[k]
#             else:
#                 table[height[k]].append(k) 
        
#         print(table)
#         for key in sorted(table.keys(),reverse=True):
#             while table[key]:
#                 print('key는',key)
#                 if i==-1:
                    
#                     i=table[key].pop(0)
#                     print('시작의 i',i)
#                     continue
#                 if j==-1:
                    
#                     j=table[key].pop(0)
#                     print('시작의 j',j)
#                     if max_int==0:
#                         max_int=abs(i-j)*key
#                         print(max_int,key,i,j)
#                     continue
                
#                 tmp=table[key].pop(0)
                
                
                
#                 if abs(i-j) == max(abs(i-j),abs(tmp-i),abs(tmp-j)):
#                     i,j=i,j
#                     max_int=max(max_int,abs(i-j)*key)
#                 elif abs(i-tmp) == max(abs(i-j),abs(tmp-i),abs(tmp-j)):
#                     i,j=i,tmp
#                     max_int=max(max_int,abs(i-j)*key)
#                 else:
#                     i,j=tmp,j
#                     max_int=max(max_int,abs(i-j)*key)
#                 print(max_int)
#         return max_int
    

class Solution:
    def maxArea(self, height):
        i=0
        j=len(height)-1
        max_int=(j-i)*min(height[i],height[j])
        while i<j:
            if height[i]<=height[j] : i+=1
            else: j-=1
            max_int=max(max_int,(j-i)*min(height[i],height[j]))
            
        return max_int
            
            
            
a=Solution()
height =[1,8,6,2,5,4,8,3,7]
print(a.maxArea(height))



