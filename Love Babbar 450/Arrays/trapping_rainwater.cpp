#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long trappingWater(int arr[], int n)
    {
        if (n <= 2)
        {
            return 0;
        }

        vector<int> l(n, 0);
        vector<int> r(n, 0);

        l[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            int mx = max(arr[i], l[i - 1]);
            l[i] = mx;
        }

        r[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            int mxr = max(arr[i], r[i + 1]);
            r[i] = mxr;
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (min(l[i], r[i]) - arr[i]);
        }
        return ans;
    }
};

int main()
{

    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;

        int a[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
}