class Solution {
    private int queryquery(int[][] query, int[][] target) {
        Arrays.sort(target, (a, b) -> a[0] - b[0]);
        Arrays.sort(query, (a, b) -> (a[0] + a[1]) - (b[0] + b[1]));
        int m = query.length;
        int n = target.length;
        int wi = n - 1;
        int answer = (int) 1e9;
        // PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int i = m - 1; i >= 0; i--)
        {
            // 나보다 일찍 시작한놈들은 그 기간만 가지고와
            int boundary =  query[i][0] + query[i][1];   
            while (
                wi >= 0 &&
                target[wi][0] >= boundary
            )
            {
                // 여기를 그냥 걔로 만들고
                answer = Math.min(answer, target[wi][0] + target[wi--][1]);
                // pq.add(target[wi][0] + target[wi--][1]);
            }

            // 전부다 나의 끝보다 일찍 시작하는애들임 여기부터는 
            if (i == 0 && wi >= 0)
            {
                while(
                    wi >= 0
                )
                {
                    // pq.add(
                    //     boundary + target[wi--][1]
                    // );
                    answer = Math.min(answer, boundary + target[wi--][1]);
                }
            }

            // System.out.println(i + " " + boundary + " " + " " + pq.peek());

            // if (!pq.isEmpty())
            // {
            //     answer = Math.min(answer, boundary + pq.peek());
            // }
        }
        // 그냥 아예끝나는 시간을 다 가져가도록 
        // System.out.println("answer " + answer);


        return answer;
    }

    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        // 둘다 시작하는 시간 기준으로 정렬한다
        int m = landStartTime.length;
        int n = waterStartTime.length;
        int[][] waterSD = new int[n][2];
        int[][] landSD = new int[m][2];
        for (int i = 0; i < n; i++)
        {
            waterSD[i][0] = waterStartTime[i];
            waterSD[i][1] = waterDuration[i];
        }
        for (int i = 0; i < m; i++)
        {
            landSD[i][0] = landStartTime[i];
            landSD[i][1] = landDuration[i];
        }



        Arrays.sort(waterSD, (a, b) -> a[0] - b[0]);
        Arrays.sort(landSD, (a, b) -> (a[0] + a[1]) - (b[0] + b[1]));
        // Stream.of(landSD).forEach((arg) -> System.out.print(Arrays.toString(arg) + " "));
        // System.out.println("\n");
        // Stream.of(waterSD).forEach((arg) -> System.out.print(Arrays.toString(arg) + " "));
        // System.out.println("\n");

        int answer = (int) 1e9;
        answer = Math.min(answer, queryquery(landSD, waterSD));
        // System.out.println("넘어갓");
        answer = Math.min(answer, queryquery(waterSD, landSD));

        return answer;
    }
}