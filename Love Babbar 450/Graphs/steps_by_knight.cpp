#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int x1 = KnightPos[0];
	    int y1 = KnightPos[1];
	    int x2 = TargetPos[0];
	    int y2 = TargetPos[1];
	    
	    int a[1001][1001];
	    
	   // when the target is reached return distance fro  there  (i.e., 0)
	   // if(x1 == x1 && y1 == y2) return 0;
	    
	   // filling the full board with one
	    for(int i=0; i<N; i++)
	    {
	        for(int j=0; j<N; j++)
	        {
	            a[i][j] = 0;
	        }
	    }
	    
	   // BFS: (as  BFS works in parallel for all the valid paths and so when we reach the target, with any path, then that first path will always be minimum)
	    queue<pair<int,int>> q;
	    
	   // as it is 1 indexed as per the question
	    q.push(make_pair(x1-1, y1-1));
	    while(!q.empty())
	    {
	        auto curr = q.front();
	        int i = curr.first;
	        int j = curr.second;
	        q.pop();
	        
	       // 8 directions:
	       
	       if((i+1) >= 0 && (i+1)<N && (j+2)>=0 && (j+2)<N && a[i+1][j+2] == 0)
	       {
	           //increment 1 from the current index to the new index
	           a[i+1][j+2] = a[i][j] + 1;
	           q.push(make_pair(i+1, j+2));
	       }
	       
	       if((i-1) >= 0 && (i-1)<N && (j+2)>=0 && (j+2)<N && a[i-1][j+2] == 0)
	       {
	           a[i-1][j+2] = a[i][j] + 1;
	           q.push(make_pair(i-1, j+2));
	       }
	       
	       if((i+2) >= 0 && (i+2)<N && (j+1)>=0 && (j+1)<N && a[i+2][j+1] == 0)
	       {
	           a[i+2][j+1] = a[i][j] + 1;
	           q.push(make_pair(i+2, j+1));
	       }
	       
	       if((i-2) >= 0 && (i-2)<N && (j+1)>=0 && (j+1)<N && a[i-2][j+1] == 0)
	       {
	           a[i-2][j+1] = a[i][j] + 1;
	           q.push(make_pair(i-2, j+1));
	       }
	       
	       if((i-1) >= 0 && (i-1)<N && (j-2)>=0 && (j-2)<N && a[i-1][j-2] == 0)
	       {
	           a[i-1][j-2] = a[i][j] + 1;
	           q.push(make_pair(i-1, j-2));
	       }
	       if((i+1) >= 0 && (i+1)<N && (j-2)>=0 && (j-2)<N && a[i+1][j-2] == 0)
	       {
	           a[i+1][j-2] = a[i][j] + 1;
	           q.push(make_pair(i+1, j-2));
	       }
	       
	       if((i-2) >= 0 && (i-2)<N && (j-1)>=0 && (j-1)<N && a[i-2][j-1] == 0)
	       {
	           a[i-2][j-1] = a[i][j] + 1;
	           q.push(make_pair(i-2, j-1));
	       }
	       
	       if((i+2) >= 0 && (i+2)<N && (j-1)>=0 && (j-1)<N && a[i+2][j-1] == 0)
	       {
	           a[i+2][j-1] = a[i][j] + 1;
	           q.push(make_pair(i+2, j-1));
	       }
	       
	    }
	    return a[x2-1][y2-1];
	}
};


/*

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends

*/
