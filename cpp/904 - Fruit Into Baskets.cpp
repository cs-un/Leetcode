class Solution {
public:
    int totalFruit(vector<int>& tree) {
        auto mmax{0};
        auto currmax{0};
        auto t1{-1}, t2{-1}, last{-1};
        for(auto i{0}; i < tree.size(); ++i)
        {
            if(t1 == -1)
            {
                t1 = tree[i];
            }
            else if (t2 == -1 && tree[i] != t1)
            {
                t2 = tree[i];
                last = i;
            }
            if (t1 == tree[i] || t2 == tree[i])
            {
                ++currmax;
            }
            else
            {
                mmax = max(mmax, currmax);
                t1 = -1, t2 = -1;
                currmax = 0;
                i = last - 1;
                last = i;
            }
        }
        return max(mmax, currmax);
    }
};