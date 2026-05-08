class Solution {
    private List<Integer> primes;
    private HashMap<Integer, HashSet<Integer>> hmap;

    private void getAllPrime(int maximum, List<List<Integer>> sieve){
        int[] keys = new int[maximum];
        for (int i = 2; i < maximum; i++)
        {
            if (keys[i] == 0)
            {
                primes.add(i);
                HashSet<Integer> hset = hmap.getOrDefault(i, new HashSet<>());
                for (int j = i; j < maximum; j += i)
                {
                    if (sieve.get(j).isEmpty() == false)
                    {
                        for (Integer item : sieve.get(j))
                        {
                            hset.add(item);
                        }
                    }
                    keys[j] = 1;
                }
                hmap.put(i, hset);
            }
        }
    }


    // private boolean isPrime(int x){
    //     if (x == 1) return false;
    //     for (int it : primes)
    //     {
    //         if (it * it > x) break;
    //         if (x != it && x % it == 0)
    //         {
    //             return false;
    //         }
    //     }
    //     return true;
    // }   


    // private void addPrimeDivider(int[] nums, int prime)
    // {
    //     int n = nums.length;
    //     HashSet<Integer> primeHset = hmap.getOrDefault(prime, new HashSet<>());
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (nums[i] % prime == 0)
    //         {
    //             primeHset.add(i);
    //         }
    //     }
    //     hmap.put(prime, primeHset);
    // }

    public int minJumps(int[] nums) {
        primes = new ArrayList<>();
        int n = nums.length;
        hmap = new HashMap<>();
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            maxi = Math.max(maxi, nums[i]);
        }
        List<List<Integer>> sieve = new ArrayList<>(maxi + 1);
        for (int i = 0; i< maxi + 1; i++)
        {
            sieve.add(new ArrayList<>());
        }
        // Arrays.fill(sieve, new ArrayList<>());
        // Collections.fill(sieve, new ArrayList<>());
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= maxi)
            {
                sieve.get(nums[i]).add(i);
            }
        }
        // System.out.println(sieve);

        getAllPrime(maxi + 1, sieve);

        // System.out.println(hmap);

        int[] visited = new int[n];
        Queue<Integer> q = new LinkedList<>();
        Queue<Integer> nq = new LinkedList<>();
        visited[0] = 1;
        q.add(0);
        int answer = 0;

        while (q.isEmpty() == false)
        {
            while (q.isEmpty() == false)
            {
                int next = q.poll();
                //act1 
                if (next == n - 1) return answer;
                if (next > 0 && visited[next - 1] == 0)
                {
                    visited[next - 1] = 1;
                    nq.add(next - 1);
                }
                if (visited[next + 1] == 0)
                {
                    visited[next + 1] = 1;
                    nq.add(next + 1);
                }


                if (hmap.get(nums[next]) != null)
                {
                    // 지랄시작 
                    // 여기서 다 보는게 문제 
                    HashSet<Integer> hset = hmap.get(nums[next]);
                    for (int item : hset)
                    {
                        if (visited[item] == 0)
                        {
                            visited[item] = 1;
                            nq.add(item);
                        }
                    }
                    hmap.remove(nums[next]);
                }
            }
            
            q = nq;
            nq = new LinkedList<>();
            answer++;
        }
        
        return answer;
    }
}