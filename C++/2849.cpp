class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        int tmp;        if (sx > fx)
        {
            tmp = sx;
            sx = fx;
            fx = tmp;
        }
        if (sy > fy)
        {
            tmp = sy;
            sy = fy;
            fy = tmp;
        }
        int longestPath = fx - sx + fy - sy;
        int shortt = min(fy - sy, fx - sx);
        int shortestPath = longestPath - shortt;
        // cout << shortt;
        // cout << !(!shortestPath && (t == 1));

        return (shortestPath <= t) && !(!shortestPath && (t == 1));
    }
};