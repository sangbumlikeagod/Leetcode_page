class Solution {
    class UnionFind {
    public:
        static void Union(UnionFind* a, UnionFind* b) {
            a = a -> find();
            b = b -> find();
            if (a -> val < b -> val)
            {
                b -> parent = a;
            }
            else
            {
                a -> parent = b;
            }
        }
        UnionFind* parent;
        char val;

        UnionFind* find() {
            if (parent == this) return this;
            parent = parent -> find();
            return parent;
        }

        UnionFind() : parent(this) {
            
        }
    };
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int m = s1.length(), n = s2.length();
        int numnum[26][26] = {0};

        UnionFind* names[26];
        for (int i = 0; i < 26; i++)
            {
                names[i] = new UnionFind();
                names[i] -> val = 'a' + i;
            }

        for (int i = 0; i < min(m, n); i++)
            {
                UnionFind::Union(names[s1[i] - 'a'], names[s2[i] - 'a']);
            }

        string answer = "";
        for (int i = 0; i < baseStr.length(); i++)
            {

                answer += names[baseStr[i] - 'a'] -> find() -> val;

            }

        return answer;
    }
};