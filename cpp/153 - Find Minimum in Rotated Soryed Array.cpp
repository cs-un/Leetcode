class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        auto pivot{0};
        if(nums[low] > nums[high])
        {
            while(low <= high)
            {
                auto mid{low + (high - low)/2};
                if(nums[mid] > nums[mid + 1])
                {
                    pivot = mid + 1;
                    break;
                }
                else if(nums[mid] < nums[low])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        return nums[pivot];
    }
};