#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// function to return how many elements are smaller than or equal to the mid value passed
int counter(int mat[MAX][MAX], int n, int k, int mid)
{
    int count = 0;
    int rows = n;
    int cols = n;
    int j = cols - 1;
    for(int i = 0; i<rows; i++)
    {
        for(j; j>=0; j=j-1)
        {
            if(mat[i][j]<=mid)
            {
                count += j+1;
                break;
            }
        }
    }
    return count;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  int low = mat[0][0];
  int high = mat[n-1][n-1];
  
  while(low<high)
  {
      int mid = floor((high-low)/2+low);
      int count = counter(mat,n,k,mid);
      if(count>=k)
      {
          high = mid;
      }
      else
      {
          low = mid+1;
      }
  }
  return low;
}