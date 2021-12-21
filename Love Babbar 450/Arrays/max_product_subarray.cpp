#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxProduct(vector<int> arr, int n)
    {
        long long int mxp = arr[0], mnp = arr[0], ans = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < 0) swap(mxp, mnp);

            if (arr[i] > arr[i] * mxp) mxp = arr[i];
            else mxp = arr[i] * mxp;

            if (arr[i] < (arr[i] * mnp))  mnp = arr[i];
            else mnp = arr[i] * mnp;

            if (ans < mxp) ans = mxp;
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}