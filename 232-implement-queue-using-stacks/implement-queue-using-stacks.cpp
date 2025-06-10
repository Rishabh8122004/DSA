class MyQueue {
public:
stack<int>s;
stack<int>st;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        while(s.size()>1){
            st.push(s.top());
            s.pop();
        }
        int x = s.top();
        s.pop();
        while(st.size()){
            s.push(st.top());
            st.pop();
        }
        return x;
    }
    
    int peek() {
        while(s.size()>1){
            st.push(s.top());
            s.pop();
        }
        int x = s.top();
        while(st.size()){
            s.push(st.top());
            st.pop();
        }
        return x;
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */