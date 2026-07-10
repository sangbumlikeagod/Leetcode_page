
class UnionFind {
    public Integer value;
    private UnionFind parent;

    UnionFind(int value) {
        this.value = value;
        this.parent = this;
    }
    public UnionFind find()
    {
        if (this.parent == this)
        {
            return this;
        }
        this.parent = this.parent.find();
        return this.parent;
    }
    static public void union(UnionFind a, UnionFind b, Integer limit)
    {
        a = a.find();
        b = b.find();
        if (a.value < b.value && b.value - a.value <= limit)
        {
            a.parent = b;
        }
        else if (a.value >= b.value && a.value - b.value <= limit)
        {
            b.parent = a;
        }
    }
}

class Solution {
    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        int ql = queries.length;
        boolean[] answer = new boolean[ql];
        UnionFind[] uf = new UnionFind[n];

        int[][] nnums = new int[n][2];
        for (int i = 0; i < n; i++)
        {
            nnums[i] = new int[] {nums[i], i};
        }
        // Arrays.sort(nnums, (a, b) -> a[0] - b[0]);
        // System.out.println(Arrays.deepToString(nnums));

        for (int i = 0; i < n; i++)
        {
            uf[i] = new UnionFind(nums[i]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            UnionFind.union(uf[nnums[i][1]], uf[nnums[i + 1][1]], maxDiff);
        }
        for (int i = n - 1; i > 0; i--)
        {
            UnionFind.union(uf[nnums[i][1]], uf[nnums[i - 1][1]], maxDiff);
        }


        
        for (int i = 0; i < ql; i++)
        {
            if (uf[queries[i][0]].find() == uf[queries[i][1]].find())
            {
                answer[i] = true;
            } 
            else
            {
                answer[i] = false;
            }
        }


        return answer;
    }
}