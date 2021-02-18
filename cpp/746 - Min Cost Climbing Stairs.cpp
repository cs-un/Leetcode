class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int minCost[cost.size() + 1] = {};
        
        minCost[0] = cost[0];
        minCost[1] = cost[1];
        for(auto i{2}; i <= cost.size(); ++i)
        {
            minCost[i] = min(minCost[i-1], minCost[i-2]) + (i == cost.size() ? 0 : cost[i]);
        }
        
        return minCost[cost.size()];
    }
};