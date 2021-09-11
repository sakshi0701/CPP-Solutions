#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    void dfs(int src, vector<vector<int>> &g, vector<int> &vis, string &ans)
    {
        vis[src] = 1;
        for(auto x : g[src])
        {
            if(!vis[x])
            {
                dfs(x, g, vis, ans);
            }
        }
        // converting the src to char
        char ch = src + 'a';
        ans = ch + ans;
    }
    
//   topological sort application
    string findOrder(string dict[], int N, int K) {
       vector<vector<int>> g(K);
       for(int i=0; i<N-1; i++)
       {
           string a = dict[i];
           string b = dict[i+1];
           
        //   comparing the two strings for judgement:
           for(int j=0; j<min(a.size(), b.size()); j++)
           {
            //   whichever comes first is smaller and hence the graph edge will point from smaller char to larger char
               if(a[j] != b[j])
               {
                   g[a[j] - 'a'].push_back(b[j]-'a');
                   break;
               }
           }
       }
    
        vector<int> vis(K, 0);
        string ans = "";
        for(int i=0; i<K; i++)
        {
            if(!vis[i])
            {
                dfs(i, g, vis, ans);
            }
        }
        return ans;
    }
};

/*

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
  
  */
