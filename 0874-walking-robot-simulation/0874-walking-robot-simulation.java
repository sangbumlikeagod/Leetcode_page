class Solution {
    private Integer binarySearch(int start, int end, List<Integer> sortedArray) {
        // 둘중 작은놈보다 큰수를 구한다
        int minOne = Math.min(start, end);
        int l = 0;
        int r = sortedArray.size() - 1;
        if (sortedArray.isEmpty())
        {
            return end;
        }

        while (l < r)
        {
            int m = (l + r) / 2;
            if (sortedArray.get(m) <= minOne - 1)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        // 작은놈보다 큰 인덱스를 찾도록 했음
        // 시작점이 겹치는 건 상관없지만 끝점이 겹치는건 상관이 있음 
        // 찾았는데 너무 작거나 
        if (
            (minOne == start && sortedArray.get(l) <= start) ||
            (minOne == start && sortedArray.get(l) >  end) ||
            (minOne == end && sortedArray.get(l) < end) ||
            (minOne == end && sortedArray.get(l) >= start)
        )
        {
            return end;
        }
        // 중간에 뭐가 있긴 한경우
        if (start >= end)
        {
            return sortedArray.get(l) + 1;
        }
        else
        {
            return sortedArray.get(l) - 1;
        }
    }

    public int robotSim(int[] commands, int[][] obstacles) {
        int x = 0;
        int y = 0;

        int[] dX = {0, 1, 0, -1};
        int[] dY = {1, 0, -1, 0};
        // int[] dX = {-1, 0, 1, 0};
        // int[] dY = {0, -1, 0, 1};
        int p = 0;

        List<List<Integer>> rowObstacles = new ArrayList<>();
        List<List<Integer>> columnObstacles = new ArrayList<>();

        // 모든 열 ()
        for (int i = 0; i <= 60000; i++)
        {
            rowObstacles.add(new ArrayList<>());
            columnObstacles.add(new ArrayList<>());
        }

        Arrays.sort(obstacles, (int[] a, int[] b) -> {
            return a[0] - b[0];
        });
        for (int i = 0; i < obstacles.length; i++)
        {
            columnObstacles.get(obstacles[i][1] + 30000).add(obstacles[i][0]);
        }

        Arrays.sort(obstacles, (int[] a, int[] b) -> {
            return a[1] - b[1];
        });
        for (int i = 0; i < obstacles.length; i++)
        {
            rowObstacles.get(obstacles[i][0] + 30000).add(obstacles[i][1]);
        }
        int answer = 0;
        for (int command : commands)
        {
            // 방향타를 먼저 잡고
            if (command == -1)
            {
                p =  p == 3 ? 0 : p + 1;
            }
            else if (command == -2)
            {
                p =  p == 0 ? 3 : p - 1;
            }
            else
            {
                // 여기까진 문제 없음 
                int pX = x + dX[p] * command;
                int pY = y + dY[p] * command;
                List<Integer> sortedArray;
                if (p == 0)
                {
                    sortedArray = rowObstacles.get(x + 30000);
                }
                else if (p == 1)
                {
                    sortedArray = columnObstacles.get(y + 30000);
                }
                else if (p == 2)
                {
                    sortedArray = rowObstacles.get(x + 30000);
                }
                else
                {
                    sortedArray = columnObstacles.get(y + 30000);
                }
                if (p == 1 || p == 3) 
                {
                    pX = binarySearch(x, pX, sortedArray);
                }
                else
                {
                    pY = binarySearch(y, pY, sortedArray);
                }
                x = pX;
                y = pY;
            }
            answer = Math.max(x * x + y * y, answer);
        }

        return answer;  
    }
}