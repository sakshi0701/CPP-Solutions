// will work like topological sort as we take the nodes of indgree of 0 out first
// we create an array of the time (required answer) in which we will add 1 to time taken by the parent node;

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v, e;
    cin>>v>>e;
    std::vector<int> g[v+1];
    vector<int> indegree(v+1, 0);
    
    // calculating indegrees while making the graph too:
    for(int i=0; i<e; i++)
    {
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        indegree[y]++;
    }
    
    vector<int> ans(v+1, 0);
    std::queue<int> q;
    // if indgree is zero in the starting then time = 1
    for(int i=1; i<=v; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
            ans[i] = 1;
        }
    }
    
    while(!q.empty())
    {
        int val = q.front();
        q.pop();
        for(auto x : g[val])
        {
            indegree[x]--;
            if(indegree[x] == 0)
            {
                q.push(x);
                // parent time + 1
                ans[x] = ans[val] + 1;
            }
        }
    }
    
//   printing the answer array
    for(int i=1; i<=v; i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}
