class Solution {
    TreeMap<Integer, Integer> tMapMinK = new TreeMap<>();
    TreeMap<Integer, Integer> tMapRest = new TreeMap<>();
    Integer tMapMinKSize = 0;
    Long sumOfDist_1 = (long) 0;
    Integer k_1;


    private Long eraseTreeMap(Integer x)
    {
        Integer v = tMapMinK.get(x);
        if (v != null)
        {
            sumOfDist_1 -= x;
            if (v == 1)
            {
                tMapMinK.remove(x);
            }
            else
            {
                tMapMinK.put(x, v - 1);
            }

            if (!tMapRest.isEmpty())
            {
                Integer replace = tMapRest.firstKey();
                sumOfDist_1 += replace;

                if (tMapRest.get(replace) == 1)
                {
                    tMapRest.remove(replace);
                }
                else
                {
                    tMapRest.put(replace, tMapRest.get(replace) - 1);
                }
                tMapMinK.put(replace, tMapMinK.getOrDefault(replace, 0) + 1);
            }
        }
        else if (v == null && !tMapRest.isEmpty())
        {
            Integer tmp = tMapRest.get(x);
            if (tmp == 1)
            {
                tMapRest.remove(x);
            }
            else
            {
                tMapRest.put(x, tmp - 1);
            }
        }
        return sumOfDist_1;
    }

    private Long addTreeMap(Integer x)
    {
        if (tMapMinKSize < k_1)
        {
            tMapMinK.put(x, tMapMinK.getOrDefault(x, 0) + 1);
            sumOfDist_1 += x;
            return sumOfDist_1;
        }

        Integer limit =  tMapMinK.lastKey();
        if (x <= limit)
        {   
            System.out.println(limit);
            if (tMapMinK.get(limit) == 1)
            {
                tMapMinK.remove(limit);
            }
            else
            {
                tMapMinK.put(limit, tMapMinK.get(limit) - 1);
            }
            sumOfDist_1 -= limit;

            tMapRest.put(limit, tMapRest.getOrDefault(limit, 0) + 1);

            tMapMinK.put(x, tMapMinK.getOrDefault(x, 0) + 1);

            sumOfDist_1 += x;
        }
        else
        {
            tMapRest.put(x, tMapRest.getOrDefault(x, 0) + 1);
        }
        return sumOfDist_1;
    } 



    public long minimumCost(int[] nums, int k, int dist) {
        long answer = (long) 1e15;
        int n = nums.length;
        k_1 = k - 1;

        
        for (int i = 0; i <= dist; i++)
        {
            addTreeMap(nums[i]);
            tMapMinKSize++;
        }

        for (int i = 0; i < n - dist - 1; i++)
        {
            // int cnt = tMap.get(nums[i]);
            eraseTreeMap(nums[i]);
            tMapMinKSize--;
            // System.out.println(i + " " + ttmp);
            // System.out.println(tMapMinK);
            // System.out.println(tMapRest);
            long tmp = addTreeMap(nums[i + dist + 1]);
            tMapMinKSize++;
            // System.out.println(i + " " + tmp);
            // System.out.println(tMapMinK);
            // System.out.println(tMapRest);
            // System.out.println(i + " " + tmp);
            // System.out.println("\n\n");
            answer = Math.min(answer, tmp + nums[0]);
        }
        return answer;

        // k - 1개의 합중 제일 작은것 구하게하기 
    }
}