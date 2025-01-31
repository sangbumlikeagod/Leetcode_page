#define isBorder(x, y, n) 0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (n)

struct UnionFind
{
    int val;
    UnionFind* parent;

    UnionFind(int val) : val(val)
    {
        parent = this;
    }
    UnionFind* find(){
        if (parent->val == val)
        {
            return this;
        }
        parent = parent->find();
        return parent;
    }
    void merge(UnionFind* B){
        UnionFind* a = find();
        UnionFind* b = B -> find();
        // cout << a -> val << ' ' << b -> val << '\n';
        if (a -> val == b -> val) return;
        if (a -> val < b -> val)
        {
            b -> parent = a;
        }
        else
        {
            a -> parent = b;
        }
    }
};

class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<UnionFind*>> unionFinds (n, vector<UnionFind*> (n, nullptr));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                unionFinds[i][j] = new UnionFind(i * n + j);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    for (int k = 0; k < 2; k++)
                    {
                        int ni = i + dx[k], nj = j + dy[k];
                        if (isBorder(ni, nj, n) && grid[ni][nj])
                        {
                            // cout << i << ' ' << j << " 와 " << unionFinds[ni][nj] -> val << "을 합친다\n";
                            unionFinds[i][j] -> merge(unionFinds[ni][nj]);
                        }
                    }
                }
            }
        }

        vector<int> countRegion(n * n, 0);

        // 전부 다 세는 자리 
        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    // cout << i << j << "는 더한다 여기에 "<< unionFinds[i][j] -> find() -> val << '\n';
                    countRegion[unionFinds[i][j] -> find() -> val]++;
                    answer = max(answer, countRegion[unionFinds[i][j] -> find() -> val]);
                }
            }
        }
        // cout << '\n' <<  answer <<'\n';



        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    // cout << i << ' ' << j << " 에 대해서 \n";
                    unordered_set<int> puputy;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (isBorder(nx, ny, n) && grid[nx][ny] && puputy.find(unionFinds[nx][ny] -> find() -> val) == puputy.end())
                        {
                            // cout << "갑니다 " << unionFinds[nx][ny] -> find() -> val << '\n';
                            puputy.insert(unionFinds[nx][ny] -> find() -> val);
                        }
                    }

                    int tmp = 1;
                    for (auto arg : puputy)
                    {
                        // cout << arg << ' ' << countRegion[arg] << '\n';
                        tmp += countRegion[arg];
                    }
                    answer = max(answer, tmp);
                }
            }
        }
        return answer;
    }
};