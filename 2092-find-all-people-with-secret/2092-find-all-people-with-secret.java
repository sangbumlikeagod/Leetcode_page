class UnionFind {
    public int idx;
    public boolean known;
    public UnionFind parent;

    public UnionFind(int idx ){
        this.known = false;
        this.idx = idx;
        this.parent = this;
    }

    public UnionFind find() {
        if (this.parent == this)
        {
            return this;
        }
        this.parent = this.parent.find();
        this.known = this.parent.known;
        return this.parent;
    }

    public static void union(UnionFind a, UnionFind b)
    {
        a = a.find();
        b = b.find();
        if (a.idx <= b.idx)
        {
            b.parent = a;
        }
        else
        {
            a.parent = b;
        }
        b.known = b.known || a.known;
        a.known = b.known || a.known;
    }
    
}
class Solution {
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        List<Integer> answer = new ArrayList<>();
        Arrays.sort(meetings, (x, y) -> {
            return x[2] - y[2];
        });
        int[] knowTruth = new int[n];
        UnionFind[] knownTruth = new UnionFind[n];
        for (int i = 0; i < n; i++)
        {
            knownTruth[i] = new UnionFind(i);
        }
        knowTruth[0] = 1;
        knowTruth[firstPerson] = 1;

        knownTruth[0].known=true;
        knownTruth[firstPerson].known=true;


        int[] idxLeap = new int[100001];
        for (int[] meeting : meetings)
        {
            // System.out.println(Arrays.toString(meeting));
            idxLeap[meeting[2]]++;
        }

        int idx = 0, m = meetings.length;
        while (idx < m)
        {
            int leap = idxLeap[meetings[idx][2]];
            // System.out.println(idx + " " + leap + " ");

            // boolean getToKnown = false;
            // for (int nx = idx; nx < idx +leap; nx++)
            // {
            //     if (
            //         knowTruth[meetings[nx][0]] == 1 ||
            //         knowTruth[meetings[nx][1]] == 1
            //     )
            //     {
            //         getToKnown = true;
            //         break;
            //     }
            // }

            // if (getToKnown)
            // {
                for (int nx = idx; nx < idx + leap; nx++)
                {
                    knownTruth[meetings[nx][0]].known = knowTruth[meetings[nx][0]] == 1;
                    knownTruth[meetings[nx][0]].parent = knownTruth[meetings[nx][0]];
                    knownTruth[meetings[nx][1]].known = knowTruth[meetings[nx][1]] == 1;
                    knownTruth[meetings[nx][1]].parent = knownTruth[meetings[nx][1]];

                }
                for (int nx = idx; nx < idx + leap; nx++)
                {
                    UnionFind.union(knownTruth[meetings[nx][0]], knownTruth[meetings[nx][1]]);
                    // if (knowTruth[meetings[nx][0]] == 1)
                    // {
                    //     knowTruth[meetings[nx][1]] = 1;
                    // }
                    // else if (knowTruth[meetings[nx][1]] == 1)
                    // {
                    //     knowTruth[meetings[nx][0]] = 1;
                    // }
                    // knowTruth[meetings[nx][1]] = 1;
                }
                for (int nx = idx + leap - 1; nx >= idx; nx--)
                {
                    if (knownTruth[meetings[nx][0]].find().known)
                    {
                        knowTruth[meetings[nx][0]] = 1;
                    }
                    if (knownTruth[meetings[nx][1]].find().known)
                    {
                        knowTruth[meetings[nx][1]] = 1;
                    }
                    // knowTruth[meetings[nx][1]] = 1;
                }
            // }
            // System.out.println(Arrays.toString(knowTruth));
            idx += leap;
        }

        for (int i = 0; i < n; i++)
        {
            if (knowTruth[i] == 1)
            {
                answer.add(i);
            }
        }

        return answer;
    }
}