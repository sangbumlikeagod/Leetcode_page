class Solution:
    def intToRoman(self, num: int):
        a,b,c,d=num//1000,num%1000//100,num%100//10,num%10
        a1='M'*a
        if 0<=b<4:
            b1='C'*b
        elif b==4:
            b1='CD'
        elif 4<b<9:
            b1='D'+'C'*(b-5)
        elif b==9:
            b1='CM'
            
        if 0<=c<4:
            c1='X'*c
        elif c==4:
            c='XL'
        elif 4<c<9:
            c1='L'+'X'*(c-5)
        elif c==9:
            c1='XC'

        if 0<=d<4:
            d1='I'*d
        elif d==4:
            d1='IV'
        elif 4<d<9:
            d1='V'+'I'*(d-5)
        elif d==9:
            d1='IX'

        return a1+b1+c1+d1