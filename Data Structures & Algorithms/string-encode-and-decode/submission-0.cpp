class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for( auto it: strs){
            int size = it.size();
            encoded += to_string(size);
            encoded += "#";
            encoded += it;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int l = 0; int size = 0;
        while( l < s.size() ){
            string temp = "";
            while(s[l]!='#'){
                temp += s[l++];
            }
            l++;
            size = stoi(temp);
            string word = "";
            for( int i = l; i < l+size ; i++){
                word += s[i];
            }
            ans.push_back(word);
            l = l + size;
        }
        return ans;
    }
};
