class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(auto i{0}; i < n; ++i)
        {
            if(nums[i] <= 0)
            {
                nums[i] = n + 1;
            }
        }
        
        for(auto num : nums)
        {
            auto nn = abs(num);
            if(nn <= n)
            {
                nums[nn-1] = -1 * abs(nums[nn-1]);
            }
        }
        
        for(auto i{0}; i < n; ++i)
        {
            if(nums[i] > 0)
            {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};