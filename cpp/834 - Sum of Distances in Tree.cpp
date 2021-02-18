class Solution {
public:
    struct node 
    {
        int dist;
        int child_nodes;
    };
    
    node findDists(int root, int parent, vector<vector<int>> &adjacency, map<pair<int, int>, node> &dists)
    {
        auto p = make_pair(root, parent);
        auto it = dists.find(p);
        if(parent != -1 && it != dists.end())
        {
            return it->second;
        }
        
        auto dist{0};
        auto child_nodes{1};
        for(const auto child : adjacency[root])
        {
            if(child != parent)
            {
                auto childNode = findDists(child, root, adjacency, dists);
                dist += childNode.dist + childNode.child_nodes;
                child_nodes += childNode.child_nodes;
            }
        }
        auto n = node();
        n.dist = dist;
        n.child_nodes = child_nodes;
        dists[p] = n;
            
        return dists[p];
    }
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> adjacency(N, vector<int>());
        for(const auto edge : edges)
        {
            auto a = edge[0];
            auto b = edge[1];
            adjacency[a].push_back(b);
            adjacency[b].push_back(a);
        }

        vector<int> ans(N, 0);
        map<pair<int, int>, node> dists;

        for(auto i{0}; i < N; ++i)
        {
            ans[i] = findDists(i, -1, adjacency, dists).dist;
        }
        return ans;
    }
};