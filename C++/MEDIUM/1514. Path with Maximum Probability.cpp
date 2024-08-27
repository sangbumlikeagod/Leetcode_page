class Solution
{
    queue<int> q;
    vector<vector<int>> adjLists{};
    vector<vector<double>> adjPoss{};
    vector<double> possibilities;

public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        adjLists = vector<vector<int>>(n, vector<int>{});
        adjPoss = vector<vector<double>>(n, vector<double>{});
        for (int i = 0; i < edges.size(); i++)
        {
            vector<int> edge = edges[i];
            adjLists[edge[0]].push_back(edge[1]);
            adjLists[edge[1]].push_back(edge[0]);
            adjPoss[edge[0]].push_back(succProb[i]);
            adjPoss[edge[1]].push_back(succProb[i]);
        }
        possibilities = vector<double>(n, 0);
        possibilities[start_node] = 1;

        q.push(start_node);
        while (!q.empty())
        {
            int node = q.front();

            q.pop();
            if (node == end_node)
                continue;
            for (int i = 0; i < adjLists[node].size(); i++)
            {
                int next = adjLists[node][i];

                double acc = adjPoss[node][i] * possibilities[node];
                cout << acc;
                if (possibilities[next] < adjPoss[node][i] * possibilities[node])
                {
                    possibilities[next] = adjPoss[node][i] * possibilities[node];
                    q.push(next);
                }
            }
        }
        return possibilities[end_node];
    }
};