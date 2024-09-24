class Trie
{
public:
    Trie *arr[10];
    Trie()
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i] = nullptr;
        }
    };
};
class Solution
{

    void PutTrie(Trie *trie, int num)
    {
        int digit = 1;
        while (digit * 10 <= num)
        {
            digit *= 10;
        }
        // cout << digit << ' ' << num << '\n';
        while (digit)
        {
            int prefix = num / digit;
            // cout << digit << ' ' << num  << ' ' << prefix << '\n';
            if (!(trie->arr)[prefix])
            {
                trie->arr[prefix] = new Trie();
            }
            trie = trie->arr[prefix];
            num %= digit;
            digit /= 10;
        }
    }

    int getMaxPrefix(Trie *trie1, Trie *trie2)
    {
        int answer = 0;
        for (int i = 0; i < 10; i++)
        {
            cout << i << '\n';
            if ((trie1->arr[i]) && (trie2->arr[i]))
            {
                answer = max(answer, getMaxPrefix(trie1->arr[i], trie2->arr[i]));
            }
        }
        return answer + 1;
    }

public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        Trie *root1 = new Trie();
        Trie *root2 = new Trie();

        for (int arr : arr1)
        {
            PutTrie(root1, arr);
        }
        for (int arr : arr2)
        {
            PutTrie(root2, arr);
        }
        return getMaxPrefix(root1, root2) - 1;
    }
};