class UnionFind {
    public int val;
    public UnionFind parent;

    public UnionFind find() {
        if (parent.val == val)
        {
            return this;
        }
        parent = parent.find();
        return parent;
    }
    public static void union(UnionFind a, UnionFind b) {
        a = a.find(); b = b.find();
        if (a.val < b.val)
        {
            b.parent = a;
        }
        else
        {
            a.parent = b;
        }
    }
    public UnionFind(int val)
    {
        this.val = val;
        this.parent = this;
    }
}

class Solution {
    public int[] processQueries(int c, int[][] connections, int[][] queries) {
        UnionFind[] grids = new UnionFind[c + 1];
        ArrayList<Integer> answer = new ArrayList<>();
        for (int i = 0; i <= c ; i++)
        {
            grids[i] = new UnionFind(i);
        } 
        for (int[] connection : connections)
        {
            UnionFind.union(grids[connection[0]], grids[connection[1]]);
        }


        HashMap<Integer, ArrayList<Integer>> maps = new HashMap<>();
        HashMap<Integer, Integer> indexMaps = new HashMap<>();
        int[] onOff = new int[c + 1];
        for (int i = 1; i <= c; i++)
        {
            if (!maps.containsKey(grids[i].find().val))
            {
                maps.put(grids[i].find().val, new ArrayList<>());
                indexMaps.put(grids[i].find().val, 0);
            }
            maps.get(grids[i].find().val).add(i);
        }

        // 여기서부터 새로운 데이터 찾기
        for (int[] query : queries)
        {
            if (query[0] == 1)
            {
                if (onOff[query[1]] == 0)
                {
                    answer.add(query[1]);
                }
                else
                {
                    int groupKey = grids[query[1]].find().val;
                    ArrayList<Integer> group = maps.get(groupKey);
                    int groupIndex = indexMaps.get(groupKey);
                    while (groupIndex != group.size() && onOff[group.get(groupIndex)] != 0)
                    {
                        groupIndex++;
                    }
                    if (groupIndex == group.size())
                    {
                        answer.add(-1);
                    }
                    else
                    {
                        answer.add(group.get(groupIndex));
                    }
                    indexMaps.put(groupKey, groupIndex);
                }
            }
            else
            {
                onOff[query[1]] = 1;
            }
        }
        
    
        return answer.stream().mapToInt(i -> i).toArray();
    }
}