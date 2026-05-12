class Solution {
    public int minimumEffort(int[][] tasks) {
        int answer = 0;
        Arrays.sort(tasks, (int[] taskA, int[] taskB) -> {
            return (taskA[1] - taskA[0]) - (taskB[1] - taskB[0]);
        });

        for (int[] task : tasks){

            answer += task[0];
            if (task[1] > answer)
            {
                answer = task[1];
            }
        }
        
        return answer;

    }
}