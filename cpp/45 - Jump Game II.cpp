class Solution {
public:

    int jump(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return 0;
        }
        int n = nums.size();
        auto mm{nums[0]}, prev{nums[0]}, count{1}; 
        for(auto i{1}; i < n; ++i)
        {
            mm = max(mm, nums[i] + i);
            if(i == prev && i != n - 1)
            {
                prev = mm;
                ++count;
            }
        }
        
        return count;
    }  
};