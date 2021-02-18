class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sums{};

        int tot{0};
        int sum{0};
        sums[0] = 1;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum+=nums[i];
            if(sums.count(sum-k))
            {
                tot += sums[sum-k];
            }

            ++sums[sum];
        }
        
        return tot;
    }
};