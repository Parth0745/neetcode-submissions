class Solution {
public:
    vector<int> countBits(int n) {
        int start=1;
        vector<int> ans;
        ans.push_back(0);
        while(start<=n){
            int count=0;
            int curr=start;
            while(curr>0){
                if((curr&1)==1) count++;
                curr>>=1;
            }
            ans.push_back(count);
            start++;
        }
        return ans;
    }
};
