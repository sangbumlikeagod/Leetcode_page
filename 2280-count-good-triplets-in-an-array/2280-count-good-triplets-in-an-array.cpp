class Feature {
    vector<int> feature;
public:
    Feature(int n) {
        feature = vector<int>(n + 1, 0);
    }

    void update(int idx, int val)
    {
        idx++;
        while(idx < feature.size())
        {
            feature[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx)
    {
        idx++;
        int res = 0;
        while (idx > 0)
        {
            res += feature[idx];
            idx -= idx & -idx;   
        }
        return res;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long answer = 0;
        int sz = nums1.size();

        vector<int> pos2(sz + 1), idxToIdx(sz + 1);

        for (int i = 0; i < sz; i++)
        {
            pos2[nums2[i]] = i;
        }
        for (int i = 0; i < sz; i++)
        {
            idxToIdx[pos2[nums1[i]]] = i;
        }

        Feature feat(sz);
        for (int i = 0; i < sz; i++)
        {
            int val = idxToIdx[i];
            int left = feat.query(val);
            feat.update(val, 1);
            int right = sz  - 1  - i - val + left;
            answer += (long long)left * right;
        }
        return answer;
    }
};