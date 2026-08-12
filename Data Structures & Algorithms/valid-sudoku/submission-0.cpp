class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,vector<char>> rows;
        unordered_map<int,vector<char>> cols;
        unordered_map<int,vector<char>> box;
        for(int i = 0 ; i < board.size() ; i++){
            for( int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] != '.'){
                    rows[i].push_back(board[i][j]);
                    cols[j].push_back(board[i][j]);
                    int col = (j)/3;
                    int row = (i)/3;
                    int boxx = row*3 + col;
                    box[boxx].push_back(board[i][j]);
                }
            }
        }

        for(int i = 0 ; i < board.size() ; i++){
            for( int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] != '.'){
                    int count = 0;
                    for(auto it: rows[i]){
                        if(it == board[i][j]) count++;
                    }
                    if(count > 1) return false;
                    count = 0;
                    for(auto it: cols[j]){
                        if(it == board[i][j]) count++;
                    }
                    if(count > 1) return false;
                    count = 0;
                    int col = (j)/3;
                    int row = (i)/3;
                    int boxx = row*3 + col;
                    for(auto it: box[boxx]){
                        if(it == board[i][j]) count++;
                    }
                    if(count > 1) return false;
                }
            }
        }
        return true;
    }
};
