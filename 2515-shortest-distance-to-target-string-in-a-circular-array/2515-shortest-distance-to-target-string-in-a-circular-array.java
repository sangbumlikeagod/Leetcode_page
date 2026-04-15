class Solution {
    public int closestTarget(String[] words, String target, int startIndex) {
        
        int l = startIndex;
        int r = startIndex;
        
        int n = words.length;
        // 같은인덱스의 경우에 
        int answer = 0;
        // 둘이 합쳐졌을 경우를 의미하는데 
        while (l != r + 1)
        {
            // System.out.println(l + " " + r);
            if (words[l].equals(target) || words[r].equals(target))
            {
                return answer;
            }
            l = l == 0 ? n - 1 : l - 1;
            r = (r + 1) % n; 
            answer += 1;

            if (l == r && l != startIndex)
            {
                // System.out.println(l + " " + r);
                break;
            }
        }
        if (words[l].equals(target) || words[r].equals(target))
        {
            return answer;
        }
        return -1;
    }
}