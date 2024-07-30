class Solution
{
public:
    int numTeams(vector<int> &rating)
    {

        int n = rating.size();
        vector<vector<int>> greaterThanBoth(n, vector<int>{0, 0});
        map<int, int> leftTree;
        map<int, int> rightTree;
        int answer = 0;

        for (int i = 0; i < n; i++)
        {
            rightTree[rating[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            leftTree[rating[i]]++;
            rightTree.erase(rating[i]);

            int leftBigger = distance(leftTree.upper_bound(rating[i]), leftTree.end());
            int rightBigger = distance(rightTree.upper_bound(rating[i]), rightTree.end());
            answer += leftBigger * (n - (i + 1) - rightBigger);
            answer += rightBigger * (i - leftBigger);
        }
        return answer;
    }
};