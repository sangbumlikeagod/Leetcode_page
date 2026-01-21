class LFUCache {
    private HashMap<Integer, Queue<int[]>> keyCacheCountCache = new HashMap<>();
    private HashMap<Integer, Integer> keyValueCache = new HashMap<>();
    private HashMap<Integer, Integer> keyLevelCache = new HashMap<>();
    private int minimumCache = 0;
    private int[] informations;
    private int time = 0;
    private int capacity;
    private int currentCacheAmount = 0;

    
    public LFUCache(int capacity) {
        this.informations = new int[100001];
        this.capacity = capacity;
    }

    private boolean popMinCache(int level)
    {
        cleanCache(level);
        Queue<int[]> tmp = keyCacheCountCache.getOrDefault(level, new LinkedList<>());
        
        int[] genuineData = tmp.poll();
        keyValueCache.remove(genuineData[0]);
        keyLevelCache.remove(genuineData[0]);
        informations[genuineData[0]] = time;

        this.keyCacheCountCache.put(level, tmp);
        return tmp.isEmpty();
    }

    private boolean cleanCache(int level)
    {
        Queue<int[]> tmp = keyCacheCountCache.getOrDefault(level, new LinkedList<>());
        //다른데로 갔거나 삭제됐으면 필요없지.
        while (!tmp.isEmpty() && tmp.peek()[1] != informations[tmp.peek()[0]] )
        {
            tmp.poll();
        }
        keyCacheCountCache.put(level, tmp);
        return tmp.isEmpty();   
    }

    private void putCache(int key, int level)
    {
        cleanCache(level);
        Queue<int[]> tmp = keyCacheCountCache.getOrDefault(level, new LinkedList<>());
        
        tmp.add(new int[] {key, time});
        keyCacheCountCache.put(level, tmp);
    }

    
    public int get(int key) {
        int level = keyLevelCache.getOrDefault(key, -1);
        // System.out.println(time + "시간대 get 작업을 시작합니다.");
        
        if (level == -1)
        {
            time++;
            return -1;
        }
        else
        {
            putCache(key, level + 1);
            informations[key] = time;

            keyLevelCache.put(key, level + 1);
            boolean isEmpty = this.cleanCache(level);
            
            if (isEmpty && level == this.minimumCache)
            {
                this.minimumCache++;
            }
            
        }
        time++;
        return keyValueCache.get(key);
    }
    
    public void put(int key, int value) {
        {
            keyValueCache.put(key, value);
        }


        
        int level = keyLevelCache.getOrDefault(key, -1);
        
        
        if (level == -1)
        {
            // this.capacity
            if (this.currentCacheAmount >= this.capacity)
            {
                this.popMinCache(this.minimumCache);
            }
            else
            {
                this.currentCacheAmount++;
            }
            keyLevelCache.put(key, 1);
            putCache(key, 1);
            this.minimumCache = 1;
        }
        else
        {
            putCache(key, level + 1);
            informations[key] = time;
            boolean isEmpty = this.cleanCache(level);
            keyLevelCache.put(key, level + 1);
            if (isEmpty && level == this.minimumCache)
            {
                this.minimumCache++;
            }
        }

        informations[key] = time;
        time++;            
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */