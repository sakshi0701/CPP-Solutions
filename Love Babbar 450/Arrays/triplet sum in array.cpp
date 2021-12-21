#include <stdio.h>

bool find3Numbers(int A[], int n, int X)
{
    int flag = 0;
    sort(A, A + n);
    for (int i = 0; i < n; i++)
    {
        int l = i + 1;
        int r = n - 1;

        while (l < r)
        {
            if (A[i] + A[l] + A[r] == X)
            {
                flag = 1;
                break;
            }

            else if (A[i] + A[l] + A[r] < X)
            {
                l++;
            }

            else
                r--;
        }

        if (flag == 1)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, X;
        scanf("%d", &n);
        scanf("%d", &X);
        int i, A[n];
        for (i = 0; i < n; i++)
            scanf("%d", &A[i]);
        printf("%d\n", find3Numbers(A, n, X));
    }
}