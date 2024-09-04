class Solution
{
    vector<vector<int>> columns = vector<vector<int>>(60002, vector<int>{});
    vector<vector<int>> rows = vector<vector<int>>(60002, vector<int>{});
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int mode = 0;
    int answer = 0;
    int x = 0;
    int y = 0;

public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {

        for (vector<int> obstacle : obstacles)
        {
            rows[obstacle[1] * -1 + 30000].push_back(obstacle[0]);
            columns[obstacle[0] + 30000].push_back(obstacle[1] * -1);
        }
        for (int i = 0; i < 60002; i++)
        {
            sort(rows[i].begin(), rows[i].end());
            sort(columns[i].begin(), columns[i].end());
        }

        for (int command : commands)
        {
            // cout << command << ' ' << mode << '\n' ;
            if (command == -1)
            {
                mode = mode == 3 ? 0 : mode + 1;
                continue;
            }
            if (command == -2)
            {
                mode = mode == 0 ? 3 : mode - 1;
                continue;
            }

            int nx = x + dx[mode] * command;
            int ny = y + dy[mode] * command;
            auto obs = columns[ny + 30000].begin();
            // cout << nx << ' ' << ny << '\n';
            // cout << mode << '\n';
            if (mode == 0)
            {
                obs = lower_bound(columns[ny + 30000].begin(), columns[ny + 30000].end(), nx);
                if (obs != columns[ny + 30000].end() && *obs >= nx && *obs < x)
                {
                    nx = *obs + 1;
                }
            }
            else if (mode == 1)
            {
                obs = upper_bound(rows[nx + 30000].begin(), rows[nx + 30000].end(), y);

                // for (int a : rows[nx + 30000])
                // {
                //     cout << a << '\t';
                // }
                // cout << '\n';
                // if (obs != rows[nx + 30000].end())
                // {
                //     cout << "아오 씨발 그냥. " << *obs << '\n';
                // }
                if (obs != rows[nx + 30000].end() && *obs <= ny && *obs > y)
                {
                    ny = *obs - 1;
                }
            }
            else if (mode == 2)
            {
                obs = upper_bound(columns[ny + 30000].begin(), columns[ny + 30000].end(), x);
                if (obs != columns[ny + 30000].end() && *obs <= nx && *obs > x)
                {
                    nx = *obs - 1;
                }
            }
            else
            {
                obs = lower_bound(rows[nx + 30000].begin(), rows[nx + 30000].end(), ny);
                if (obs != rows[nx + 30000].end() && *obs >= ny && *obs < y)
                {
                    ny = *obs + 1;
                }
            }
            x = nx;
            y = ny;
            // cout << mode << ' ' << command << '\t' << x << ' ' << y << '\t' << answer << '\n' ;
            answer = max(answer, x * x + y * y);
        }

        return answer;
    }
};