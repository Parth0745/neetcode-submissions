class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0,high=matrix.size()*matrix[0].size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mid/matrix[0].size();
            int col=mid%matrix[0].size();
            int val=matrix[row][col];
            if(val==target) return true;
            else if(val>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};
