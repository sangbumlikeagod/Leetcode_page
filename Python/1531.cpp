#include <queue>

using namespace std;

class Solution {
    priority_queue<int, vector<int>, greater<int>> q;
    priority_queue<int, vector<int>, greater<int>> q10;
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int idx = 0;
        int alen = s.length();
        int local = 1;
        while (idx < alen){
            if (idx != alen - 1 && s[idx] == s[idx + 1]){
                local++;
                idx++;
            }
            else {
                if (local >= 10){
                    q10.push(local);
                }
                else {
                    q.push(local);
                }
                local = 1;
                idx++;
            }
        }

        while (k){
            if (!q.empty()){
                int val1 = q1.front();
            }
            else {
                int val1 = 101;
            }
            if (val1 > k){
                if (!q10.empty()){
                    int val2 = q2.front() - 9;
                    if (val2 > k){
                        return alen;
                    }
                    else {
                        alen--;
                        k -= val2;
                        q.push(9);
                    }
                }
                else {
                    return alen;
                }
            } else {
                alen -= 2;
                if (q10.size() >= 2){
                    int val2 = q10.front() - 9;
                    q10.pop();
                    int val3 = q10.front() - 9;
                    if (val1 > val2 + val3){
                        k -= val2 + val3;
                        q10.pop();
                        q.push(9);
                        q.push(9);
                    }
                    else {
                        k -= val1;
                        q.pop();
                        q10.push(val2 + 9);
                    }
                }
                else {
                    k -= val1;
                    q1.pop();
                }
            }
        }
        return alen;
    }
};