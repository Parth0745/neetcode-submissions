class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hash(26,0);
        if(s1.size()<=s2.size()){
            for(char ch:s1){
                hash[ch-'a']++;
            }
            vector<int> hash1(26,0);
            int l=0;
            int len=0;
            for(int r=0;r<s2.size();r++){
                hash1[s2[r]-'a']++;
                len=r-l+1;
                if(len>s1.size()){
                    hash1[s2[l]-'a']--;
                    l++;
                    len=r-l+1;
                }
                if(len==s1.size()){
                    if(hash1==hash) return true;
                }
            }
        }
        else{
            return false;
        }
        return false;
        
    }
};
