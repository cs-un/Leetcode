class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k != 0 )
        {
            return false;
        }
        
        map<int, int> ss{};
        for(const auto& num : nums)
        {
            ++ss[num];
        }
        
        for(auto &i : ss)
        {
            while(i.second > 0)
            {
                for(auto x{i.first}; x < i.first + k; ++x)
                {
                    if(!ss[x])
                    {
                        return false;
                    }
                    --ss[x];
                }
            }
        }
        return true;
    }
};