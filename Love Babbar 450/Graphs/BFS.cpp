#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> g[]) {
        vector<int> ans;
        queue<int> q;
        q.push(0);
        vector<int> vis(V, 0);
        // first node is visited
        vis[0] = 1;
        
        while(!q.empty())
        {
            int a = q.front();
            q.pop();
            ans.push_back(a);
            for(auto x : g[a])
            {
                if(!vis[x])
                {
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
        return ans;
    }
};

/*

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends

*/