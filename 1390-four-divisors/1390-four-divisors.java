class Solution {
    List<Integer> primes = new ArrayList<>();
    int[] firstDegreeComposite = new int[100001];
    private void getPrimes(){
        int[] bases = new int[100001];
        for (int i = 2; i < 50000; i++)
        {
            if (bases[i] == 0)
            {
                primes.add(i);
                for (int j = i; j < 50000; j+=i)
                {
                    bases[j] = 1;
                }
            }
        }
    }

    private void getFirstDegreeComposite(){
        int n = primes.size();
        long limit = 100000;
        for (int i = 0; i < n; i++)
        {
            if ((long) primes.get(i) * primes.get(i) * primes.get(i) <= limit)
            {
                firstDegreeComposite[primes.get(i) * primes.get(i) * primes.get(i)] = primes.get(i);
            }
            for (int j = i + 1; j < n; j++)
            {
                if ((long) primes.get(i) * primes.get(j) >= limit)
                {
                    break;
                }
                firstDegreeComposite[primes.get(i) * primes.get(j)] = primes.get(i);
            }
        }   
    }
    
    public int sumFourDivisors(int[] nums) {
        getPrimes();
        getFirstDegreeComposite();
        int answer = 0;
        for (int num : nums)
        {
            if (firstDegreeComposite[num] != 0)
            {
                answer += num + 1;
                answer += firstDegreeComposite[num] + num / firstDegreeComposite[num];
            }
        }
        return answer;   
    }
}