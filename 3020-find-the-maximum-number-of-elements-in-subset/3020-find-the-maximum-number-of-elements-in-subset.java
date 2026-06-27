class Solution {
    int[] visited;
    ArrayList<int[]> cnts = new ArrayList();
    long MXM = (long) 1e9;
    private int bs(int l, int r, int target)
    {
        // System.out.println(l + " " + r + " " + target);
        while (l < r)
        {
            int m = (l + r) / 2;
            if (cnts.get(m)[0] == target)
            {
                return m;
            }
            else if (cnts.get(m)[0] > target)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return l;
    }
    public int maximumLength(int[] nums) {
        Arrays.sort(nums);
        int len = nums.length;
        visited = new int[len];
        int last = nums[0];
        int answer = 1;

        int cnt = 0;
        for (int num : nums)
        {
            if (last != num)
            {
                // System.out.println(last + "  " + cnt);
                cnts.add(
                    new int[] {last, cnt}
                );
                if (last == 1)
                {
                    if (cnt % 2 == 0)
                    {
                        cnt--;
                    }
                    answer = cnt;
                }
                cnt = 1;
            }
            else
            {
                cnt++;
            }
            last = num;
        }
        // System.out.println(last + "  " + cnt);
        cnts.add(
            new int[] {last, cnt}
        );
        if (last == 1)
        {
            if (cnt % 2 == 0)
            {
                cnt--;
            }
            answer = cnt;
        }

        for (int i = 0; i < cnts.size(); i++)
        {
            if (visited[i] == 1) {continue;}
            

            int target_idx = i;
            int local_ans = 1;
            while (target_idx < cnts.size())
            {
                if (cnts.get(target_idx)[1] >= 2 && cnts.get(target_idx)[0] != 1)
                {
                    visited[target_idx] = 1;
                    long target = (long) cnts.get(target_idx)[0] * cnts.get(target_idx)[0];
                    if (target < MXM)
                    {
                        int ntgx = bs(target_idx, cnts.size() - 1, (int) target);
                        if (cnts.get(ntgx)[0] == target)
                        {
                            target_idx= ntgx;
                            local_ans += 2;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            answer = Math.max(answer, local_ans);
        }


        return answer;
    }
}