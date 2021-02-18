class Solution {
public:
    int maxArea(vector<int>& height) {
        auto l{0};
        int r = height.size() - 1;
        
        auto maxArea{0};
        
        while(l != r)
        {
            maxArea = max(maxArea, min(height[l], height[r]) * (r - l));
            
            if(height[l] < height[r])
            {
                ++l;
            }
            else
            {
                --r;
            }
        }
        
        return maxArea;
    }
};