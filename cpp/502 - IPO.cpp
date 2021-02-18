class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<pair<int, int>> maxHeap{};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap{};
        
        for(auto i{0}; i < Profits.size(); ++i)
        {
            if(Capital[i] <= W)
            {
                maxHeap.push({Profits[i], Capital[i]});
            }
            else
            {
                minHeap.push({Capital[i], Profits[i]});
            }
        }
        
        for(auto i{0}; i < k; ++i)
        {
            while(!minHeap.empty() && minHeap.top().first <= W)
            {
                auto p = minHeap.top();
                minHeap.pop();
                maxHeap.push({p.second, p.first});
            }
            if(!maxHeap.empty())
            {
                W += maxHeap.top().first;
                maxHeap.pop();
            }
        }
        
        return W;
    }
};