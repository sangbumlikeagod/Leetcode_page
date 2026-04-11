class Node {
private:
    int before;
public:
    int index;
public: 
    Node(int before, int index) {
        this -> index = index;
        this -> before = before;
    }

    int getDistance() {
        return index - before;
    }

};
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int answer = 200001;
        int n = nums.size();

        vector<vector<Node*>> nodeVec(n + 1, vector<Node*>{});

        for (int i = 0; i < n; i++)
        {
            int nodeRowSize = nodeVec[nums[i]].size();
            int before = nodeRowSize == 0 ? -2000000 : \
                nodeVec[nums[i]][nodeRowSize - 1] -> index;

            if (nodeRowSize != 0)
            {
                answer = min(answer, \
                    (nodeVec[nums[i]][nodeRowSize - 1] -> getDistance() + \
                    (i - nodeVec[nums[i]][nodeRowSize - 1] -> index)) * 2
                );
            }

            nodeVec[nums[i]].push_back(new Node(before, i));
        }

        return answer == 200001 ? -1 : answer;
    }
};