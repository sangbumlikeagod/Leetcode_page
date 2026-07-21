class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        int l = s.length();
        int x = 0;
        List<Integer> arr = new ArrayList<>();
        int answer = 0;
        for (int i = 0; i < l; i++)
        {
            char c = s.charAt(i);
            if (c == '1')
            {
                answer++;
                if (x > 0)
                {
                    x++;
                }
                else
                {
                    arr.add(x);
                    x = 1;
                }
            }
            else
            {
                if (x < 0)
                {
                    x--;
                }
                else
                {
                    arr.add(x);
                    x = -1;
                }
            }
        }
        arr.add(x);
        int m = 0;
        for (int i = 0; i < arr.size() - 2; i++)
        {
            if (
                arr.get(i) < 0 &&
                arr.get(i + 1) > 0 &&
                arr.get(i + 2) < 0
            )
            {
                m = Math.max(m, - arr.get(i) - arr.get(i + 2));
            }
        }
        return answer + m;
    }
}