/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l=1,r=mountainArr.length()-2;
        int len=mountainArr.length();
        int mid;
        int peak;
        int ans=INT_MAX;
        while(l<=r){
            mid=l+(r-l)/2;
            int left=mountainArr.get(mid-1);
            
            int right=mountainArr.get(mid+1);
            
            int ans=mountainArr.get(mid);
            if(ans<right && left<ans) l=mid+1;
            else if(ans>right && left>ans) r=mid-1;
            else{ peak=mid; break;}
        }
        l=0,r=peak;
        while(l<=r){
            mid=l+(r-l)/2;
            if(mountainArr.get(mid)==target) {ans=mid; break;}
            if(mountainArr.get(mid)>target) {r=mid-1;}
            if(mountainArr.get(mid)<target) {l=mid+1;}
        }
        l=peak+1,r=mountainArr.length()-1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(mountainArr.get(mid)==target) {ans=min(ans,mid); break;}
            if(mountainArr.get(mid)<target) {r=mid-1;}
            if(mountainArr.get(mid)>target) {l=mid+1;}
        }
        return ans==INT_MAX?-1:ans;
    }
};