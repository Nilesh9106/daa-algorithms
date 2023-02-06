#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cout<<"enter Number"<<endl;
    cin>>n;
    // algorithm
    int dp[n+1];  
    dp[0]=0; 
    dp[1]=1; 
    for (int  i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];  
        cout<<dp[i]<<" ";
    }

    cout<<"answer = "<<dp[n];
    return 0;
}