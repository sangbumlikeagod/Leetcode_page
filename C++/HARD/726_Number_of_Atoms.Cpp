class Solution
{
    map<string, int> atomIndex;
    unordered_map<int, string> indexAtom;
    int maxIndex = 0;

public:
    int determineChar(char c)
    {
        if ('0' <= c && c <= '9')
        {
            return 2;
        }
        else if ('A' <= c && c <= 'Z')
        {
            return 0;
        }
        else if ('a' <= c && c <= 'z')
        {
            return 1;
        }
        else if (c == '(')
        {
            return 3;
        }
        return 4;
    }

    void fillVectors(vector<int> &array, int &index, string s)
    {
        string iS = "";

        while (index < s.length())
        {
            int type = determineChar(s[index]);
            // cout << s[index] << ' ' << type <<  '\n';
            if (type == 0)
            {
                if (!iS.empty())
                {
                    array[atomIndex[iS]]++;
                    iS = "";
                }
                iS += s[index];
                index++;
            }
            else if (type == 1)
            {
                iS += s[index++];
            }
            else if (type == 2)
            {
                int number = s[index] - '0';
                while (index + 1 < s.length() && determineChar(s[index + 1]) == 2)
                {
                    index++;
                    number *= 10;
                    number += s[index] - '0';
                }
                if (!iS.empty())
                {
                    array[atomIndex[iS]] += number;
                    // array[atomIndex[iS]] += stoi(number);
                    iS = "";
                }
                index++;
            }
            else if (type == 3)
            {
                if (!iS.empty())
                {
                    array[atomIndex[iS]]++;
                    iS = "";
                }
                index++;
                vector<int> subArray(maxIndex + 1, 0);
                fillVectors(subArray, index, s);
                for (int sIndex = 0; sIndex < maxIndex; sIndex++)
                {
                    array[sIndex] += subArray[sIndex];
                }
            }
            else
            {
                if (!iS.empty())
                {
                    array[atomIndex[iS]]++;
                    iS = "";
                }
                if (index < s.length() && determineChar(s[index + 1]) == 2)
                {
                    int number = 0;
                    while (index + 1 < s.length() && determineChar(s[index + 1]) == 2)
                    {
                        index++;
                        number *= 10;
                        number += s[index] - '0';
                    }
                    for (int i = 0; i < maxIndex; i++)
                    {
                        array[i] *= number;
                    }
                    index++;
                    return;
                }
                else
                {
                    index++;
                    return;
                }
            }
        }
    }

    string countOfAtoms(string formula)
    {
        string s = "";
        for (char c : formula)
        {
            int type = determineChar(c);
            if (type == 0)
            {
                if (!s.empty())
                {
                    indexAtom[maxIndex] = s;
                    atomIndex[s] = maxIndex++;
                    s = "";
                    s += c;
                }
                else
                {
                    s += c;
                }
            }
            else if (type == 1)
            {
                s += c;
            }
            else
            {
                if (!s.empty())
                {
                    indexAtom[maxIndex] = s;
                    atomIndex[s] = maxIndex++;
                    s = "";
                }
            }
        }
        if (!s.empty())
        {
            indexAtom[maxIndex] = s;
            atomIndex[s] = maxIndex++;
        }

        vector<int> answerVector(maxIndex + 1, 0);
        int index = 0;

        string iS = "";

        while (index < formula.length())
        {
            int type = determineChar(formula[index]);
            // cout << formula[index] << ' ' << type <<  '\n';
            if (type == 0)
            {
                if (!iS.empty())
                {
                    answerVector[atomIndex[iS]]++;
                    iS = "";
                }
                iS += formula[index];
                index++;
            }
            else if (type == 1)
            {
                iS += formula[index++];
            }
            else if (type == 2)
            {
                // if (!iS.empty())
                // {
                //     // cout << formula[index] - '0' << '\n';
                //     answerVector[atomIndex[iS]] += formula[index] - '0';
                //     iS = "";
                // }
                // index++;
                // cout << formula[index] << '\n';
                int number = formula[index] - '0';
                while (index + 1 < formula.length() && determineChar(formula[index + 1]) == 2)
                {
                    index++;
                    number *= 10;
                    number += formula[index] - '0';
                }
                if (!iS.empty())
                {
                    // cout << number << '\n';
                    answerVector[atomIndex[iS]] += number;
                    iS = "";
                }
                index++;
            }
            else if (type == 3)
            {
                if (!iS.empty())
                {
                    answerVector[atomIndex[iS]]++;
                    iS = "";
                }
                vector<int> indexEntities(maxIndex + 1, 0);
                index++;
                fillVectors(indexEntities, index, formula);
                for (int sIndex = 0; sIndex < maxIndex; sIndex++)
                {
                    answerVector[sIndex] += indexEntities[sIndex];
                }
            }
        }
        if (!iS.empty())
        {
            // cout << atomIndex[iS] << '\n';
            answerVector[atomIndex[iS]]++;
        }

        string Answer = "";
        for (map<string, int>::iterator a = atomIndex.begin(); a != atomIndex.end(); a++)
        {
            Answer += a->first;
            if (answerVector[a->second] > 1)
            {
                // cout << a -> first << answerVector[a -> second] << '\t';
                Answer += to_string(answerVector[a->second]);
            }
        }
        return Answer;
    }
};