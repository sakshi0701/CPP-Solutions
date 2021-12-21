// C++ program to find minimum swaps required to club all elements less than or equals to k together
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int minSwap(int arr[], int n, int k)
    {
        int fav = 0, nonFav = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k) fav++;
        }

        // window size ( it is the number of elements less than k )
        for (int j = 0; j < fav; j++)
        {
            if (arr[j] > k) nonFav++;
        }

        int l = 0, r = fav - 1, result = INT_MAX;

        while (r < n)
        {
            result = min(result, nonFav);
            r++;
            if (r < n && arr[r] > k)
                nonFav++;
            if (l < n && arr[l] > k)
                nonFav--;
            l++;
        }

        return (result == INT_MAX) ? 0 : result;
    }
};

int main()
{

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
    return 0;
}