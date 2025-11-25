class Solution {
    public int smallestRepunitDivByK(int k) {
        List<Integer> initial = init(k);
        int answer = initial.getFirst();
        int remainder = initial.getLast();
        HashSet<Integer> set = new HashSet<>();
        // System.out.println(answer + " " + remainder);
        set.add(remainder);
        while (true)
        {
            if (remainder == 0)
            {
                return answer;
            }

            answer++;
            remainder = ((remainder * 10) + 1) % k;
            if (set.contains(remainder)) break;
            set.add(remainder);
        }
        return -1;

    }

    private List<Integer> init(int k)
    {
        int start = 1;
        int val = 1;
        int kCopy = k;
        while (k > 1)
        {
            k /= 10;
            start++;    
            val *= 10;
            val += 1;
        }
        return List.of(start, val % kCopy);
    }
}