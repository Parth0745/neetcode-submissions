class Solution {
public:
    int evalRPN(vector<string>& nums) {
        stack<int> st;
        for(string &s:nums){
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                if(s=="+"){
                    st.push(a+b);
                }
                else if(s=="-"){
                    st.push(b-a);
                }
                else if(s=="*"){
                    st.push(a*b);
                }
                else{
                    st.push(b/a);
                }
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
