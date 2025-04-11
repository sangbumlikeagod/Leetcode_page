class Solution {
public:
    int getDigit(long long tmp)
    {
        int digit = 0;
        while (tmp > 0)
        {
            tmp /= 10;
            digit++;
        }
        return digit;
    }
    long long getPrefix(long long target, long long s, int suffixDigit, bool isLow)
    {
        long long tC = target;
        int suffixDigitC = suffixDigit;
        while (suffixDigitC)
        {
            tC /= 10;
            suffixDigitC--;
        }
        long long low, high;
        long long multi = (long long) pow(10, suffixDigit);
        if (isLow)
        {
            low = tC ;
            high = (tC + 1);
        }
        else
        {
            low = (tC - 1);
            high = tC;
        }
        // 앞의 몇자는 같고 뒤에걸 갈아버림 그게 큰지를 target보다 크다? 

        // target은 high보다는 반드시 작고, low보다는 클 수도 있고 작을 수도 있음 지금 상황에선 
        // target보다 
        // 141이라고 했을때 149랑 가장 큰 수를 제공하는게 맞다 
        if (isLow)
        {
            // 몇개가 안될지를 보는거지 
            if (target > low * multi + s)
            {
                return low + 1;
            }
            else
            {
                return low;
            }
        }
        else
        {
            if (target >= high * multi + s)
            {
                return high;
            }
            else
            {
                return low;
            }
        }
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        
        // string s  => s의 정수값, s의 자리수
        long long sInt = 0, answer = 0, sC = start, fC = finish;
        int sDigit = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            sInt += (s[i] - '0') * (long long) pow(10, sDigit);
            sDigit++;
        }
        int lD = getDigit(start), rD = getDigit(finish);
        // start와
        if (lD < sDigit)
        {   
            start = sInt;
            lD = sDigit;
        }
        if (fC < sInt)
        {
            return 0;
        }
        long long r = getPrefix(finish, sInt, sDigit, false);
        long long l = getPrefix(start ,sInt, sDigit, true);

        vector<int> rArg {};
        vector<int> lArg {};
        while (r >= 0)
        {
            rArg.push_back(r % 10);
            r /= 10;
            if (r == 0)
            {
                r--;
            }
            // 44541 => [1, 4, 5, 4, 4]
        }
        l--;
        while (l >= 0)
        {
            lArg.push_back(l % 10);
            l /= 10;
            if (l == 0)
            {
                l--;
            }
        }


        // 위에서 0을 포함해버려서 에러가 생기는건가하는생각이 든다. 

        // 이미 0이 가능하다는 것은 위에서 세었음 근데 밑에서 또한다? 
        // 0 , 1, 2를 세어서 3개가 됐고, 0을 포함한 그만큼을 더해야한다 여긴 그래서 0,1, 2, 3, 4,5를 세어서 6개가 됐는데
        long long rR = 0;
        for (int i = rArg.size() - 1; i >= 0; i--)
        {
            int tmp = rArg[i] + 1;
            rArg[i] = min(rArg[i] + 1, limit + 1);
            if (i > 0)
            {
                if (rArg[i] != tmp)
                {
                    // 변했어
                    rR +=  pow(limit + 1, i) * (rArg[i]);
                    break;
                }
                else
                {
                    rR +=  pow(limit + 1, i) * (rArg[i] - 1);
                }
            }
            else
            {
                rR += rArg[i];
            }
        }
        long long rL = 0;
        for (int i = lArg.size() - 1; i >= 0; i--)
        {
            int tmp = lArg[i] + 1;
            lArg[i] = min(lArg[i] + 1, limit + 1);
            if (i > 0)
            {
                if (lArg[i] != tmp)
                {
                    rL += (pow(limit + 1, i) * (lArg[i])); 
                    break;
                }
                else
                {
                    rL += (pow(limit + 1, i) * (lArg[i] - 1)); 
                }
            }
            else
            {
                rL += lArg[i];
            }
        }
        // 0보다 같거나 작을 수있는놈중 만족하는건 1개있다는건데 근데 문제는 얘는 포함이라는거임 l부터니까 
        // cout << rR << ' ' << rL << '\n';
        return rR - rL;
    }
};