class MyCircularQueue {
public:
    int size,f,b,k;
    vector<int>v;

    MyCircularQueue(int k) {
        size = 0;
        vector<int> t(k);
        v = t;
        f = 0,b = 0;
        this->k = k;
    }
    
    bool enQueue(int value) {
        if(size == k){return false;}
        v[b%k] = value;b++;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size == 0)return false;
        f++;
        if(f == k)f = 0;
        size--;
        return true;
    }
    
    int Front() {
        if(size == 0)return -1;
        return v[f];
    }
    
    int Rear() {
        if(size == 0)return -1;
        if(b%k == 0)return v[k-1];
        return v[(b%k)-1];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */