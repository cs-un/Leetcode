class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(const auto& num : nums)
        {
            sum+=num;
        }
        
        for(auto i{0}; i <= nums.size(); ++i)
        {
            sum-=i;
        }
        
        return -sum;
    }
};