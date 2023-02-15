#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int e1, e2, x1, x2;
    cout << "enter e1,e2.x1,x2 : " << endl;
    cin >> e1 >> e2 >> x1 >> x2;
    cout << "enter node costs : " << endl;
    vector<vector<int>> A(2, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        cin >> A[0][i] >> A[1][i];
    }
    cout << "enter transpose cost : " << endl;
    vector<vector<int>> T(2, vector<int>(n + 1));
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> T[0][i] >> T[1][i];
    }
    vector<vector<int>> dp(2, vector<int>(n + 1));
    dp[0][1] = e1 + A[0][1];
    dp[1][1] = e2 + A[1][1];

    for (int i = 2; i <= n; i++)
    {
        if (dp[0][i - 1] + A[0][i] < dp[1][i - 1] + A[0][i] + T[1][i - 1])
        {
            dp[0][i] = dp[0][i - 1] + A[0][i];
        }
        else
        {
            dp[0][i] = dp[1][i - 1] + A[0][i] + T[1][i - 1];
        }
        if (dp[1][i - 1] + A[1][i] < dp[0][i - 1] + A[1][i] + T[0][i - 1])
        {
            dp[1][i] = dp[1][i - 1] + A[1][i];
        }
        else
        {
            dp[1][i] = dp[0][i - 1] + A[1][i] + T[0][i - 1];
        }
    }
    int final, final_l;
    if (dp[1][n] + x1 < dp[2][n] + x2)
    {
        final = dp[1][n] + x1;
        final_l = 1;
    }
    else
    {
        final = dp[2][n] + x2;      // 5    10  .12.  12    .13.  23
        final_l = 2;                // 5    9   .10.  14    .13.  12
    }

    for (int j = 0; j < 2; j++)
    {
        for (int i = 1; i < n + 1; i++)
        {
            cout << dp[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
