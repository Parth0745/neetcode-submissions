class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int l = 0, r = 0;
        unordered_map<char,int> mp;
        int idx = 0;
        for(auto ch : s){
            mp[ch] = idx; 
            idx++;
        }
        unordered_set<char> comp;
        unordered_set<char> notComp;
        int n = s.size();
        while(r < n){
            // mp[s[r]]--;
            if(notComp.count(s[r]) == 0) notComp.insert(s[r]);
            if(mp[s[r]] == r){
                notComp.erase(s[r]);
                if(notComp.size() == 0){
                    ans.push_back(r-l+1);
                    l = r+1;
                }
            }
            r++;
        }
        return ans;
    }
};
