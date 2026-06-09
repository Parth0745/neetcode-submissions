class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1;
        int mid;
        int ans=INT_MAX;
        while(l<=r){
            mid=l+(r-l)/2;
            // if(nums[mid]==target) return mid;
            if(nums[mid]<=nums[r]){
                ans=min(ans,nums[mid]);
                r=mid-1;
            }
            else{
                ans=min(ans,nums[mid]);
                l=mid+1;
            }
        }
        return ans;
    }
};
