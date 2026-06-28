class Solution {
public:
    vector<int> topoSort(int k, unordered_map<int,vector<int>> &adjList){
        queue<int> q;
        vector<int> indeg(k+1,0);
        for( auto &edge: adjList){
            for( auto it: edge.second){
                indeg[it]++;
            }
        }
        for( int i = 1 ; i <=k ; i++){
            if( indeg[i] == 0 ){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            auto node = q.front(); q.pop();
            ans.push_back(node);
            for( auto neigh : adjList[node]){
                indeg[neigh]--;
                if( indeg[neigh] == 0 ){
                    q.push(neigh);
                }
            }
        }
        if( ans.size() != k ) return {};
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        unordered_map<int,vector<int>> row;
        unordered_map<int,vector<int>> col;
        for(auto &edge: rowConditions){
            row[edge[0]].push_back(edge[1]);
        }
        for(auto &edge: colConditions){
            col[edge[0]].push_back(edge[1]);
        }
        vector<int> rowTopo = topoSort(k,row);
        vector<int> colTopo = topoSort(k,col);

        if( rowTopo.size()==0 || colTopo.size() == 0 ) return {};

        vector<vector<int>> ans(k,vector<int> (k,0));
        for( int i = 0 ; i < rowTopo.size(); i++){
            for ( int j = 0 ; j < rowTopo.size(); j ++ ){
                if( rowTopo[i] == colTopo[j] ){
                    ans[i][j] = rowTopo[i];
                }
            }
        }
        return ans;
    }
};