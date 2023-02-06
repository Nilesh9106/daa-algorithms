#include <bits/stdc++.h>
using namespace std;
void print_optimal_param(vector<vector<int>> &k, int i, int j)
{
    if (i == j)
    {
        cout << "A" << i << " ";
    }
    else
    {
        cout << "(";
        print_optimal_param(k, i, k[i][j]);
        print_optimal_param(k, k[i][j] + 1, j);
        cout << ")";
    }
}
int main()
{
    int n;
    cout << "enter no of matrix" << endl;
    cin >> n;
    int p[n + 1];
    cout << "Enter Value of Pi : " << endl;

    for (int i = 0; i <= n; i++){
        cin >> p[i];
    }
    int arr[n + 1][n + 1];

    vector<vector<int>> cut(n + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            arr[i][j] = 0;
        }
    }
    for (int l = 2; l <= n; l++){

        for (int i = 1; i <= (n - l + 1); i++){
            int j = i + l - 1;
            arr[i][j] = INT_MAX;

            for (int k = i; k < j; k++){

                int q = arr[i][k] + arr[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < arr[i][j]){
                    arr[i][j] = q;
                    cut[i][j] = k;
                }

            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j > 0; j--)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "---------------------------------\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j > 0; j--)
        {
            cout << cut[i][j] << "\t";
        }
        cout << endl;
    }
    print_optimal_param(cut, 1, n);
    cout << endl;
    return 0;
}
