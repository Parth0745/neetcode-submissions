class Solution {
public:
    bool dfs(int node, vector<bool> &vis, unordered_map<int, vector<int>> &mp, int parent){
        if(vis[node]) return false;
        vis[node] = true;
        for(auto neigh: mp[node]){
            if(neigh!=parent){
                if(!dfs(neigh, vis, mp, node)) return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        //for a valid tree - no cycle must exist and graph must be connected
        unordered_map<int, vector<int>> mp;
        for( auto edge: edges){
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }
         vector<bool> vis(n,false);
        if( !dfs(0,vis,mp,-1) ) return false; // cycle exists
        for( auto it: vis){
            if(!it) return false;
        } 
        return true;
    }
};
