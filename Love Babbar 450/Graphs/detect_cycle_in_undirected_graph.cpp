#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
    // while traversing just check whether it is the parent or not
    // as we do not want to visit the parent of the particular node
  
    bool solve(int src, int parent, vector<int> &vis, vector<int> g[])
    {
        vis[src] = 1;
        for(auto x : g[src])
        {
            if(!vis[x])
            {
                if(solve(x, src, vis, g)) return true;
            }
            else if(x != parent) return true;
        }
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                // starting node parent is considered -1
                if(solve(i, -1, vis, adj)) return true;
            }
        }
        return false;
    }
};

/*

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends

*/
