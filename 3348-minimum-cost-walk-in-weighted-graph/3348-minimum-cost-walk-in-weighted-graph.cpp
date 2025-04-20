#define maxAND (1 << 17) - 1

class UnionFind {
    UnionFind* parent;

public:
    int andVal;
    int idx; 
    UnionFind(int idx) : idx(idx) {
        parent = this;
        andVal = maxAND;
    }
    UnionFind* find()
    {
        if (parent == this)
        {
            return this;
        }
        parent = parent->find();
        andVal = parent->andVal;
        return parent;
    }
    void merge(UnionFind* oth, int weight)
    {
        UnionFind* me = parent->find();
        UnionFind* othParent = oth -> find();
        // cout << me  -> andVal << "  " << oth -> andVal << '\t' << weight << '\n';
        if (me == othParent)
        {
            me -> andVal &= weight;
        }   
        else if (me -> andVal < othParent -> andVal)
        {
            othParent->parent = me;
            me -> andVal &= weight;
            me -> andVal &= othParent -> andVal;
        }
        else
        {
            me -> parent = othParent;
            othParent -> andVal &= weight;
            othParent -> andVal &= me -> andVal;
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        // cout <<maxAND << '\n';
        vector<UnionFind*> unionFinds(n, nullptr);
        for (int i = 0; i < n; i++)
        {
            unionFinds[i] = new UnionFind(i);
        }

        for (vector<int> edge : edges)
        {
            // cout << edge[0] << ' ' << edge[1] << " 둘을 연결 \t" << '\n';
            UnionFind* l = unionFinds[edge[0]] -> find();
            UnionFind* r = unionFinds[edge[1]] -> find();
            l -> merge(r, edge[2]);
        }

        // for (auto arg : unionFinds)
        // {
        //     cout << arg -> find() -> idx<< '\t';
        //     cout << arg -> find() -> andVal<< '\n';
        // }
        vector<int> answer;
        for (vector<int> que : query)
        {
            UnionFind* l = unionFinds[que[0]] -> find();
            UnionFind* r = unionFinds[que[1]] -> find();
            if (l != r)
            {
                answer.push_back(-1);
            }
            else
            {
                answer.push_back(l -> andVal);
            }
        }

        return answer;
    }
};