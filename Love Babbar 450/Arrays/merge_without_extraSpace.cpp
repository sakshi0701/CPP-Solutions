#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // invariant: `X[]` and `Y[]` are sorted at any point
    void merge(int X[], int Y[], int m, int n)
    {
        int i = m - 1, j = 0;
        while (i >= 0 && j < n && X[i] > Y[j])
        {
            int temp = X[i];
            X[i] = Y[j];
            Y[j] = temp;
            i--;
            j++;
        }
        sort(X, X + m);
        sort(Y, Y + n);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}