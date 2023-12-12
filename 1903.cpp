#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int initLength = num.length() - 1;
        while (initLength >= 0){
            if ((num[initLength] - '0') % 2){
                return num.substr(0, initLength + 1);
            }
        }
        return "";
    }
};

int main() {
    string S = "56790tajk";
    cout << S.length();
    for (char a : S){
        // cout << a - '0' == int(a) ? "문자열임" : "아님";
       if (0 <= a - '0' &  a - '0' < 10)
       {
            cout << a - '0'  << "는"<< "숫자임";
       }
       else 
       {
            cout << a - '0'  << "는" << "아님";
       }
    }
}