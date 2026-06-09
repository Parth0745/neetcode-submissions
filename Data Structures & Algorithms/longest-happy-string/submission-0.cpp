class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a){
            pq.push({a,'a'});    
        }
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
        string ans;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int n=ans.size()-1;
            if(ans.size()>1 && ans[n]==ans[n-1] && ans[n]==it.second){
                if(pq.empty()) break;
                auto it1=pq.top();
                pq.pop();
                ans+=it1.second;
                it1.first-=1;
                if(it1.first>0){
                    pq.push({it1.first,it1.second});
                }
            }
            else{
                ans+=it.second;
                it.first-=1;
            }
            if(it.first){
                pq.push({it.first,it.second});

            }
        }
        return ans;
    }
};