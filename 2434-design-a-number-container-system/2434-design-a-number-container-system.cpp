class NumberContainers {
public:
    unordered_map<int, map<int, int>> superMap;
    unordered_map<int, int> indexMap;
    NumberContainers() {
        // 숫자별 정렬
    }
    
    void change(int index, int number) {
        int prev = 0;
        if (indexMap.find(index) != indexMap.end())
        {
            prev = indexMap[index];
            superMap[prev].erase(index);            
        }
        indexMap[index] = number;
        superMap[number][index]++;
    }
    
    int find(int number) {
        if (superMap[number].empty()) return -1;

        return (superMap[number].begin()) -> first;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */