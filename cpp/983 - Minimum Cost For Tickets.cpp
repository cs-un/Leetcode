class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int day[366]{};
        unordered_set<int> traveling_days{days.begin(), days.end()};
        for(auto i{1}; i <= 365; ++i)
        {
            if(!traveling_days.count(i))
            {
                day[i] = day[i-1];
            }
            else
            {
                day[i] = min(
                    min(day[i-1] + costs[0], 
                        day[max(i-7, 0)] + costs[1]), 
                        day[max(i-30, 0)] + costs[2]);
            }
        }
        return day[365];
    }
};