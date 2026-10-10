class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        int n = nums1.length;
        int[] nums3 = new int[n + 1];
        long answer = 0;
        for (int i = 0; i < n; i++)
        {
            nums3[i + 1] = Math.abs(nums1[i] - nums2[i]);
        }
        Arrays.sort(nums3);
        long k3 = k1 + k2;
        int count = 1;
        System.out.println(Arrays.toString(nums3));
        int i = n;
        for (; i > 0; i--)
        {
            long diff = nums3[i] - nums3[i - 1];
            if (diff * count <= k3)
            {
                k3 -= diff * count;
                count++;
                nums3[i] = 0;
            }
            else
            {
                long s = (nums3[i] - k3 / count);
                answer += s * s * (count - (k3 % count));
                answer += (s - 1) * (s - 1) * (k3 % count);
                nums3[i] = 0;
                break;
            }
        }

        for (; i > 0; i--)
        {
            answer += (long) nums3[i] * nums3[i]; 
        }
        return (long) answer;
    }
}