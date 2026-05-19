class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int i = 0, j = 0;
        int n1 = nums1.length;
        int n2 = nums2.length;
        while (i < n1 && j < n2)
        {
            if (nums1[i] == nums2[j])
            {
                return nums1[i];
            }
            if (i != n1 && nums1[i] < nums2[j])
            {
                i++;
            } 
            else if (j != n2 && nums2[j] < nums1[i])
            {
                j++;
            }
        }
        return -1;
    }
}