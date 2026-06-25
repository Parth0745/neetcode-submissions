class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if( parent[x]==x ) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b){
        int x = find(a);
        int y = find(b);
        if( x == y ) return;
        if( rank[x] < rank[y] ){
            parent[x] = y;
        }
        else if( rank[x] > rank[y] ){
            parent[y] = x;
        }
        else{
            parent[x] = y;
            rank[y]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        iota(parent.begin(),parent.end(),0);
        // vector<int> vis(n,0);
        for( auto it: edges ){
            int u = it[0];
            int v = it[1];
            if( find(u) == find(v) ) return it;
            unite(u,v);
        }
        return {};
    }
};
