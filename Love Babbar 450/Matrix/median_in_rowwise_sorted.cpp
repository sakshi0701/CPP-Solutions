#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int median(vector<vector<int>> &matrix, int r, int c)
    {
        int lo = 1, hi = 2000;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;
            for (int i = 0; i < r; i++)
                cnt += lessThanNum(matrix[i], mid);
            if (cnt <= (r * c) / 2)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return lo;
    }

    int lessThanNum(vector<int> &arr, int val)
    {
        int n = arr.size();
        int lo = 0, hi = n - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] <= val)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return lo;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        cout << obj.median(matrix, r, c) << endl;
    }
    return 0;
}