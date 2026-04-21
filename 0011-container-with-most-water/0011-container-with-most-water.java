class Solution {
    public int maxArea(int[] height) {
        List<List<Integer>> lst = new ArrayList<>();
        int l = height.length;
        for (int i = 0; i < l; i++)
            {
                lst.add(Arrays.asList(height[i], i));
            }

        Collections.sort(lst, (a, b)->{
            if (a.get(0) != b.get(0))
            {
                return b.get(0) - a.get(0);
            }
            else
            {
                return a.get(1) - b.get(1);
            }
        });

        // System.out.println(lst);

        List<List<Integer>> ansLst = new ArrayList<>();
        int answer = 0;
        for (int i = 0; i < l; i++)
        {
            // 바로앞의놈이 가장 인덱스가 앞이란걸 보장하도록
            while (!ansLst.isEmpty() && ansLst.get(ansLst.size() - 1).get(1) > lst.get(i).get(1))
            {
                answer = Math.max(answer, (ansLst.get(ansLst.size() - 1).get(1) - lst.get(i).get(1)) * lst.get(i).get(0));
                ansLst.remove(ansLst.size() - 1);
            }
            if (!ansLst.isEmpty())
            {
                answer = Math.max(answer, (lst.get(i).get(1) - ansLst.get(ansLst.size() - 1).get(1)) * lst.get(i).get(0));
                
            }
            if (ansLst.isEmpty())
            {
                ansLst.add(lst.get(i));
            }
            // System.out.println(i + " " +  ansLst);
        }


        Collections.sort(lst, (a, b)->{
            if (a.get(0) != b.get(0))
            {
                return b.get(0) - a.get(0);
            }
            else
            {
                return b.get(1) - a.get(1);
            }
        });
        // System.out.println(lst);
        ansLst = new ArrayList<>();



        for (int i = 0; i < l; i++)
        {
            // 바로앞의놈이 가장 인덱스가 앞이란걸 보장하도록
            while (!ansLst.isEmpty() && ansLst.get(ansLst.size() - 1).get(1) < lst.get(i).get(1))
            {
                answer = Math.max(answer, (lst.get(i).get(1) - ansLst.get(ansLst.size() - 1).get(1)) * lst.get(i).get(0));
                ansLst.remove(ansLst.size() - 1);
            }
            if (!ansLst.isEmpty())
            {
                answer = Math.max(answer, (ansLst.get(ansLst.size() - 1).get(1) - lst.get(i).get(1)) * lst.get(i).get(0));
                
            }
            if (ansLst.isEmpty())
            {
                ansLst.add(lst.get(i));
            }
            // System.out.println(i + " " +  ansLst);
        }
        
        return answer;
    }
}