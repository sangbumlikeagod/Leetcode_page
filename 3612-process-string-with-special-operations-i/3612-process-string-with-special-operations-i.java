class Solution {

    private int direction = 1;
    public int changeDirection() {
        direction = direction  == 1 ? -1 : 1;
        return direction; 
    }
    public int duplicate(char[] arr, int l, int r) {
        // l이 문자를 포함하지 않음
        int ls = l, rs = r;
        // 그냥 뒤에다 붙이면됨
        int len = rs - ls;
        for (int i = 1; i <= len; i++)
        {
            arr[r + i + prefix] = arr[r + i + prefix - len];
        }
        r = r + len;
        return r;
    }
    Integer thMAX = 1200000; 
    Integer prefix = 600000;

    public String processStr(String s) {
        
        char[] arr = new char[thMAX];
        int l = 0, r = 0;
        for (char c : s.toCharArray())
        {
            // r 이포함하는것으로한다  
            if (c == '*')
            {
                if (l == r) continue;
                if (direction == 1)
                {
                    arr[prefix + r] = ' ';
                    r--; 
                }
                else {
                    l++; 
                    arr[prefix + l] = ' ';
                }
            }
            else if (c == '#')
            {
                if (l == r) continue;
                r = duplicate(arr, l, r);
            }
            else if (c == '%')
            {
                if (l == r) continue;
                changeDirection();
            }
            else
            {
                // r이 포함하는걸로 바뀐다 
                if (direction == 1)
                {
                    r++;
                    arr[prefix + r] = c;
                }
                else
                {
                    arr[prefix + l] = c;
                    l--;
                }
            }
            
            
            // System.out.println(l + " -- " + r);
            // for (int ls = l + 1; ls <= r; ls++)
            // {
            //     System.out.print(arr[ls + prefix]);
            // }
            // System.out.println();
        }
        StringBuffer answer = new StringBuffer();
        // System.out.println(l + " -- " + r);
        if (direction == 1) {
            while (l < r)
            {
                l++;
                answer.append(arr[l + prefix]);
            }
        }
        else {
            while (l < r)
            {
                answer.append(arr[r + prefix]);
                r--;
            }
        }

        return answer.toString();
    }
}