class Solution:
    def maxProfit(self, prices):
        minvalue=prices[0]
        size=len(prices)
        def recur(index,max_re,minvalue):
            print("{} times left".format(max_re),index,minvalue)
            if index==size-1:
                print('다왔다',prices[index]-minvalue)
                return prices[index]-minvalue

            while index<size-1:
                if prices[index+1]<=prices[index]:
                    if max_re==0:
                        
                        return recur(index+1,max_re,min(prices[index+1],minvalue))
                    else:
                        ans1=(prices[index]-minvalue+recur(index+1,max_re-1,prices[index+1]))
                        ans2=recur(index+1,max_re,min(prices[index+1],minvalue))
                        print(ans1,'과',ans2,'중 큰 친구를 답으로 리턴할거다 지금의 index와 minvalue는 ' ,index,minvalue)
                        return max(ans1,ans2)
                else:  
                
                    index+=1

            return recur(index,max_re,minvalue)
        return recur(0,1,minvalue)
                    

a=Solution()
prices=[2,1,4,5,2,9,7]
print(a.maxProfit(prices))