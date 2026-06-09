class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            pair<int,int> p=pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;

    }
};
