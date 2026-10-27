
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainMultiplication(vector<int> &p, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // len is the length of the matrix chain
    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            // Try every possible split point
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);

    cout << "Enter dimensions array ("
         << n + 1 << " values):\n";

    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    cout << "Minimum number of scalar multiplications: "
         << matrixChainMultiplication(p, n + 1)
         << endl;

    return 0;
}
