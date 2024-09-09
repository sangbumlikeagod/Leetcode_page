/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> answer(m, vector<int>(n, -1));
        int direction = 0;
        int x = 0, y = 0;

        while (head)
        {
            visited[x][y] = 1;
            answer[x][y] = head->val;
            int nx, ny;

            nx = x + dx[direction];
            ny = y + dy[direction];

            if (0 <= nx && nx < m && 0 <= ny && ny < n && !visited[nx][ny])
            {
            }
            else
            {
                direction = direction == 3 ? 0 : direction + 1;
                nx = x + dx[direction];
                ny = y + dy[direction];
            }
            x = nx;
            y = ny;
            head = head->next;
        }
        return answer;
    }
};