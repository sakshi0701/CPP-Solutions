#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
//   If there exists any cycle in the graph, it denotes that all nodes are dependent on each other and hence the task can not be completed.
//   Hence the code is the same as cycle detection in a directed graph.
  
  // Using BFS:
  // If indegree is greater than 0 for all the nodes at any point means there's a cycle
  bool isCyclic(int V, vector<int> adj[]) {
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
    }
    return 0;
}
  // } Driver Code Ends
  
  */
