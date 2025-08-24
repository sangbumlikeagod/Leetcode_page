class SegmentsTree{
public:
    int maxVal;
    int leftIdx;
    int rightIdx;
    SegmentsTree* left;
    SegmentsTree* right;

public:
    SegmentsTree(
        vector<int>& con,
        int leftidx,
        int rightidx
    ) : leftIdx(leftidx), rightIdx(rightidx)
    {
        // cout << leftidx << ' ' << rightidx << '\n';
        if (leftidx == rightidx)
        {
            maxVal = con[leftidx];
        }
        else
        {
            int mid = (rightidx + leftidx) / 2;
            left = new SegmentsTree(con, leftidx, mid);
            right = new SegmentsTree(con, mid + 1, rightidx);
            maxVal = max(left->get(), right->get());
        }
    }

    void update(int idx, int val)
    {
        // cout << idx << ' ' << leftIdx << ' ' << rightIdx << '\n';
        if (leftIdx == rightIdx && leftIdx == idx)
        {
            maxVal = val;
            return;
        }
        else
        {
            int mid = (rightIdx + leftIdx) / 2;
            // cout << "끄아아아아앆 " << mid << '\n';
            if (mid >= idx)
            {
                left->update(idx, val);
            }
            else
            {
                right->update(idx, val);
            }
            maxVal = max(left->maxVal, right->maxVal);
            return;
        }
    }
    int get()
    {
        if (leftIdx == rightIdx)
        {
            return maxVal;
        }
        return max(left->get(), right->get());
    }

    int query(int val)
    {
        if (val > maxVal)
        {
            return -1;
        }
        else
        {
            if (leftIdx == rightIdx)
            {
                return leftIdx;
            }
            if (left -> maxVal >= val)
            {
                return left -> query(val);
            }
            else
            {
                return right -> query(val);
            }
        }
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentsTree* root = new SegmentsTree(baskets, 0, fruits.size() - 1);
        // cout << root -> maxVal << '\n';
        // cout << root -> left -> leftIdx << ' ' << root -> left -> rightIdx << '\n';
        // cout << root -> right -> leftIdx << ' ' << root -> right -> rightIdx << '\n';
        // cout << root -> right -> maxVal;
        int answer = 0;
        for (int fruit : fruits)
        {
            int ret = root -> query(fruit);
            if (ret == -1)
            {
                answer++;
            }
            else
            {
                root -> update(ret, -1);
            }
        }
        return answer;
    }
};