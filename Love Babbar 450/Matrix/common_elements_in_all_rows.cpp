#include <bits/stdc++.h>
using namespace std;

#define M 4
#define N 5

void printCommonElements(int mat[M][N])
{
    unordered_map<int, int> mp;

    // initialize 1st row elements with value 1
    for (int j = 0; j < N; j++)
        mp[mat[0][j]] = 1;

    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // If element is present in the map and is not duplicated in current row.
            if (mp[mat[i][j]] == i)
            {
                // we increment count of the element in map by 1
                mp[mat[i][j]] = i + 1;

                // If this is last row we print the element if it has appeared m-1 times before
                if (i == M - 1 && mp[mat[i][j]] == M)
                    cout << mat[i][j] << " ";
            }
        }
    }
}

int main()
{
    int mat[M][N] =
        {
            {1, 2, 1, 4, 8},
            {3, 7, 8, 5, 1},
            {8, 7, 7, 3, 1},
            {8, 1, 2, 7, 9},
        };

    printCommonElements(mat);

    return 0;
}