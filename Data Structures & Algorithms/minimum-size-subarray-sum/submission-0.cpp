class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0;
        int n=nums.size();
        int sum=0;
        int minLen=INT_MAX;
            int len=0;
        while(r<n){

            sum+=nums[r];
            if(sum>=target){
                len=r-l+1;
                minLen=min(minLen,len);
                 while(l<r && sum>=target){
                    sum-=nums[l++];
                    if(sum>=target){
                        minLen=min(minLen,r-l+1);
                    }
                }
            }
            r++;
        }
        return min(len,minLen);
    }
};