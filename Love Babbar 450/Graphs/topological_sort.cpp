#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V, 0);
	    vector<int> ans;
	    queue<int> q;
	    
	   // finding indegrees:
	    for(int i=0; i<V; i++)
	    {
	        for(auto x : adj[i])
	        {
	            indegree[x]++;
	        }
	    }
	    
	    for(int i=0; i<V; i++)
	    {
	        if(indegree[i] == 0) q.push(i);
	    }
	    
	    while(!q.empty())
	    {
	        int curr = q.front();
	        q.pop();
	        ans.push_back(curr);
	        for(auto x : adj[curr])
	        {
	            indegree[x]--;
	            if(indegree[x] == 0) q.push(x);
	        }
	    }
	    
	    return ans;
	}
};

/*

// { Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends

*/
