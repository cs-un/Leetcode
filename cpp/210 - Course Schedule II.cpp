class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        bool visited[numCourses]{};
        bool rootNode[numCourses]{false};
        bool visitedThisRun[numCourses]{false};

        vector<int> adj[numCourses];
        vector<int> order;
        set<int> added;
        
        for(const auto& pairs : prerequisites)
        {
            adj[pairs[0]].push_back(pairs[1]);
            rootNode[pairs[1]] = true;
        }
        
        for(auto i{0}; i < numCourses; ++i)
        {
            if (visited[i] || rootNode[i])
            {
                continue;
            }
            if(!addRoot(visited,visitedThisRun, adj, order, i))
            {
                return {};
            }
        }
        
        if(order.size() != numCourses)
        {
            return {};
        }
        
        return order;
    }
    
    bool addRoot(bool visited[], bool visitedInThisPath[], vector<int> adj[], vector<int>& order, int i)
    {
        if(visitedInThisPath[i])
        {
            return false;
        }
        if(visited[i])
        {
            return true;
        }
        
        visited[i] = true;
        
        if(adj[i].empty())
        {
            order.push_back(i);
            return true;
        }
        visitedInThisPath[i] = true;

        for(const auto x : adj[i])
        {
            if(!addRoot(visited, visitedInThisPath, adj, order, x))
            {
                return false;
            }
        }
        order.push_back(i);
        visitedInThisPath[i] = false;
        return true;
    }
};