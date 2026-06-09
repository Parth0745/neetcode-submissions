class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
        
    }
    
    void push(int val) {
        if(!st.empty()){
            minSt.push(min(minSt.top(),val));
        }
        else{
            minSt.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        // int a=st.pop();
        // if(minSt.top()==st.top()) minSt.pop();
        st.pop();
        minSt.pop();// because it stores minimum upto that index so as soon as it is removed then irrespective of the equalness just remove as we will get minimum till last index in minSt
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
