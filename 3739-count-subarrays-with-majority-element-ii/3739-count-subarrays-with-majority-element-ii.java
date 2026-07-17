
class Solution {

    class SegmentTree {
        private int l; // inclusive
        private int r; // not inclusive
        private int boundary;
        private int val;
        private SegmentTree left;
        private SegmentTree right;
        SegmentTree(int l, int r) {
            this.l = l; 
            this.r = r; 
            this.val = 0;
            // System.out.println(l + " " + r);
            if (l != r - 1)
            {
                int m = (l + r) / 2;
                this.boundary = m;
                this.left = new SegmentTree(l, m);
                this.right = new SegmentTree(m, r);
            }
        }

        public void update(int a) {
            // System.out.println("update "+ a + " " + this.l + " "  + this.r);
            this.val++;
            if (
                this.l != this.r - 1 || 
                a != this.l
            )
            { 
                if (this.boundary <= a)
                {
                    this.right.update(a);
                }
                else
                {
                    this.left.update(a);
                }
            }
        }
    
        public int count(int l, int r) {
            // System.out.println(l + " " + r + " " + this.l + " " + this.r + " " + this.val);
            if (l == r) return 0;
            if (this.l == l && this.r == r)
            {
                return this.val;
            }
            
            if (r <= this.boundary)
            {
                return this.left.count(l, r);
            }
            else if (l >= this.boundary)
            {
                return this.right.count(l, r);
            }
            else
            {
                return this.left.count(l, this.boundary) + this.right.count(this.boundary, r);
            }

        }
    }
    public long countMajoritySubarrays(int[] nums, int target) {
        int n = nums.length;
        int[] args = new int[n + 1];
        int[] prefixSum = new int[n + 1];
        long answer = 0;
        for (int i = 0; i < n; i++)
        {
            args[i + 1] = nums[i] == target ? 1 : - 1;
        }
        for (int i = 1; i <= n; i++)
        {
            prefixSum[i] += prefixSum[i - 1] + args[i];
        }
        SegmentTree seg = new SegmentTree(-n - 1 ,n + 1);
        // System.out.println(Arrays.toString(args));
        // System.out.println(Arrays.toString(prefixSum));
        // System.out.println();
        for (int i = 0; i <= n; i++)
        {
            int ff = seg.count(-n, prefixSum[i]);
            // System.out.println(i + " index " + ff + " " + answer);
            answer += ff;
            seg.update(prefixSum[i]); 
            // System.out.println();

            
        }
        return answer;
    }
}