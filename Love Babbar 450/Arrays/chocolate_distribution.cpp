#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        long long mn = INT_MAX;
        sort(a.begin(), a.end());
        for (int i = 0; i <= n - m; i++)
        {
            // mn = min((a[m-1+i] - a[i]), mn);
            if ((a[i + m - 1] - a[i]) < mn)
            {
                mn = a[m - 1 + i] - a[i];
            }
        }
        return mn;
    }
};

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a;
        long long x;
        for (long long i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }

        long long m;
        cin >> m;
        Solution ob;
        cout << ob.findMinDiff(a, n, m) << endl;
    }
    return 0;
}