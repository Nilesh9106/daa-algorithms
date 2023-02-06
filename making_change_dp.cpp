#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n ;
   cout<<"enter number of coins"<<endl;
   cin>>n;
   vector<int> coins(n+1);
   cout<<"Enter Amount of Coins one by one"<<endl;
   for (int i = 1; i <= n; i++){
       cin >> coins[i];
   }
   cout << "Enter Amount : " << endl;
   int c;
   cin >> c;


   int arr[n+1][c+1] ;
   for(int i=0;i<=n;i++){arr[i][0] = 0;}
   for(int i=1;i<=n;i++){
       for(int j=1;j<=c;j++){
           if(j<coins[i]){
               if(i == 1){
                   arr[i][j] = -1;
               }else{
                   arr[i][j] = arr[i-1][j];
               }
           }else{
               if (i == 1)
               {
                   arr[i][j] = 1+arr[i][j-coins[i]];
               }else{
                   arr[i][j] = min(arr[i-1][j],1+arr[i][j-coins[i]]);
               }
              
           }
       }
   }
   cout<<"              ";
    for (int i = 0; i <= c; i++)
    {
        cout<<"j="<<i<<"\t";
    }
    cout<<endl;
   for(int i=1;i<=n;i++){
       cout<<"coin[i] = "<<coins[i]<<" : ";
       for(int j=0;j<=c;j++){
           cout<<arr[i][j]<<" \t";
       }
       cout<<endl;
   }
   cout<< "\nMinimum coins required for "<<c<<" : "<<arr[n][c]<<endl;
   return 0;
}
