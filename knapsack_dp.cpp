#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> p(n+1),w(n+1);
    cout<<"Enter Profit and Weight One by one"<<endl;
    for(int i=1;i<=n;i++){
        cin>>p[i]>>w[i];
    }
    int c;
    cin>>c;
    int arr[n+1][c+1] ;
    for(int i=0;i<=n;i++){arr[i][0] = 0;}
    for(int i=0;i<=c;i++){arr[0][i] = 0;}

    for(int i=1;i<=n;i++){
        for(int j=1;j<=c;j++){
            if(j<w[i]){
                arr[i][j] = arr[i-1][j];
            }else{
                arr[i][j] = max(arr[i-1][j],p[i]+arr[i-1][j-w[i]]); 
            }
        }
    }
    cout<<"i =   : ";
    for (int i = 0; i <= c; i++){
        cout<<"j="<<i<<"\t";
    }
    cout<<endl;
    for(int i=0;i<=n;i++){
        cout<<"i = "<<i<<" : ";
        for(int j=0;j<=c;j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Answer : "<<arr[n][c]<<endl;
    int i=n,j=c;
    int x[n+1];
     while (i>0 and j>0)
    {
        if(arr[i][j] != arr[i-1][j]){
            x[i] = 1;
            j-=w[i];
            i--;
        }else{
            x[i]=0;
            i--;
        }
    }
    for(int i=1;i<=n;i++){
        if (x[i]==1){
            cout<<p[i]<<" : "<<w[i]<<endl;
        }
        
    }
    cout<<endl;

    return 0;
}
