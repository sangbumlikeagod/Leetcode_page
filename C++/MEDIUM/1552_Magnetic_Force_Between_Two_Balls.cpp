class Solution
{
public:
    int maxDistance(vector<int> &position, int m)
    {
        int minAns = 1;
        int maxAns = 1e9;
        int beforeMax = -1;
        sort(position.begin(), position.end());
        while (minAns < maxAns)
        {
            cout << minAns << '\n';
            int midAns = (minAns + maxAns) / 2;
            int isValid = check(position, midAns, m);
            if (isValid != -1)
            {
                beforeMax = isValid;
                minAns = isValid + 1;
            }
            else
            {
                maxAns = midAns;
            }
        }
        return beforeMax;
    }

private:
    int check(vector<int> &position, int limit, int m)
    {
        int startIndex = 0;
        int distance = 0;
        int remains = m;
        int minimum = 1e9;
        while (remains && startIndex < position.size() - 1)
        {
            if (distance + position[startIndex + 1] - position[startIndex] >= limit)
            {
                remains--;
                minimum = min(minimum, distance);
                distance = 0;
            }
            else
            {
                distance += position[startIndex + 1] - position[startIndex];
            }
            startIndex++;
        }
        return remains ? -1 : minimum;
    }
};