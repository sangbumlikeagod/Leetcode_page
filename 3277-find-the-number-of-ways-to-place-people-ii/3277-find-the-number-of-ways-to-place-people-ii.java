class Solution {
    public int numberOfPairs(int[][] points) {
        int ll = points.length;
        ArrayList<ArrayList<Integer>> xAxis = new ArrayList<>();
        ArrayList<ArrayList<Integer>> yAxis = new ArrayList<>();
        HashMap<Integer, Integer> xMap = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> yMap = new HashMap<Integer, Integer>();
        for (int i = 0; i < 1001; i++)
        {
            xAxis.add(new ArrayList<>());
            yAxis.add(new ArrayList<>());
        }

        Arrays.sort(points, (A, B) -> {
            return A[1] - B[1];
        });

        for (int i = 0; i < ll; i++)
        {
            if (yMap.getOrDefault(points[i][1], -1) == -1)
            {
                yMap.put(points[i][1], yMap.size());
            }
        }

        Arrays.sort(points, (A, B) -> {
            return A[0] - B[0];
        });
        for (int i = 0; i < ll; i++)
        {
            if (xMap.getOrDefault(points[i][0], -1) == -1)
            {
                xMap.put(points[i][0], xMap.size());
            }
        }
        // x를 기준으로 정렬됐기 때문에 yAxis들은 정렬된 리스트다.
        for (int i = 0; i < ll; i++)
        {
            int nX = xMap.get(points[i][0]);
            int nY = yMap.get(points[i][1]);
            xAxis.get(nX).add(nY);
            yAxis.get(nY).add(nX);
        }
        // 정렬된 애들중에 찾기까지 완료 
        int answer = 0;
        for (int i = 0; i <= 1000; i++)
        {
            if (xAxis.get(i).isEmpty()) continue;
            for (Integer arg : xAxis.get(i))
            {
                // 여기까지 웃기게도 1000개로 고정됨
                int minimi = 1001;
                for (int j = arg; j >= 0; j--)
                {
                    int biggerThat = Collections.binarySearch(yAxis.get(j), j == arg ? i + 1 : i);
                    if (0 <= biggerThat)
                    {
                        int bigger = yAxis.get(j).get(biggerThat);
                        if (bigger >= minimi) continue;
                        minimi = bigger;
                        answer++;
                    }
                    else if (-biggerThat <= yAxis.get(j).size())
                    {
                        int bigger = yAxis.get(j).get(-biggerThat - 1);
                        if (bigger >= minimi) continue;
                        minimi = bigger;
                        answer++;
                    }
                }
            }
        }
        return answer;
    }
}