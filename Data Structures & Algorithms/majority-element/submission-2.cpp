class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr = nums[0];
        int add = 1;
        if ( nums.size()==1 ) return nums[0];
        for( int i = 1; i < nums.size(); i++){
            if(curr == nums[i]){
                add++;
            }
            else{
                add--;
                if(!add){
                    curr = nums[i];
                    add = 1;
                }
            }
        }
        return curr;
    }
};