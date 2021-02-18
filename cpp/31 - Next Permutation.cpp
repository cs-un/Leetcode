class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int start = nums.size() - 2;
        
        while(start >= 0 && nums[start] >= nums[start+1])
        {
            --start;
        }
        if(start >= 0)
        {
            int end = nums.size() - 1;
            while(end >= 0 && nums[end] <= nums[start])
            {
                --end;
            }
            
            swap(nums[start], nums[end]);
        }
        reverse(nums.begin() + start + 1, nums.end());
    }
};