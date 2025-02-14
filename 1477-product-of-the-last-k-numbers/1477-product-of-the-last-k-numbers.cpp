class ProductOfNumbers {
    vector<int> zeros {0};
    vector<vector<int>> prefixProduct;
    int index = 1;
public:
    ProductOfNumbers() {
        prefixProduct.resize(40001, vector<int> (102, 0));
    }
    
    void add(int num) {
        if (num == 0)
        {
            zeros.push_back((zeros.back()) + 1);
            for (int i = 1; i < 101; i++)
            {
                prefixProduct[index + 1][i] = prefixProduct[index][i];
            }
            // prefixProduct.push_back(prefixProduct.back());
        }
        else
        {
            for (int i = 1; i < 101; i++)
            {
                if (i == num)
                {
                    prefixProduct[index][i]++;
                }
                prefixProduct[index + 1][i] = prefixProduct[index][i];
            }
            zeros.push_back((zeros.back()));
        }
        index++;
    }
    
    int getProduct(int k) {
        // cout << index << ' ' << k << '\n';
        if (zeros[index - 1] != zeros[index - k - 1]) return 0;
        int answer = 1;
        for (int i = 2; i < 101; i++)
        {
            for (int j = prefixProduct[index - 1][i] - prefixProduct[index - k - 1][i]; j > 0; j--)
            {
                answer *= i;
            }
        }
        return answer;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */