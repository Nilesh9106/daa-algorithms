#include<bits/stdc++.h>

using namespace std;

class Hamiltonian {
    vector<int> sol;
    int v;
    int e;
    vector<vector<int> > graph;
    public:

    Hamiltonian(){
        cout<<"Enter Number of vertices and edges:"<<endl;
        cin>>v>>e;
        vector<vector<int> > g(v+1,vector<int>(v+1,0));
        vector<int> s(v+1,0);
        sol=s;
        sol[1]=1;
        cout<<"Enter edges:"<<endl;
        for (int i = 0; i < e; i++)
        {
            int u,v;
            cin>>u>>v;
            g[u][v]=1;
            g[v][u]=1;
        }
        graph=g;
    }

    void print(){
        for(int i=1; i<=v;i++)cout<<sol[i]<<" ";
        cout<<endl;
    }
    void nextValue(int k){
        while(true){
            sol[k] = (sol[k]+1)%(v+1);
            if(sol[k]==0)return;
            if(graph[sol[k-1]][sol[k]]){
                int i=1;
                for(i=1;i<k;i++){
                    if(sol[i]==sol[k]){
                        break;
                    }
                }
                if(i==k and (k<v or (k==v and graph[sol[v]][sol[1]]) ) ){
                    return;
                }
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
    Hamiltonian h;
    h.solve(2);
    return 0;
}