class MedianFinder {
public:
    priority_queue<int>left;//stores all the left elements from median
    priority_queue<int,vector<int>,greater<int>>right;//stores all the right elements from the median
    MedianFinder() {
    }
    void addNum(int num) {
        right.push(num);
        while(left.size()<right.size()){
            left.push(right.top());
            right.pop();
        }
        while(right.size() &&  left.top()>right.top()){
            right.push(left.top());
            left.push(right.top());
            right.pop();left.pop();
        }
    }
    
    double findMedian() {
        if((left.size()+right.size())%2 == 0) return (left.top()+right.top())/2.0;
        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */