class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        sort(points.begin(), points.end(), [](const auto &e1, const auto &e2)
        {
            return (e1[0] * e1[0] + e1[1] * e1[1]) < (e2[0] *e2[0] + e2[1] * e2[1]);
        });

        vector<vector<int>> res{};
        for(auto i{0}; i < K; ++i)
        {
            res.push_back(points[i]);
        }
        
        return res;
    }
};