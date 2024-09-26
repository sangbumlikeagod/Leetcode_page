class MyCalendar
{
    vector<vector<int>> roots;

public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        for (vector<int> root : roots)
        {
            if ((start <= root[0] && end > root[0] && end < root[1]) || (start > root[0] && root[1] > start && root[1] < end) || (start >= root[0] && end <= root[1]) || (start <= root[0] && end >= root[1]))
            {
                return false;
            }
        }
        roots.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */