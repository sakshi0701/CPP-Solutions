#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution
{
public:
    int mah(vector<int> arr)
    {
        int n = arr.size();
        stack<int> s;
        s.push(-1);
        int area = arr[0];
        int i = 0;

        vector<int> left_smaller(n, -1), right_smaller(n, n);

        while (i < n)
        {
            while (!s.empty() && s.top() != -1 && arr[s.top()] > arr[i])
            {
                right_smaller[s.top()] = i;
                s.pop();
            }
            if (i > 0 && arr[i] == arr[i - 1])
            {
                // we use this condition to avoid the unnecessary loop to find the left_smaller.
                // since the previous element is same as current element, the left_smaller will always be the same for both.
                left_smaller[i] = left_smaller[i - 1];
            }
            else
            {
                // Element with the index stored on the top of the stack is always smaller than the current element.
                // Therefore the left_smaller[i] will always be s.top().
                left_smaller[i] = s.top();
            }
            s.push(i);
            i++;
        }

        for (int j = 0; j < n; j++)
        {
            // here we find area with every element as the smallest element in their range and compare it with the previous area.
            //  in this way we get our max Area form this.
            area = max(area, arr[j] * (right_smaller[j] - left_smaller[j] - 1));
        }
        return area;
    }

    int maxArea(int M[MAX][MAX], int n, int m)
    {
        // Your code
        vector<int> v;

        for (int i = 0; i < m; i++)
            v.push_back(M[0][i]);

        int mx = mah(v);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] == 0)
                {
                    v[j] = 0;
                }
                else
                {
                    v[j] = v[j] + M[i][j];
                }
            }
            mx = max(mx, mah(v));
        }
        return mx;
    }
};

int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}