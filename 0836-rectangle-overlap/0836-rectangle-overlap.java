class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        if (rec2[3] < rec1[3] && rec2[2] < rec1[2])
        {
            int[] rec3 = rec1;
            rec1 = rec2;
            rec2 = rec3;
        }
        return rec1[2] > rec2[0] && rec1[3] > rec2[1];
    }
}