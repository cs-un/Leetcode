class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto counter{m + n - 1};
        --m;
        --n;
        while (counter >= 0)
        {
            if (n < 0 || m >= 0 && nums1[m] > nums2[n])
            {
                nums1[counter--] = nums1[m--];
            }
            else 
            {
                nums1[counter--] = nums2[n--];
            }
        }
    }
};