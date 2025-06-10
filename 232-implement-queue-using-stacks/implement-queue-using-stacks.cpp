class MyQueue {
public:
string a = "",b = "";
    MyQueue() {
        
    }
    
    void push(int x) {
        a+=to_string(x);
    }
    
    int pop() {
        int x = a[0]-'0';
        a = a.substr(1,a.size());
        return x;
    }
    
    int peek() {
       return a[0]-'0';
    }
    
    bool empty() {
        return a.empty();
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