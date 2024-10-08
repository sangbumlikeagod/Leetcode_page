class UnionFind
{
    vector<vector<vector<vector<int>>>> SectionGrid;
    int mX;
    int mY;

public:
    UnionFind(int m, int n)
    {
        mX = m;
        mY = n;
        SectionGrid = vector<vector<vector<vector<int>>>>(m, vector<vector<vector<int>>>(n, vector<vector<int>>(4, vector<int>{})));
        for (int x = 0; x < m; x++)
        {
            for (int y = 0; y < n; y++)
            {
                for (int z = 0; z < 4; z++)
                {
                    SectionGrid[x][y][z] = {x, y, z};
                }
            }
        }
    }

    vector<int> find(int x, int y, int z)
    {
        vector<int> &parent = SectionGrid[x][y][z];
        if (x == parent[0] && y == parent[1] && z == parent[2])
        {
            return {x, y, z};
        }
        SectionGrid[x][y][z] = find(parent[0], parent[1], parent[2]);
        return SectionGrid[x][y][z];
    }

    void merge(int x1, int y1, int z1, int x2, int y2, int z2)
    {
        // 이건 내가 조절할 수 있으므로 조절함 반드시 1번이 위다
        vector<int> parent1 = find(x1, y1, z1);
        vector<int> parent2 = find(x2, y2, z2);
        SectionGrid[parent2[0]][parent2[1]][parent2[2]] = parent1;
    }

    int totalCount()
    {
        int answer = 0;
        vector<vector<vector<int>>> visited(mX, vector<vector<int>>(mY, vector<int>(4, 0)));
        for (int x = 0; x < mX; x++)
        {
            for (int y = 0; y < mY; y++)
            {
                for (int z = 0; z < 4; z++)
                {
                    int px = SectionGrid[x][y][z][0], py = SectionGrid[x][y][z][1], pz = SectionGrid[x][y][z][2];
                    vector<int> par = find(px, py, pz);
                    if (!visited[par[0]][par[1]][par[2]])
                    {
                        visited[par[0]][par[1]][par[2]] = 1;
                        answer++;
                    }
                }
            }
        }
        return answer;
    }
};

class Solution
{
public:
    int regionsBySlashes(vector<string> &grid)
    {
        int m = grid.size();
        int n = grid[0].length();

        UnionFind *unionFind = new UnionFind(m, n);
        for (int x = 0; x < m; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (grid[x][y] == '/')
                {
                    unionFind->merge(x, y, 0, x, y, 3);
                    unionFind->merge(x, y, 1, x, y, 2);
                    if (x)
                        unionFind->merge(x - 1, y, 2, x, y, 0);
                    if (y)
                        unionFind->merge(x, y - 1, 1, x, y, 0);
                }
                else if (grid[x][y] == '\\')
                {
                    unionFind->merge(x, y, 0, x, y, 1);
                    unionFind->merge(x, y, 2, x, y, 3);
                    if (x)
                        unionFind->merge(x - 1, y, 2, x, y, 0);
                    if (y)
                        unionFind->merge(x, y - 1, 1, x, y, 2);
                }
                else
                {
                    unionFind->merge(x, y, 0, x, y, 1);
                    unionFind->merge(x, y, 0, x, y, 2);
                    unionFind->merge(x, y, 0, x, y, 3);
                    if (x)
                        unionFind->merge(x - 1, y, 2, x, y, 0);
                    if (y)
                        unionFind->merge(x, y - 1, 1, x, y, 0);
                }
            }
        }
        return unionFind->totalCount();
    }
};