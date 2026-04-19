class Solution {
    public int maxDistance(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;

        int i = 0, j = 0;
        int answer = 0;
        for (; i < n; i++)
        {

            while (j < m && (j < i || nums1[i] <= nums2[j]))
            {
                answer = Math.max(answer, j++ - i);
            }
        }
        return answer;
    }
}