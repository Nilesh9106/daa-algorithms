#include <bits/stdc++.h>

using namespace std;

int exch(char a,char b){
    return a==b ? 0 : 2;
}

int main()
{
    string str;
    string update_str;
    cin>>str>>update_str;
    vector<vector<int> > dp(str.length()+1,vector<int> (update_str.length()+1,0));
    int m=str.length()+1,n=update_str.length()+1;
    for(int i=0;i<m;i++){
        dp[i][0] = i;
    }

    for(int i=0;i<n;i++){
        dp[0][i] = i;
    }
    
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = min(dp[i-1][j-1] + exch(str[i-1],update_str[j-1]),min(dp[i][j-1]+1,dp[i-1][j]+1));
        }
    }
    
    for(int i =m-1,j=n-1;i>0 && j>0;){
        if(dp[i][j] == dp[i][j-1] +1 ){
            cout<<"insert "<<update_str[j-1]<<endl;
            j--;
        }
        else if(dp[i][j] == dp[i-1][j] +1 ){
            cout<<"delete "<<str[i-1]<<endl;
            i--;
        } else{
            if(str[i-1]!=update_str[j-1]){
                cout<<"exchange "<<str[j-1]<<" with "<<update_str[j-1]<<endl;
            }else{
                cout<<"already same"<<endl;
            }
            i--;
            j--;
        }
    }
    
    for(int i=0;i<m;i++){
        cout<<"i = "<<i<<"\t";
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}