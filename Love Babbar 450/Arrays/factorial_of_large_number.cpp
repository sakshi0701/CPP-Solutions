#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int multiply(int x, vector<int> res, int res_size)
    {
        int carry = 0;

        // One by one multiply n with individual digits of res[]
        for (int i = 0; i < res_size; i++)
        {
            int prod = res[i] * x + carry;

            // Store last digit of 'prod' in res[]
            res[i] = prod % 10;

            // Put rest in carry
            carry = prod / 10;
        }

        // Put carry in res and increase result size
        while (carry)
        {
            res[res_size] = carry % 10;
            carry = carry / 10;
            res_size++;
        }
        return res_size;
    }

    vector<int> factorial(int N)
    {
        vector<int> ans;
        ans[0] = 1;
        int res_size = 1;

        // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
        for (int x = 2; x <= N; x++)
        {
            res_size = multiply(x, ans, res_size);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}