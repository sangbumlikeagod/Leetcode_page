class Solution {
    class Task implements Comparable<Task> {
        public Integer weight;
        public Integer index;
        public Integer time;

        Task(
            int weight,
            int index,
            int time
        ) {
            this.weight = weight;
            this.index = index;
            this.time = time;
        }
 
        @Override
        public int compareTo(Task b) {
            if (this.time - b.time != 0)
            {
                return this.time - b.time;
            }
            if (this.weight - b.weight != 0)
            {
                return this.weight - b.weight;
            }
            return this.index - b.index;
        }
    }
    public int[] assignTasks(int[] servers, int[] tasks) {
        int m = servers.length;
        int n = tasks.length;
        Integer statictime = 0;
        // unassigned
        PriorityQueue<Task> q = new PriorityQueue<>();
        PriorityQueue<Task> QAssigned = new PriorityQueue<>();
        // Task Task1 = new Task(503, 34, 0);
        // Task Task2 = new Task(503, 22, 0);
        // System.out.println(
        //     Task1.compareTo(Task2)
        // );


        for (int i = 0; i < m; i++)
        {
            int server = servers[i];
            q.add(new Task(server, i, 0));
        }
        // System.out.println(
        //     q.peek().weight
        // );
        int[] answer = new int[n];
        for (int j = 0; j < n; j++)
        {
            if (q.isEmpty())
            {
                statictime = QAssigned.peek().time;
            }
            else if (statictime < j)
            {
                statictime++;
            }

            while (
                !QAssigned.isEmpty() && 
                QAssigned.peek().time <= statictime
            )
            {
                Task freeTask = QAssigned.poll();
                // System.out.println(
                //     statictime + " " + 
                //     "\t " + 
                //     freeTask.time + " " + 
                //     freeTask.index + " " +
                //     freeTask.weight
                // );
                q.add(
                    new Task(
                        freeTask.weight,
                        freeTask.index, 
                        0
                    )
                );
            }

            Task taskAssigned = q.poll();   
            // System.out.println(
            //     taskAssigned.time + " " + 
            //     taskAssigned.index + " " +
            //     taskAssigned.weight
            // );
            answer[j] = taskAssigned.index;
            QAssigned.add(new Task(
                taskAssigned.weight,
                taskAssigned.index,
                statictime + tasks[j]
            ));
        }
        return answer;

    }
}