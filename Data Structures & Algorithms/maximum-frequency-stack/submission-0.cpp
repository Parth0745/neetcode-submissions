class FreqStack {
public:
    unordered_map<int,int> mp;
    unordered_map<int,stack<int>> groups;
    int maxFreq=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++;
        if(maxFreq<mp[val]){
            maxFreq=mp[val];
        }
        groups[mp[val]].push(val);
    }
    
    int pop() {
       int a=groups[maxFreq].top();
       groups[maxFreq].pop();
       if(groups[maxFreq].empty()){
            maxFreq--;
       }
        mp[a]--;
        return a;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */