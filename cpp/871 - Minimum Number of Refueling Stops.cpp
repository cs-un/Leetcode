class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        long maxPossible[stations.size() + 1]{};
        maxPossible[0] = startFuel;
        for(auto i{0}; i < stations.size(); ++i)
        {
            auto curr = stations[i][0];
            for(auto j{i}; j >= 0; --j)
            {
                if(maxPossible[j] >= curr)
                {
                    maxPossible[j + 1] = max(maxPossible[j + 1], maxPossible[j] + stations[i][1]);
                }
            }
        }
        
        
        for(auto i{0}; i <= stations.size(); ++i)
        {
            if(maxPossible[i] >= target)
            {
                return i;
            }
        }
        
        return -1;
    }
};