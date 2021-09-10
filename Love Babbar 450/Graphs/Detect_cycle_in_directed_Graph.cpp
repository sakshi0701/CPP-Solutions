#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
//   Using DFS:
    bool solve(int src, vector<int> &vis, vector<int> &order, vector<int> g[])
    {
        vis[src] = 1;
        order[src] = 1;
        for(auto x : g[src])
        {
            if(!vis[x])
            {
                if(solve(x, vis, order, g) == true) return true;
            }
            // if order[element] is 1, it means that node has already been printed
            else if(order[x]) return true;
        }
        order[src] = 0;
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> order(V, 0);
        
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                bool c = solve(i, vis, order, adj);
                if(c==true)
                    return true;
            }
        }
        return false;
    }
  
  // Using BFS:
  // If indegree is greater than 0 for all the nodes at any point means there's a cycle
  bool isCyclicBFS(int V, vector<int> adj[]) {
    queue<int> q;
    vector<int> indegree(V, 0);
    // calculating indegree:
    for(int i=0; i<V; i++)
    {
        for(auto x : adj[i]) indegree[x]++;
    }
    
    for(int i=0; i<V; i++)
    {
        if(indegree[i] == 0) q.push(i);
    }
    
    int counter = q.size();
    while(!q.empty())
    {
        int a = q.front();
        q.pop();
        // (works similar to topological sort: )
        for(auto x : adj[a])
        {
            indegree[x]--;
            if(indegree[x] == 0)
            {
                q.push(x);
                counter++;
            }
        }
    }
    
    // checking how many nodes have indegree 0 with counnter: (if all then no cycle)
    if(counter == V) return false;
    
    return true;
    
    }
};

/*

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
        cout << obj.isCyclicBFS(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
  
  */
