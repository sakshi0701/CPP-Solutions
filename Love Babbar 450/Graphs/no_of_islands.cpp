#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void dfs(int i, int j, int vis[][501], int n, int m, vector<vector<char>>& g)
    {
        // boundary condition:
        if(i<0 || i>=n || j<0 || j>=m) return;
        if(g[i][j] == '0') return;
        
        if(!vis[i][j])
        {
            vis[i][j] = 1; 
            // 8 directions:
            dfs(i-1, j-1, vis, n, m, g);
            dfs(i-1, j, vis, n, m, g);
            dfs(i-1, j+1, vis, n, m, g);
            dfs(i, j-1, vis, n, m, g);
            dfs(i, j+1, vis, n, m, g);
            dfs(i+1, j-1, vis, n, m, g);
            dfs(i+1, j, vis, n, m, g);
            dfs(i+1, j+1, vis, n, m, g);
        }
    }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
    // Code here// if we get 1 and the path is satisfying boundary conditions, we continue our dfs search
    // then we keep increasing our counter as to how many times dfs was executed
    
        int n = grid.size();
        int m = grid[0].size();
        
        if(n == 0) return 0;
        
        int vis[501][501];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                vis[i][j] = 0;
            }
        }

      // counter
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, vis, n, m, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends
