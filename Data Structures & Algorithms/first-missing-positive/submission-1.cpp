class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;
        for(int x:nums){
            st.insert(x);
        }
        if(st.count(1)==0){
            return 1;
        }
        for(auto it:st){
            if(it>=0){
                if(st.count(it+1)==0){
                    return it+1;
                }
            }
        }
        return 1;
    }
};