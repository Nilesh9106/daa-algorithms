#include <iostream>
#include <string>
#include <vector>
using namespace std;

int LCS(const string &X, const string &Y)
{
  int m = X.length();
  int n = Y.length();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (X[i - 1] == Y[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[m][n];
}

int main()
{
  string X = "ABRACADABRA";
  string Y = "AKKADBAKKAD";
  cout << "The length of LCS is: " << LCS(X, Y) << endl;
  return 0;
}
