#include <bits/stdc++.h>

using namespace std;
int matrix[8][2]={{-1,0},{-1,1},{-1,-1},{1,-1},{1,0},{1,1},{0,1},{0,-1}};
int m=3,n=4;
class Neighborhood{
    public:
        vector<vector<int> > mat;
        
        Neighborhood(){
            vector<vector<int> > m(3,vector<int> (4,-1));
            mat=m;
        }
        bool dead(int i,int j){
            if((i==0 and j==0) or (i==2 and j==0) or (i==0 and j==3) or (i==2 and j==3)){
                return true;
            }
            return false;
        }
        int value(int i,int j){
            if(i<0 or j<0 or j>3 or i>2){
                return -1;
            }
            return mat[i][j];
        }
        bool isSafe(int i,int j,int k){
            if(mat[i][j] != -1){
                return false;
            }
            for(int l=0;l<8;l++){
                int t =value(i+matrix[l][0],j+matrix[l][1]);
                if(t == k-1){
                    return false;
                }
            }
            
            return true;
        }
        void solve(int k){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(!dead(i,j) and isSafe(i,j,k)){
                        mat[i][j]=k;
                        if(k==8){
                            print();
                            mat[i][j]=-1;
                            return;
                        }else{
                            solve(k+1);
                            mat[i][j]=-1;
                        }
                    }
                }
            }
        }
        void print(){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][j]==-1){
                        cout<<"  ";
                    }else{
                        cout<<mat[i][j]<<" ";
                    }
                }
                cout<<endl;
            }
            cout<<endl;
        }
};

int main(){
    Neighborhood n;
    n.solve(1);
    return 0;
}