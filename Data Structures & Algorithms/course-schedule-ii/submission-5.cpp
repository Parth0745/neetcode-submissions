class Solution {
public:
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& nums) {
        unordered_map<int,vector<int>> mp;
        vector<int> indegree(numCourses,0);
        for( auto it: nums){
            // if(mp.find(it[0]) != mp.end()) return {};
            mp[ it[1] ].push_back( it[0] );
            indegree[it[0]]++;
        }
        queue<int> q;
        for( int i =0 ; i <= numCourses-1; i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int a = q.front(); q.pop();
            ans.push_back(a);
            for(auto it: mp[a]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if( ans.size() != numCourses) return {};
        return ans;

    }
};
