class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
		    // 인접 매트릭스, in 앤 out
        unordered_map<int, deque<int>> adjacencyMatrix;
        unordered_map<int, int> inDegree, outDegree;

        // Build the adjacency list and track in-degrees and out-degrees
        for (const auto& pair : pairs) {
            int start = pair[0], end = pair[1];
            adjacencyMatrix[start].push_back(end);
            // 방향을 설정 
            outDegree[start]++;
            inDegree[end]++;
        }
        // 개수를 설정하고 인접리스트를 설정한다. 

        vector<int> result;
        
        // Find the start node (outDegree == inDegree + 1)
        // 시작점을 찾는데, 끝점이 시작점보다 1 큰 값을 더한다. 
        int startNode = -1;
        for (const auto& entry : outDegree) {
		        // node를 outDegree에서 가져온다. 
            int node = entry.first;
            if (outDegree[node] == inDegree[node] + 1) {
		            // 들어오는게 하나 더 많다면, 
			          // 둘중 하나만 홀수라면?
                startNode = node;
                break;
            }
        }
				// 한붓 그리기에 대한 정의가 있나. 들어오는게 나간거보다 한번이라도 많으면 가능 하다는것 같다. 
				// 밖으로 뻗은칸이 한번이라도 더 많으면 , 만약에 여전히 노드가 -1이면 여태까지 한번도 없으면 
        // If no such node exists, start from the first pair's first element
        if (startNode == -1) {
            startNode = pairs[0][0];
        }
        // 

        stack<int> nodeStack;
        nodeStack.push(startNode);
				// 처음 노드를 push 한다. 
        // Iterative DFS using stack
        while (!nodeStack.empty()) {
            int node = nodeStack.top();
            if (!adjacencyMatrix[node].empty()) {
                // Visit the next node
                int nextNode = adjacencyMatrix[node].front();
                adjacencyMatrix[node].pop_front();
                nodeStack.push(nextNode);
            } else {
                // No more neighbors to visit, add node to result
                result.push_back(node);
                nodeStack.pop();
            }
        }
        
        
        // Reverse the result since we collected nodes in reverse order
        reverse(result.begin(), result.end());

        // Construct the result pairs
        vector<vector<int>> pairedResult;
        for (int i = 1; i < result.size(); ++i) {
            pairedResult.push_back({result[i - 1], result[i]});
        }

        return pairedResult;
    }
};