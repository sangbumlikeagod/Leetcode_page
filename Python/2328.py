class Solution:
    def countPaths(self, grid):
        table=[[0]*len(grid[0])]*len(grid)
        ans=0
        
        def recur(i,j):

            if table[i][j]!=0:
                return table[i][j]
            
                

            
            east=recur(i+1,j) if i<len(grid)-1 and grid[i+1][j]>grid[i][j] else 0     
            west=recur(i-1,j) if i!=0  and grid[i-1][j]>grid[i][j] else 0     
            north=recur(i,j+1) if j<len(grid[0])-1 and grid[i][j+1]>grid[i][j] else 0     
            south=recur(i,j-1) if j!=0 and grid[i+1][j-1]>grid[i][j]else 0        
            
            table[i][j]+=east+west+south+north+1
            return table[i][j]
        for i in range(grid):
            for j in range(grid):
                recur(i,j)
        for i in table:
            ans+=sum(i)
        return ans
    

# dict={1:[[1,2,3],[2,3,4]],2:[1,2,3]}
# count=0
# for i in dict:
#     count+=len(dict[i])
# print(count)

# class Solution:
#     def countPaths(self, grid):
#         table={}
#         ans=0
        
#         def recur(i,j):
            
#            .append(grid[i][j])
#             if len) not in table:
#                 table[len)]=]
#             else:
#                 if in table[len)]:
#                     pass
#                 else:
#                     table[len)].append)
#             if 0<=i<len(grid)-1:
#                 if grid[i][j]<grid[i+1][j]:
#                     recur(i+1,j[:])
#                 elif i!=0 and grid[i][j]>grid[i-1][j]: 
#                     recur(i-1,j[:])    
#                 recur(i+1,j,[])
#             if 0<=j<len(grid[0])-1:
#                 if grid[i][j]<grid[i][j+1]:
#                     recur(i,j+1[:])
#                 elif j!=0 and grid[i][j]>grid[i][j-1]: 
#                     recur(i,j-1[:])
#                 recur(i,j+1,[])
#         recur(0,0,[])
#         for i in table:
#             ans+=len(table[i])
#         print(table)
#         return ans
print([[0]*8]*4)
print(sum([1,2,3]))

# class Solution:
#     def countPaths(self, grid):
#         table=[[0]*len(grid[0])]*len(grid)
#         ans=0
        
#         def recur(i,j):
#             re=0
#             if table[i][j]!=0:
#                 return table[i][j]
#             table[i][j]+=1
#             east=recur(i+1,j) if i<len(grid)-1 else 0
#             if east != 0 and grid[i+1][j]>grid[i][j]:
#                 table[i][j]+=east 

#             west=recur(i-1,j) if i!=0 else 0  
#             if west != 0 and grid[i-1][j]>grid[i][j]:
#                 table[i][j]+=west   
#             north=recur(i,j+1) if j<len(grid[0])-1 else 0 
#             if north != 0 and grid[i][j+1]>grid[i][j]:
#                 table[i][j]+=north    
#             south=recur(i,j-1) if j!=0 else 0        

#             if south != 0 and grid[i][j-1]>grid[i][j]:
#                 table[i][j]+=south                    

#             return table[i][j]
#         recur(0,0)
#         for i in table:
#             ans+=sum(i)
#         print(table)
#         return ans