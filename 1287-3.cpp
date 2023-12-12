class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        // vector
        int n=arr.size();
        // 크기를 구한다
        vector<int>possibleAnswer={arr[n/4],arr[n/2],arr[3*n/4],arr[n-1]};
        // 4가지 구역에 설정 25%, 50%, 75%, 100% 
        for(int i=0;i<4;i++){
            int lb=lower_bound(arr.begin(),arr.end(),possibleAnswer[i])-arr.begin();
            // 시작, 끝이있고, iterator 범위, begin, end와 한계 값이 있음 여기서 4개의 범위값보다 크거나 같은 최소값 인덱스를 리턴
            int ub=upper_bound(arr.begin(),arr.end(),possibleAnswer[i])-arr.begin();
            // 시작, 끝이있고, iterator 범위, begin, end와 한계 값이 있음 여기서 4개의 범위값보다 작거나 큰 최대값을 고르게한다 인덱스를 리턴
            // 
            if(ub-lb>n/4){
                return possibleAnswer[i];
            }
            // 인덱스의 길이차이가 n / 4인지만 확인하면 된다
        }

        return -1;
    }
};