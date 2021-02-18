class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        auto s{nums[nums[0]]}, ss{nums[nums[nums[0]]]};
        
        while(s != ss)
        {
            s = nums[s];
            ss = nums[nums[ss]];
        }
        
        s = nums[0];
        
        while(s != ss)
        {
            s = nums[s];
            ss = nums[ss];
        }
        
        return s;
    }
};