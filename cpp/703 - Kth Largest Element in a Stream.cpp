class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        pq = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
        while(pq.size() > k)
        {
            pq.pop();
        }
        K = k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > K)
        {
            pq.pop();
        }
        return pq.top();
    }
};