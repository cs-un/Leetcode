class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)
        {
            return 0;
        }
        
        vector<int> left(height.size());
        vector<int> right(height.size());
        left[0] = height[0];
        right[height.size() - 1] = height[height.size() - 1];

        for(auto i{1}; i < height.size(); ++i)
        {
            left[i] = max(height[i], left[i-1]);
        }

        for(int i = height.size() - 2; i >= 0; --i)
        {
            right[i] = max(height[i], right[i+1]);
        }

        auto sum{0};
        for(auto i{0}; i < height.size(); ++i)
        {
            if(left[i] <= height[i] || height[i] >= right[i])
            {
                continue;
            }
            else
            {
                sum += min(right[i], left[i]) - height[i];
            }
        }

        return sum;
    }
};