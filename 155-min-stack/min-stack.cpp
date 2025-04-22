class MinStack {
public:
    stack<long long>st;
    long long m;
    MinStack() { // constructor
        
    }
    
    void push(int val) {
        if(st.empty()){st.push(val);m = val;}
        else{
            if(val<m){st.push(val-m+val);m = val;}
            else st.push(val);
        }
    }
    
    void pop() {
       if(st.top()<m){m = 2*m-st.top();}
       st.pop();
    }
    
    int top() {
        if(st.top()<m)return m;
        return st.top();
    }
    
    int getMin() {
        return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */