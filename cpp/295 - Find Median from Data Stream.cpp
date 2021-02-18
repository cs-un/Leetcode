class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minHeap{};
    priority_queue<int> maxHeap{};
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num < maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }
        
        if(maxHeap.size() - minHeap.size() == 2)
        {
            auto n = maxHeap.top();
            minHeap.push(n);
            maxHeap.pop();
        }
        else if(minHeap.size() - maxHeap.size() == 2)
        {
            auto n = minHeap.top();
            maxHeap.push(n);
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == 0 && minHeap.size() == 0)
        {
            return 0;
        }
        if(maxHeap.size() == minHeap.size())
        {
            return (double)(maxHeap.top() + minHeap.top()) / 2;
        }
        else if(maxHeap.size() > minHeap.size())
        {
            return maxHeap.top();
        }
        else
        {
            return minHeap.top();
        }
    }
};