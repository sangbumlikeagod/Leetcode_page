class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        

        table = {
            '(' : ')',
            '[' : ']',
            '{' : '}'
        }
        for al in s:
            if table.get(al,None) != None:
                stack+=al
            else:
                if len(stack) != 0  and al == table.get(stack[-1],None):
                    stack.pop()
                else:
                    return False
        return not stack