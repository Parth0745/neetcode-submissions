class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        int n=nums.size();
        // priority_queue<pair<int,int>> pq;
        // for(auto it:mp){
        //     pq.push({it.second,it.first});
        // }
        vector<int> ans;
        // for(int i=0;i<k;i++){
        //     pair<int,int> p=pq.top();
        //     pq.pop();
        //     ans.push_back(p.second);
        // }
        vector<vector<int>> v(n+1);
        for(auto it:mp){
            v[it.second].push_back(it.first);
        }
        int c=0;
        for(int i=n;i>=1;i--){
            for(auto x:v[i]){
                ans.push_back(x);
                c++;
                if(c==k) return ans;
            }
        }
        return ans;

    }
};
