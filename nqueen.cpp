#include <bits/stdc++.h>

using namespace std;
class Queen{
    public:
    vector<int> x;
    Queen(int n){
        vector<int> x1(n+1,0);
        x=x1;
    }

    void solve(int k){
        for(int i=1;i<x.size();i++){
            if(place(k,i)){
                x[k]=i;
                if(k==x.size()-1){
                    print();
                }else{
                    solve(k+1);
                }
            }
        }
    }
    void print(){
        for(int i=1;i<x.size();i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    bool place(int k,int i){
        for(int j=1;j<k;j++){
            if(x[j]==i or abs(j-k) == abs(x[j]-i)){
                return false;
            }
        }
        return true;
    }
};
int main(){
    Queen q(4);
    q.solve(1);
    return 0;
}