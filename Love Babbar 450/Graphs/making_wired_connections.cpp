class Solution {
public:
    
    void dfs(int src, vector<int> g[], vector<int> &vis)
    {
        vis[src] = 1;
        for(auto x : g[src])
        {
            if(!vis[x]) dfs(x, g, vis);
        }
    }
    
//     number of edges to connect c components is = c-1 edges.
    int makeConnected(int n, vector<vector<int>>& connections) {
//         graph:
        vector<int> g[n];
        int edges = connections.size();
        
//         as we should have atleast components-1 edges available
        if(edges < n-1) return -1;
        
        for(int i=0; i<edges; i++)
        {
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<int> vis(n, 0);
        int components = 0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                components++;
                dfs(i, g, vis);
            }
        }
        return components-1;
    }
};
