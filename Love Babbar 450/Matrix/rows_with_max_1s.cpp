#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int max_index = 0;
        int j = m - 1;

        for (int i = 0; i < n; i++)
        {
            // Move left until a 0 is found
            bool flag = false; // to check whether a row has more 1's than previous
            while (j >= 0 && arr[i][j] == 1)
            {
                j--;         // check if there id a 1 in this row before the index of prev alse
                flag = true; // present row has more 1's than previous
            }
            // if the present row has more 1's than previous
            if (flag)
            {
                max_index = i; // Update max_row_index
            }
        }

        if (max_index == 0 && arr[0][m - 1] == 0)
            return -1;

        return max_index;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}