class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
        {
            return -1;
        }
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
        if(target <= nums[nums.size() - 1])
        {
            high = nums.size() - 1;
            low = pivot;
        }
        else
        {
            high = pivot - 1;
            low = 0;
        }

        while(low <= high)
        {
            auto mid{low + (high - low)/2};
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return -1;
    }
};