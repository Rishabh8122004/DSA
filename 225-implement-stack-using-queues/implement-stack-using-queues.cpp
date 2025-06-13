class MyStack {
public:
    queue<int>q;
    int size;
    MyStack() {
        size = 0;
    }
    
    void push(int x) {
        q.push(x);
        size = q.size()-1;
        while(size--){
            q.push(q.front());
            q.pop();
        }
        size = q.size();
    }
    
    int pop() {
        int a = q.front();
        q.pop();
        return a;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */