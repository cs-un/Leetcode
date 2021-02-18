class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        
        for(auto i{1}; i < ratings.size(); ++i)
        {
            if(ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i-1]+1;
            }
        }
        
        for(auto i{(int)ratings.size() - 2}; i >= 0; --i)
        {
            if(ratings[i] > ratings[i + 1])
            {
                candies[i] = max(candies[i+1]+1, candies[i]);
            }
        }
        int sum = 0;
        for(const auto c : candies)
        {
            sum+=c;
        }
        return sum;
    }
};