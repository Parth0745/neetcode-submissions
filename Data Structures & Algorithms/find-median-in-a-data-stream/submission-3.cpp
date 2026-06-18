class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        if(maxHeap.size()>minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }       
        if(maxHeap.size()<minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if(maxHeap.top()>minHeap.top()) {
            int num = maxHeap.top();
            minHeap.push(num);
            maxHeap.pop();
        }
        
    }
    
    double findMedian() {
        int a = minHeap.size();
        int b = maxHeap.size();
        if( a==b ){
            int num1 = minHeap.top();
            int num2 = maxHeap.top();
            return (num1+num2)/2.0;
        }
        else if( a>b ){
            return minHeap.top();
        }
        else return maxHeap.top();
        return -1;
    }
};
