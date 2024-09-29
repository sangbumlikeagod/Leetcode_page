class AllOne
{
    vector<unordered_set<string>> indexedData;
    unordered_map<string, int> syncData;
    int maxIndex;
    int minIndex;

    int move(string key, int direction)
    {
        int before = syncData[key];
        int after = before + direction;
        syncData[key] += direction;
        if (!syncData[key])
        {
            syncData.erase(key);
        }
        indexedData[before].erase(key);
        indexedData[after].insert(key);
        return after;
    }
    void setNewMin()
    {
        if (syncData.empty())
        {
            minIndex = 0;
            return;
        }
        int minVal = 50001;
        for (auto a = syncData.begin(); a != syncData.end(); a++)
        {
            minVal = min(minVal, a->second);
        }
        minIndex = minVal;
        // cout << "new Min " <<  minIndex << '\n';
    }

public:
    AllOne()
    {
        indexedData = vector<unordered_set<string>>(50001);
        maxIndex = 0;
        minIndex = 0;
    }

    void inc(string key)
    {
        int after = move(key, 1);
        if (after - 1 == maxIndex)
        {
            maxIndex++;
        }
        if (after == 1)
        {
            minIndex = 1;
        }
        else if (after - 1 == minIndex)
        {
            if (indexedData[after - 1].empty())
            {
                minIndex++;
            }
        }
        // cout << maxIndex << ' ' << minIndex << '\n';
    }

    void dec(string key)
    {
        int after = move(key, -1);
        if (after + 1 == maxIndex)
        {
            if (indexedData[after + 1].empty())
            {
                maxIndex--;
            }
        }
        if (after == 0)
        {
            if (indexedData[1].empty())
            {
                setNewMin();
            }
            else
            {
                minIndex = 1;
            }
        }
        else if (after + 1 == minIndex)
        {
            minIndex--;
        }
        // cout << maxIndex << ' ' << minIndex << '\n';
    }

    string getMaxKey()
    {
        if (!maxIndex)
            return "";
        return *(indexedData[maxIndex].begin());
    }

    string getMinKey()
    {
        if (!minIndex)
            return "";
        return *(indexedData[minIndex].begin());
    }
};

/**
 * @brief
 *
 */
*AllOne *obj = new AllOne();
*obj->inc(key);
*obj->dec(key);
*string param_3 = obj->getMaxKey();
*string param_4 = obj->getMinKey();
* /