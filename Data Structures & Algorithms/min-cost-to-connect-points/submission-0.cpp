class Solution {
public:
    int helper( vector<vector<int>>& points, int node, int i){
        return abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> vis(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int ans = 0;
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second; 
            pq.pop();
            if ( vis[node] ) continue;
            vis[node] = true;
            ans += wt;
            for( int i = 0; i < n ; i++){
                if(!vis[i]){
                    int dist = helper(points,node, i);
                    pq.push({dist, i});
                }
            }
        }
        return ans;
    }
};
