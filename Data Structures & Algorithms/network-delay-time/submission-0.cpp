class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> edges(n+1);
        for( auto it: times ){
            edges[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        minHeap.push({0,k});
        int ans = 0;
        unordered_set<int> vis;
        while(!minHeap.empty()){
            auto [length, node] = minHeap.top(); minHeap.pop();
            if(vis.count(node)) continue;
            vis.insert(node);
            ans = length;
            for( auto neigh : edges[node]){
                if(vis.count(neigh.first) == 0) minHeap.push({neigh.second+length, neigh.first});
            } 
        }
        return vis.size() == n ? ans: -1;
    }
};
