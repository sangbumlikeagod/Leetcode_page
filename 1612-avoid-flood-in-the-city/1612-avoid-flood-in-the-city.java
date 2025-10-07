class Solution {
    HashMap<Integer, Integer> kv = new HashMap<>();
    private int getNewKey(int next)
    {
        if (kv.containsKey(next))
        {
            return kv.get(next);
        }
        kv.put(next, kv.size());
        return kv.size() - 1;
    }
    public int[] avoidFlood(int[] rains) {
        TreeSet<Integer> s = new TreeSet<>();

        
        int[] isFull = new int[rains.length + 1];
        int[] answer = new int[rains.length];
        for (int i = 0; i < rains.length; i++)
            {
                answer[i] = -1;
            }
        
        for (int i = 0; i < rains.length; i++)
            {
                if (rains[i] == 0)
                {
                    s.add(i);
                }
                else
                {
                    int key = getNewKey(rains[i]);
                    if (isFull[key] != 0)
                    {
                        Integer data = s.ceiling(isFull[key]);
                        isFull[key] = i + 1;  
                        if (data == null)
                        {
                            return new int[] {};
                        }

                        s.remove(data);
                        answer[data] = rains[i];
                    }
                    else
                    {
                        isFull[key] = i + 1;
                    }
                }
                    
            }
        while (!s.isEmpty())
        {
            Integer next = s.pollFirst();
            answer[next] = 1;
        }
        return answer;
    }
}