class Solution
{
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
    {
        vector<vector<pair<int, int>>> adjacencyList(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int nodeA = edges[i][0], nodeB = edges[i][1];
            adjacencyList[nodeA].emplace_back(nodeB, i);
            adjacencyList[nodeB].emplace_back(nodeA, i);
        }

        // distances 벡터를 초기화하고 0과 1 모두 0으로 해놓음
        vector<vector<int>> distances(n, vector<int>(2, INT_MAX));
        distances[source][0] = distances[source][1] = 0;

        runDijkstra(adjacencyList, edges, distances, source, 0, 0);

        // 0번째 요소와의 거리 차이를 구한다 target - destination[0] 의 값이라면 남은 비용
        int difference = target - distances[destination][0];
        if (difference < 0)
            return {};
        runDijkstra(adjacencyList, edges, distances, source, difference, 1);
        if (distances[destination][1] < target)
            return {};
        // 1번에 대해서도
        for (auto &edge : edges)
        {
            if (edge[2] == -1)
                edge[2] = 1;
        }
        return edges;
    }

private:
    void runDijkstra(const vector<vector<pair<int, int>>> &adjacencyList, vector<vector<int>> &edges, vector<vector<int>> &distances, int source, int difference, int run)
    {
        int n = adjacencyList.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> priorityQueue;
        priorityQueue.push({0, source});
        distances[source][run] = 0;

        while (!priorityQueue.empty())
        {
            // pair을 얻는 쉬운 방법
            auto [currentDistance, currentNode] = priorityQueue.top();
            priorityQueue.pop();

            // 현재 거리가 지금 노드에서 1또는 0까지의 거리와 같다면
            if (currentDistance > distances[currentNode][run])
                continue;

            // 모든 이웃 노드들에 대해서
            for (auto &neighbor : adjacencyList[currentNode])
            {

                // 다음 노드의 edge인덱스를 담고 가중치를 확인
                int nextNode = neighbor.first, edgeIndex = neighbor.second;
                int weight = edges[edgeIndex][2];
                // weight가 -1 이라면 1로 바꾼다.
                if (weight == -1)
                    weight = 1;
                // run이 1이고 edges의 인덱스가 -1과 같을 경우
                if (run == 1 && edges[edgeIndex][2] == -1)
                {
                    // 새로운 가중치를 구해준다. 다음노드의 0번 - 이번노드의 1번? 부족한만큼을 run이 1일때 선언해주고
                    int newWeight = difference + distances[nextNode][0] - distances[currentNode][1];
                    if (newWeight > weight)
                    {
                        edges[edgeIndex][2] = weight = newWeight;
                    }
                }
                // 0번과 1번에 상관없이 거치는 코드 지금 노드의 비용에서다음 노드로 가는게 더 낮은비용일 경우 업데이트 해주고 그노드 추가해주는 내용
                // 내 고민 1번과 2번을 한번에 해결하기 위해서 1로 바꾸고 0을 더하는거다 0일때는 더 큰값이 존재하는지를 확인한다. 가장 작은값이 초과라면 볼것도 없다, 그리고 1번에서는 아예 -1을 겪은 답은 무조건 답이되니까
                // 답에 넣어주고 오직 -1 없이 최소값이 끝부분에 다다른 놈만을 처리해준다. 그러면 답이 다 나온다,
                if (distances[nextNode][run] > distances[currentNode][run] + weight)
                {
                    distances[nextNode][run] = distances[currentNode][run] + weight;
                    priorityQueue.push({distances[nextNode][run], nextNode});
                }
            }
        }
    }
};
static const auto mynameisbarryallen = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();