class MedianFinder {
public:
    priority_queue<int> max_heap; // store smallest part
    priority_queue<int , vector<int>, greater<int>> min_heap; // store largest part
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.top()); // to make sure min heap has all biggest values
        max_heap.pop(); // erase top from max_heap to avoid inconsistancy 

        if(min_heap.size() > max_heap.size()) { // to handle odd case
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(max_heap.size() > min_heap.size()) {
            return max_heap.top();
        }
        return (max_heap.top() + min_heap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */