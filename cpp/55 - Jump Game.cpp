class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return true;
        }
        if(nums[0] == 0)
        {
            return false;
        }
        int n = nums.size();
        auto mm{nums[0]}, prev{nums[0]}; 
        for(auto i{1}; i < n; ++i)
        {
            mm = max(mm, nums[i] + i);
            if(i == prev && i != n - 1)
            {
                if(mm == prev)
                {
                    return false;
                }
                prev = mm;
            }
        }
        
        return mm >= nums.size() - 1;
    }
};