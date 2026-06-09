class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[r] && nums[l]==nums[mid]){
                l++,r--; continue;
            }
            if(nums[mid]<=nums[r]){
                if(target>nums[mid] && nums[r]>=target){
                    l=mid+1;
                    while(l<=r && nums[l]==nums[l-1]) l++;
                    // while(l<=r && nums[r]==nums[r-1]) l++;
                }
                else{
                    r=mid-1;
                    while(l<=r && nums[r]==nums[r-1]) r--;
                }
            }
            else{
                if(target<nums[mid] && nums[l]<=target){
                    r=mid-1;
                    while(l<=r && nums[r]==nums[r-1]) r--;;
                    // while(l<=r && nums[r]==nums[r-1]) l++;
                }
                else{
                    l=mid+1;
                    while(l<=r && nums[l]==nums[l+1]) l++;
                }
            }
        }
        return false;
    }
};