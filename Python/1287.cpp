#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size = *arr.size();
        if (size <= 2) return *arr[0];
        int head, tail;
        tail++;
        while (tail < size){
            while (tail < size & *arr[head] == *arr[tail]){
                if ((tail - head) * 4 >= size){ return *arr[head]}
                tail++;
            }
            if ((tail - head) * 4 >= size){ return *arr[head] } 
            head = tail;
            tail = head + 1;
        }

    }
};

int main(){
    
}