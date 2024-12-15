#define DIVIDE(x, y) (((double) ((x) + 2) / double((y) + 2)) - ((double) (x) / (double) (y)))


struct compare{
    bool operator()(vector<int>& a, vector<int>& b){
        return DIVIDE(b[0], b[1]) > DIVIDE(a[0], a[1]);
    }
};


class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<int>, vector<vector<int>>, compare> q;
        for (vector<int> class_c : classes)
        {
            q.push(class_c);
        }
        while(extraStudents)
        {
            int x = q.top()[0], y = q.top()[1];
            q.pop();
            q.push(vector<int>{x + 1, y + 1});
            extraStudents--;
        }
        // sort(classes.begin(), classes.end(), [](vector<int>& a, vector<int>& b){
        //     return DIVIDE(b[0], b[1]) < DIVIDE(a[0], a[1]);
        // });
        double answer = 0;

        while (q.empty() == false)
        {
            answer += (double) (q.top()[0]) /  (double) (q.top()[1]);
            q.pop();
        }
        return answer / classes.size();
        // for (int i = 0; i < classes.size(); i++)
        // {
        //     vector<int>& class_c = classes[i];
        //     cout << '\t' << class_c[0] << ' ' << class_c[1] << ' ' << DIVIDE(class_c[0], class_c[1]) << '\n';
        //     if (i)
        //     {
        //         answer += ((double) class_c[0] / (double) class_c[1]);
        //         cout << ((double) class_c[0] / (double) class_c[1]) << '\n';
        //     }
        //     else
        //     {
        //         answer += ((double) (class_c[0] + extraStudents) / (double) (class_c[1] + extraStudents));
        //         cout << ((double) (class_c[0] + extraStudents) / (double) (class_c[1] + extraStudents)) << '\n';
        //     }
        // }
    }
};