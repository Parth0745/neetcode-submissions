class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0], y = target[1], z = target[2];
        vector<vector<int>> possible;
        for(auto it: triplets){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if( u == x ){
                if( v <= y && w <= z ){
                    possible.push_back(it);
                }
            }
            else if( v == y ){
                if( u <= x && w <= z ){
                    possible.push_back(it);
                }
            }
            else if( w == z ){
                if( u <= x && v <= y ){
                    possible.push_back(it);
                }
            }
            
        }
        bool a = false, b = false, c = false;
        for(auto it : possible){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if( u == x ){
                a = true;
            }
            if( v == y ){
                b = true;
            }
            if( w == z ){
                c = true;
            }
        }
        return a && b && c;
    }
};
