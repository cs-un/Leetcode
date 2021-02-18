class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);

        for(auto i{1}; i < nums.size(); ++i)
        {
            res[i] = res[i-1] * nums[i-1];
        }
        
        auto right{1};
        for(int i = nums.size() - 1; i >= 0; --i)
        {
            res[i] *= right;
            right *= nums[i];
        }
        
        return res;
    }
};