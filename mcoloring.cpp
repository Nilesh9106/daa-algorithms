#include<bits/stdc++.h>

using namespace std;

class Mcolor{
    vector<int> sol;
    int m;
    int v;
    int e;
    vector<vector<int> > graph;
    public:
    Mcolor(){
        cout<<"Enter Number of vertices and edges:"<<endl;
        cin>>v>>e;
        vector<vector<int> > g(v+1,vector<int>(v+1,0));
        vector<int> s(v+1,0);
        sol=s;
        cout<<"Enter edges:"<<endl;
        for (int i = 0; i < e; i++)
        {
            int u,v;
            cin>>u>>v;
            g[u][v]=1;
            g[v][u]=1;
        }
        graph=g;
        cout<<"Enter Number of Colors :"<<endl;
        cin>>m;
    }

    void print(){
        for(int i=1; i<=v;i++)cout<<sol[i]<<" ";
        cout<<endl;
    }
    void nextValue(int k){
        while(true){
            sol[k] = (sol[k]+1)%(m+1);
            if(sol[k]==0){
                return;
            }
            int i=1;
            for(i=1;i<=v;i++){
                if(sol[i]==sol[k] and graph[k][i]){
                    break;
                }
            }
            if(i==v+1){
                return;
            }
        }
    }

    void solve(int k){
        while (true){
            nextValue(k);
            if(sol[k]==0)return;
            k==v?print():solve(k+1);
        }  
    }
};

int main(){
    Mcolor m;
    m.solve(1);
    return 0;
}