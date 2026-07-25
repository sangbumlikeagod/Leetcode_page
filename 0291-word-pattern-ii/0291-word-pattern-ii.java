class Solution {

    private boolean backTracking(
        int idx, // 얘 써야돼
        int pIdx, // 얘 써야돼 
        String s, String pattern,
        int[] charLength
    )
    {
        // idx가 필요하고 
        //    
        int sL = s.length();
        int pL = pattern.length();
        // 가능한 sRange는 1부터 sL - idx (5 - 0) pL - pIdx - 1
        if (pIdx == pL)
        {
            if (sL != idx)
            {
                return false;
            }
            // 여기부터 진짜 검증 시작
            // System.out.println("왔닥");
            // System.out.println(Arrays.toString(charLength));

            HashMap<String, String> hMap = new HashMap<>();
            HashSet<String> visited = new HashSet<>();
            int tIdx = 0;
            for (char c : pattern.toCharArray())
            {
                int allocate = charLength[c - 'a'];
                String subS = s.substring(tIdx, tIdx + allocate);
                // System.out.println(subS);
                if (hMap.get(String.valueOf(c)) == null)
                {
                    if (visited.contains(subS)) {
                        return false;
                    }
                    hMap.put(String.valueOf(c), subS);
                    
                    visited.add(subS);
                }
                else
                {
                    if (!subS.equals(hMap.get(String.valueOf(c))))
                    {
                        return false;
                    }
                }
                tIdx += allocate;
            }
            return true;
        }
        char p = pattern.charAt(pIdx);
        if (charLength[p - 'a'] == 0)
        {
            // 제약조건 한칸씩은 남아있어야함 
            // int leftChars = sL - idx; // 3 axd
            // int leftPatternChars = pL - pIdx - 1; //2 hh
            for (int j = 1; j <= sL - idx - (pL - pIdx - 1); j++)
            {
                charLength[p - 'a'] = j;
                if (backTracking(idx + j, pIdx + 1, s, pattern, charLength))
                {
                    return true;
                }
            }
            charLength[p - 'a'] = 0;
        }
        else
        {
            if (idx + charLength[p - 'a'] > sL)
            {
                return false;
            }
            else
            {
                return backTracking(idx + charLength[p - 'a'], pIdx + 1, s, pattern, charLength);
            }
        }
        return false;
    }
    public boolean wordPatternMatch(String pattern, String s) {
        
        HashMap<String, Integer> hMap = new HashMap<>();

        // 길이는 항상 s가 크다고 가정
        if (s.length() < pattern.length()) return false;

        for (char c : pattern.toCharArray())
        {   
            if (hMap.get(String.valueOf(c)) == null)
            {
                int idx = hMap.size();
                hMap.put(String.valueOf(c), idx);
            }
        }

        int[] patternChars = new int[26];
        return backTracking(0, 0, s, pattern, patternChars);
    }
}