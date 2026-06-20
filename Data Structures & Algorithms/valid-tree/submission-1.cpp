class Solution {
public:
    bool dfs( int i , vector<vector<int>> &neigh, vector<bool> &vis, int prev){
        if(vis[i]) return false;
        vis[i]= true;
        for( auto it: neigh[i]){
            if(it!= prev){
                if(!dfs(it, neigh, vis, i)) return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        vector<vector<int>> neigh(n);
        
        for( auto &it: edges){
            neigh[it[0]].push_back(it[1]);
            neigh[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n);
        // int count = 0;
        if(!dfs(0,neigh, vis, -1)) return false;
        for( auto it: vis ){
            if( it == false ) return false;
        }
        return true;
    }
};
