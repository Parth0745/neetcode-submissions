class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = 0 , l2 = 0;
        int r1 = nums1.size() , r2 = nums2.size();
        int m = nums1.size();
        int n = nums2.size();
        if(nums1.size() > nums2.size())
    return findMedianSortedArrays(nums2, nums1);
        int total = (m+n+1)/2;
        while ( l1<=r1 ){
            int mid1 = l1 + (r1-l1)/2;
            int mid2 = total - mid1;

            int left1 = mid1-1<0 ? INT_MIN: nums1[mid1-1];
            int left2 = mid2-1<0 ? INT_MIN: nums2[mid2-1];

            int right1 = mid1 == m? INT_MAX:nums1[mid1];
            int right2 = mid2 == n? INT_MAX:nums2[mid2];

            if(left1<=right2 && left2<=right1){
                if( (m + n)%2 == 0 ) return (max(left1,left2)+min(right1,right2))/2.0;
                return max(left1,left2);
            }

            else if(left1 > right2) r1 = mid1 - 1;
            else l1 = mid1 + 1;

        }
        return 0.0;
    }
};
