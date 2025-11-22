class LRUCache {
    TreeMap<Integer, Integer> timers;
    HashMap<Integer, Integer> lastTime;
    HashMap<Integer, Integer> lastValue;
    Integer CAPA;
    Integer time = 0;
    public LRUCache(int capacity) {
        timers = new TreeMap<>();
        lastTime = new HashMap<>();
        lastValue = new HashMap<>();
        CAPA = capacity;
    }
    
    public int get(int key) {
        Integer value = lastValue.get(key);
        if (value == null)
        {
            return -1;
        }
        else
        {
            // 있으면 시간 업데이트 해줘야함
            Integer lt =lastTime.get(key);
            timers.remove(lt);
            lastTime.put(key, time);
            timers.put(time, key);
            time++;
            return value;
        }
    }
    
    public void put(int key, int value) {
        if (lastTime.get(key) == null)
        {
            if (timers.size() >= CAPA)
            {
                Integer lastRecent = timers.firstKey();
                Integer keyId = timers.get(lastRecent);

                timers.remove(lastRecent);
                lastTime.remove(keyId);
                lastValue.remove(keyId);
            }        
        }
        else
        {
            Integer lt =lastTime.get(key);
            timers.remove(lt);
            lastTime.put(key, time);
            timers.put(time, key);
        }
        timers.put(time, key);
        lastTime.put(key, time);
        lastValue.put(key, value);
        time++;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */