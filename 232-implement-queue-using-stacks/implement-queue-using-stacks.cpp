class MyQueue {
public:
    stack<int>s;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int>t;
        while(!s.empty()){
            t.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!t.empty()){
            s.push(t.top());
            t.pop();
        }
    }
    
    int pop() {
        int x = s.top();
        s.pop();
        return x;
    }
    
    int peek() {
        return s.top();
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