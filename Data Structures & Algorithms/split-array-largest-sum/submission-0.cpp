class Solution {
public:
    int helper(vector<int>& nums, int maxSum){
        int count=0;
        int currSum=0;
        for(int i=0;i<nums.size();i++){
            if(currSum+nums[i]<=maxSum){
                currSum+=nums[i];
            }
            else{
                count++;
                currSum=nums[i];
            }
        }
        return count+1;//as count will not count the last subarray formed
    }
    int splitArray(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        int sum=accumulate(nums.begin(),nums.end(),0);
        int low=maxi;//the low will be the max of all of the nums otherwise the max element cant be taken in any array
        int high=sum;//if we have to split array in 1 part (array as it is) in that case we need sum of the array
        while(low<=high){
            int mid=low+(high-low)/2;
            int ans=helper(nums,mid);//it means allowed sum is mid and it will return how many arrays to be split in order to get max sum of them as mid
            if(ans<=k){//if ans==k that is required so it will be the ans
                high=mid-1;
            } 
            else if(ans>k){
                low=mid+1;
            }
        }
        return low;
    }
};