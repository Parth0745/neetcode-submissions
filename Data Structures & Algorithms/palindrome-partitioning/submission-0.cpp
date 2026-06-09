class Solution {
public:
vector<vector<string>> ans;
    bool isPalin(string s){
        string a=s;
        reverse(s.begin(),s.end());
        return s==a;
    }
    void helper(string s,int i,vector<string> curr){
        if(i==s.size()) {
            ans.push_back(curr);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(isPalin(s.substr(i,j+1))){
                curr.push_back(s.substr(i,j+1));
                helper(s.substr(j+1),0,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        helper(s,0,curr);
        return ans;
    }
};
