class Solution {
public:
    vector<string> ans;
    void helper(int n,int open,int close,string s){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(open>0){
            helper(n,open-1,close,s+'(');
        }
        if(open<close){
            helper(n,open,close-1,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        helper(n,n,n,s);
        return ans;
    }
};
