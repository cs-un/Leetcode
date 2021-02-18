class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        if(nums.size() == 1)
        {
            return nums[0];
        }
        int sums[nums.size()+1];
        sums[0] = 0;
        sums[1] = nums[0];
        sums[2] = nums[1];
        int maxsum = max(nums[0], nums[1]);
        for(auto i{3}; i <= nums.size(); ++i)
        {
            sums[i] = max(sums[i-2], sums[i-3]) + nums[i - 1];
            maxsum = max(maxsum, sums[i]);
        }
        
        return maxsum;
    }
};