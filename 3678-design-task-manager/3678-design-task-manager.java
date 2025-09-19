class Task implements Comparable<Task> {
    private int priority;
    private int user;
    private int id;

    public Task(int user, int priority, int id)
    {
        this.priority =priority;
        this.user =user;
        this.id =id;

    }
    @Override
    public int compareTo(Task t)
    {
        if (this.priority != t.priority)
        {
            return this.priority - t.priority;
        }
        return this.id - t.id;
    }

    public void setPriority(int priority)
    {
        this.priority = priority;
    }
    public int getUser()
    {
        return this.user;
    }
    public int getId()
    {
        return this.id;
    }
}
class TaskManager {
    TreeSet<Task> maps = new TreeSet<>();
    Task[] taskIds = new Task[100001];
    public TaskManager(List<List<Integer>> tasks) {
        for (List<Integer> task : tasks)
        {
            Task newTask = new Task(task.get(0), task.get(2), task.get(1));
            maps.add(newTask);
            taskIds[task.get(1)] = newTask;
        }
    }
    
    public void add(int userId, int taskId, int priority) {
        Task newTask = new Task(userId, priority, taskId);
        taskIds[taskId] = newTask;
        maps.add(newTask);
    }
    
    public void edit(int taskId, int newPriority) {
        Task task = taskIds[taskId];
        maps.remove(task);
        task.setPriority(newPriority);
        maps.add(task);
    }
    
    public void rmv(int taskId) {
        // System.out.println(taskId);
        Task task = taskIds[taskId];
        taskIds[taskId] = null;
        maps.remove(task);
    }
    
    public int execTop() {
        if (maps.isEmpty()) return -1;
        // System.out.println("before " + maps.size());

        Task task = maps.last();
        // System.out.println("after " + maps.size());
        rmv(task.getId());
        return task.getUser();

    }
}
