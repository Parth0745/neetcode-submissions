class Solution {
public:

    bool dfs( int node, int end, unordered_map<int,vector<int>> &neigh, vector<int> &vis ){
        if(node == end ) return true;
        vis[node] = 1;
        for( auto it: neigh[node]){
            if(!vis[it]){
                if(dfs(it, end, neigh, vis)) return true;
            }
        }
            return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& nums, vector<vector<int>>& queries) {
        vector<int> parent(numCourses,-1);
        unordered_map<int,vector<int>> neigh;
        for( auto &it: nums){
            neigh[it[0]].push_back(it[1]);
            // parent[it[1]] = it[0];
        }
        vector<bool> ans(queries.size());
        int i = 0;
        for( auto &it:queries){
            vector<int> vis(numCourses);
            ans[i++] = dfs(it[0],it[1],neigh, vis);
        }
        return ans;
    }
};