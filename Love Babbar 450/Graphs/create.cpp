// ADJACENCY MATRIX

/*

#include<bits/stdc++.h>
using namespace std;
  
int main() {
 
    int v,e;
    cin>>v>>e;
    int g[v+1][v+1];
  
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++) g[i][j] = 0;
    }
  
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x][y] = 1;
        g[y][x] = 1;
    }
 
    for(int i=1;i<=v;i++)
    {
        cout<<i<<"--> ";
        for(int j=1;j<=v;j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

*/

----------------------------------------------------------------------------------------------------------------------------------------------------//
  
 // ADJACENCY LIST

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v, e;
    cin>>v>>e;
    // vector of nodes only as edge distribution is not known as of now
    vector<int> g[v+1];
    for(int i=0; i<e; i++)
    {
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    
    // printing
    for(int i=1; i<=v; i++)
    {
        cout<<i<<"-->";
        for(int j=0; j<g[i].size(); j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
