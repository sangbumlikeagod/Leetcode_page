class Solution {
public:
    int numberOfBeams(vector<string>& v) {
        int ct=0,ct1=0;
        int ans=0;
        int n=v.size(),m=v[0].size();
        
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (v[i][j]=='1')
                    ct1++;
            }
            if (ct1){
                ans+=(ct*ct1);
                ct=ct1;
                ct1=0;
            }
        }
        return ans;
    }
};