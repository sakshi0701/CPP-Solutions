#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    vector<string> ans;
    
    void dfs(int i, int j, string s, vector<vector<int>> m, int n, vector<vector<int>> &vis)
    {
        // boundary conditions:
        if(i<0 || j<0 || i>=n || j>=n) return;
        
        if(m[i][j] == 0 || vis[i][j] == 1) return;
        
        if(i == n-1 && j == n-1)
        {
            ans.push_back(s);
        }
        vis[i][j] = 1;
        
        dfs(i-1, j, s+'U', m, n, vis);
        dfs(i+1, j, s+'D', m, n, vis);
        dfs(i, j-1, s+'L', m, n, vis);
        dfs(i, j+1, s+'R', m, n, vis);
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> vis(1002, vector<int>(1002));
        // if first or the destination position is 0 then it is not possible
        if(m[0][0] == 0) return ans;
        if(m[n-1][n-1] == 0) return ans;
        
        string s = "";
        
        dfs(0, 0, s, m, n, vis);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends

*/
