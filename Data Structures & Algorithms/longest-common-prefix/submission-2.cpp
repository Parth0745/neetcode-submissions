class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s1=strs[0];
        string s2=strs[strs.size()-1];
        int m=s1.size(),n=s2.size();
        string ans="";
        for(int i=0,j=0;i<m && j<n;i++,j++){
            if(s1[i]==s2[j]){
                ans+=s1[i];
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};