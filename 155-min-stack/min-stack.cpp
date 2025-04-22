class MinStack {
public:
    stack<int>st;
    stack<int>m;
    MinStack() { // constructor
        
    }
    
    void push(int val) {
        st.push(val);
        if(m.size() == 0)m.push(val);
        else m.push(min(val,m.top()));
    }
    
    void pop() {
        st.pop();
        m.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return m.top();
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