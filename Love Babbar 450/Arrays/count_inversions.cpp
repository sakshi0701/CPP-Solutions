#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int inversionCount(long long arr[], long long N)
    {
        long long int inv_count = 0;
        for (int i = 0; i < N - 1; i++)
            for (int j = i + 1; j < N; j++)
                if (arr[i] > arr[j])
                    inv_count++;

        return inv_count;
    }
};

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}