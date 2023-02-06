#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"length of array"<<endl;
    cin>>n;
    cout<<"enter values"<<endl;
    int arr[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int dp[n];
    dp[0]=arr[0];
    int max_value = arr[0];

    for (int  i = 1; i < n; i++)
    {
        dp[i] = max(dp[i-1] + arr[i],arr[i]);
        max_value = max(max_value,dp[i]);
    }

    cout<<max_value;
    
    return 0;
}