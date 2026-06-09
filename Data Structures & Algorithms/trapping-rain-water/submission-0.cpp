class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int leftMax=height[i];
        int rightMax=height[j];
        int ans=0;
        while(i<=j){
            if(leftMax<rightMax){
                ans+=max(0,leftMax-height[i]);
                leftMax=max(leftMax,height[i]);
                i++;
            }
            else{
                ans+=max(0,rightMax-height[j]);
                rightMax=max(height[j],rightMax);
                j--;
            }
        }

        return ans;
    }
};
