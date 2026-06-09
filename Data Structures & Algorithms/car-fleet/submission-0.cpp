class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<float> st;
        int ans=0;
        vector<pair<int,int>> cars;
        for(int i=0;i<speed.size();i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.rbegin(),cars.rend());
        // int ans=1;
        int pl=position.size(),s=speed.size();
        for(int i=0;i<s;i++){
            st.push_back((float)(target-cars[i].first)/cars[i].second);
            int n=st.size();
            if(st.size()>1 && st[n-1]<=st[n-2]){
                st.pop_back();
            }
            else{
                ans++;
            } 
        }
        return st.size();
        // st.push((float)(target-position[pl-1])/(float)speed[s-1]);
        // int ans=1;
        // for(int i=s-2;i>=0;i--){
        //     float comp=(float)(target-position[i])/(float)speed[i];
        //     if(st.top()<=comp){
        //         // st.pop();
                
        //     }
        //     else{
        //         ans++;
        //         st.push(comp);
        //     }
        // }
        return ans;
    }
};
