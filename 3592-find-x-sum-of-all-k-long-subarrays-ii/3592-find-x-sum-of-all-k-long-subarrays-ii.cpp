

class KitKatSet {
public:
    KitKatSet(int threshold)
    {
        this->threshold = threshold;
        this->res = 0;
    }

public: 
    void put(int num) {
        this->removeFromKitkat({occurence[num], num});
        occurence[num]++;
        this->InsertToKitkat({occurence[num], num});
    }

    void remove(int num)
    {
        this->removeFromKitkat({occurence[num], num});
        occurence[num]--;
        if (occurence[num])
        {
            this->InsertToKitkat({occurence[num], num});
        }
    }
    
    long long get(){
        return this->res;
    }
private:
    void InsertToKitkat(const pair<int, int>& pairD)
    {
        // 아직 unique의 개수가 x보다 모자르거나, large중 제일 작은애보다 커
        if (largeKitkat.size() < this->threshold || pairD > *largeKitkat.begin())
        {
            largeKitkat.insert(pairD);
            this -> res += (long long) pairD.first * pairD.second;
            // 만약 더 커졌어 그러면 result에서 small에 쳐넣는다.
            if (largeKitkat.size() > this->threshold)
            {
                
                pair<int, int> erasy = *largeKitkat.begin();
                this->res -= (long long) erasy.first * erasy.second;
                largeKitkat.erase(erasy);
                smallKitkat.insert(erasy);
            }
        }
        else {
            smallKitkat.insert(pairD);
        }
    }
    void removeFromKitkat(const pair<int, int>& pairD){
        // 처음부터 얘가 몇번 등장하고 그값이 얼마인지 안다고 봐야함

        // large에서 빼야한다면.
        if (pairD >= *largeKitkat.begin())
        {   
            largeKitkat.erase(pairD);
            this->res -= (long long) pairD.first * pairD.second;
            // small이 비어있지 않으면 하나 다시 넘겨준다.
            if (smallKitkat.size())
            {

                pair<int, int> addy = *(--smallKitkat.end());
                this->res += (long long) addy.first * addy.second;
                smallKitkat.erase(addy);
                largeKitkat.insert(addy);
            }
        }
        else
        {
            smallKitkat.erase(pairD);
        }
    }

private:
    int threshold;
    long long res;
    unordered_map<int, int> occurence;
    set<pair<int, int>> smallKitkat;
    set<pair<int, int>> largeKitkat;

};


class Solution {
public:
    
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        KitKatSet* kitkat = new KitKatSet(x);
        vector<long long> answer;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            kitkat->put(nums[i]);
            if (i >= k)
            {
                kitkat->remove(nums[i - k]);
            }   
            if (i >= k - 1)
            {
                answer.push_back(kitkat->get());
            }
        }
        return answer;   
    }
};