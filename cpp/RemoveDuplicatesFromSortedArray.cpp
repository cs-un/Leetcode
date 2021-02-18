class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto i{0};
        
        for(auto j{1}; j < nums.size(); ++j)
        {
            if(nums[i]!=nums[j])
            {
                nums[++i] = nums[j];
            }
        }
        
        return i + !nums.empty();
    }
};