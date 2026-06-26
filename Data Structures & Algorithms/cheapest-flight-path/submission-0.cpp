    class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            unordered_map<int,vector<pair<int,int>>> adj;
            for( auto it: flights){
                adj[it[0]].push_back({it[1],it[2]});
            }
            vector<int> dis(n,INT_MAX);
            dis[src] = 0;
            queue<pair<int,pair<int,int>>> q; // it will store (stops, node, dist);
            q.push({0,{src,0}});
            while( !q.empty() ){
                auto it = q.front();
                q.pop();
                int stops = it.first;
                int node = it.second.first;
                int dist = it.second.second;
                if( stops > k) continue;
                for(auto neigh: adj[node]){
                    if( dist + neigh.second < dis[neigh.first] && stops  <=k){
                        dis[neigh.first] = dist + neigh.second;
                        q.push({stops+1,{neigh.first, dist + neigh.second}});
                    }
                }
            }
            return dis[dst] == INT_MAX ? -1 : dis[dst];
            
        }
    };
