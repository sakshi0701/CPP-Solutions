#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    int maxSubarraySum(int arr[], int n){
        
        int max_sum = INT_MIN;
        int curr_sum = 0;
        
        for(int i=0; i<n; i++)
        {
            curr_sum = curr_sum + arr[i];
            if(curr_sum > max_sum)
            {
                max_sum = curr_sum;
            }
            
            if(curr_sum < 0)
            {
                curr_sum = 0;
            }
        }
        return max_sum;
    }
};

int main()
{
    int t,n;
    
    cin>>t; 
    while(t--) 
    {
        cin>>n; 
        int a[n];
        
        for(int i=0;i<n;i++) cin>>a[i]; 
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}