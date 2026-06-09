class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int it:arr){
            pq.push({abs(it-x),it});
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            int val=pq.top().second;
            pq.pop();
            ans.push_back(val);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};