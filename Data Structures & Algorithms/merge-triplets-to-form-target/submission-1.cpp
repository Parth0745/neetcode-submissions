class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0], y = target[1], z = target[2];
        vector<vector<int>> possible;
        int count = 0;
        int a = 0 , b = 0 , c = 0;
        for(auto it: triplets){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if( u == x ){
                if( v <= y && w <= z ){
                    a++;
                }
            }
            if( v == y ){
                if( u <= x && w <= z ){
                    b++;
                }
            }
            if( w == z ){
                if( u <= x && v <= y ){
                    c++;
                }
            }
            
        }
        // bool a = false, b = false, c = false;
        // for(auto it : possible){
        //     int u = it[0];
        //     int v = it[1];
        //     int w = it[2];
        //     if( u == x ){
        //         a = true;
        //     }
        //     if( v == y ){
        //         b = true;
        //     }
        //     if( w == z ){
        //         c = true;
        //     }
        // }
        // return a && b && c;
        return (a > 0) && ( b > 0 ) && ( c > 0); 
    }
};
