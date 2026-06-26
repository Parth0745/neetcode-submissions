class Solution {
private:
    
public:
    vector<int> indeg = vector<int> (26,-1);
    void indegree(unordered_map<char,vector<char>> &mp){
        for( auto it: mp ){
            for(auto it1: it.second){
                indeg[it1-'a']++;
            }
        }
    }

    string topoSort(unordered_map<char,vector<char>> &mp){
        queue<char> q;
        for( int i = 0 ; i < 26; i++){
            if(indeg[i] == 0){
                q.push( i + 'a');
            }
        }
        string ans = "";
        while(!q.empty()){
            auto a = q.front(); q.pop();
            ans += a;
            for(auto neigh : mp[a]){
                indeg[neigh-'a']--;
                if( indeg[neigh - 'a'] == 0 ){
                    q.push(neigh);
                }
            }
        }
        return ans;
    }
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,vector<char>> mp;
        int n = words.size();
        int countNodes = 0;
        for(auto word:words){
            for(auto ch: word){
                if( indeg[ch-'a'] == -1 ) {indeg[ch-'a'] = 0; countNodes++;}
            }
        }
        
        for( int i = 1; i < n ;i ++){
            int m = words[i-1].size();
            int k = words[i].size();
            int len = min(m,k);
            int j = 0;
            for( j = 0; j < len; j++){
                if( words[i-1][j] != words[i][j] ){
                    mp[words[i-1][j]].push_back(words[i][j]);
                    break;
                }
            }
            if( j == len && m > k ) return "";
        }

        indegree(mp);
         string ans =  topoSort(mp);
        if(ans.size() != countNodes) return "";
        return ans;
    }
};
