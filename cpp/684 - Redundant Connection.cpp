class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& nodes, int e1, int e2, unordered_set<int>& visited)
    {
        if(visited.count(e1))
        {
            return false;
        }
        
        visited.insert(e1);

        if(e1 == e2)
        {
            return true;
        }
        
        for(const auto& edge : nodes[e1])
        {
            if(dfs(nodes, edge, e2, visited))
            {
                return true;
            }
        }
        
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> nodes{};
        
        for(const auto& edge : edges)
        {
            unordered_set<int> visited{};
            if(dfs(nodes, edge[0], edge[1], visited))
            {
                return edge;
            }
            
            if(nodes.count(edge[0]))
            {
                nodes[edge[0]].push_back(edge[1]);
            }
            else
            {
                nodes[edge[0]] = {edge[1]};
            }
            
            if(nodes.count(edge[1]))
            {
                nodes[edge[1]].push_back(edge[0]);
            }
            else
            {
                nodes[edge[1]] = {edge[0]};
            }
        }
        
        return {};
    }
};