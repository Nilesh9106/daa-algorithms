#include <bits/stdc++.h>
using namespace std;

// nCk = n-1Ck-1 + n-1Ck
// n == k = 1
// k = 0 => 1
int main()
{
    int n = 4, k = 2;
    int dp[n + 1][k + 1] = {0};
    int i, j;

    for (i = 0; i <= n; i++){
        for (j = 0; j <= min(i, k); j++){
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; 
        }
    }
    for (int i = 1; i <= n; i++){
        cout<<"i= "<<i<<"\t";
        for (int j = 0; j < k + 1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
