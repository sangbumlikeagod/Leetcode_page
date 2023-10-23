class Solution:
    def intToRoman(self, num: int):
        table = {}
        i=10
        p=num
        while p>0:
            table[i//10]=p%10
            i,p=10*i,p//10
        print(table)
        ans=''
        j=1000
        
        if 1000 in table:
            ans+='M'*table[1000]
        if 100 in table:
            if table[100]==9:
                ans+='CM'
            elif table[100]==4:
                ans+='CD'
            if table[100]<4:
                ans+='C'*table[100]
            elif 4<table[100]<9:
                ans+='D'+'C'*(table[100]-5)
        
        if 10 in table:
            if table[10]==9:
                ans+='XC'
            elif table[10]==4:
                ans+='XL'
            if table[10]<4:
                ans+='X'*table[10]
            elif 4<table[10]<9:
                ans+='L'+'X'*(table[10]-5)
            
        if 1 in table:
            if table[1]==9:
                ans+='IX'
            elif table[1]==4:
                ans+='IV'
            if table[1]<4:
                ans+='I'*table[1]
            elif 4<table[1]<9:
                ans+='V'+'I'*(table[1]-5)
        j=j//10
        return ans
        
a=Solution()
print(a.intToRoman(1994))