#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLongestConseqSubseq(int arr[], int N)
    {
        int ans = 0, count = 0;

        sort(arr, arr + N);

        vector<int> v;
        v.push_back(arr[0]);

        // insert repeated elements only once in the vector
        for (int i = 1; i < N; i++)
        {
            if (arr[i] != arr[i - 1]) v.push_back(arr[i]);
        }

        // find the maximum length by traversing the array
        for (int i = 0; i < v.size(); i++)
        {
            // Check if the current element is equal to previous element +1
            if (i > 0 && v[i] == v[i - 1] + 1) count++;
            
            // reset the count
            else count = 1;

            // update the maximum
            ans = max(ans, count);
        }
        return ans;
    }
};

int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
}