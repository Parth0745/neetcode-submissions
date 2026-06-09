class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        // st.push(nums.size()-1);
        for(int x:nums){
            if(x>0) st.push(x);
            else{
                if(st.empty() || st.top()<0){
                    st.push(x); continue;
                }
                if(st.top()>abs(x)) continue;
                else if(st.top()<abs(x)){
                    while(!st.empty() && st.top()>0 && st.top()<abs(x)) st.pop();
                    if(!st.empty() && st.top()>0){
                        if(st.top()==abs(x)) st.pop();
                    }
                    else{
                        st.push(x);
                    }
                }
                else if(st.top()==abs(x)) st.pop();
                
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};