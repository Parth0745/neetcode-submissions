class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for(char &ch:s){
            if(ch=='('||ch=='['||ch=='{'){
                v.push_back(ch);
            }
            else{
                if((!v.empty()) && ((ch==')' && v.back()=='(')||(ch==']' && v.back()=='[') || (ch=='}' && v.back()=='{'))) v.pop_back();
                else return false;
            
            }
        }
        return v.empty();
    }
};
