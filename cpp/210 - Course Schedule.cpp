class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool visited[numCourses]{};
        bool visitedThisRun[numCourses]{};
        
        vector<int> adj[numCourses];
        
        for(const auto& pairs : prerequisites)
        {
            adj[pairs[1]].push_back(pairs[0]);
        }
        
        for(auto i{0}; i < numCourses; ++i)
        {
            if (visited[i])
            {
                continue;
            }
            
            if (!canFinish(visited, visitedThisRun, adj, i))
            {
                return false;
            }
        }
        return true;
    }
    
    bool canFinish(bool visited[], bool visitedInThisPath[], vector<int> adj[], int i)
    {
        if(visitedInThisPath[i])
        {
            return false;
        }
        visitedInThisPath[i] = true;
        visited[i] = true;
        
        for(const auto x : adj[i])
        {
            if(!canFinish(visited, visitedInThisPath, adj, x))
            {
                return false;
            }
        }
        visitedInThisPath[i] = false;
        return true;
    }
};