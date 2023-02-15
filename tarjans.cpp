#include<bits/stdc++.h>
using namespace std;
int num=1;
void art(int u,int v,vector<int> &d,vector<int> &low, vector<vector<int> > &adj){
    d[u]= num;
    low[u]=num;
    num++;

    for(int w:adj[u]){
        if(d[w] == 0){
            art(w,u,d,low,adj);
            low[u] = min(low[u],low[w]);
        }
        else if(w != v){
            low[u]=min(low[u],d[w]);
        }
    }
}

int main(){
    int v,e;
    cout<<"enter no of Vertices : "<<endl;
    cin>>v;
    cout<<"enter no of Edges : "<<endl;
    cin>>e;
    cout<<"enter Edges : "<<endl;
    vector<pair<int,int> > edges;
    vector<vector<int> > adj(v);
    for(int i=0; i<e; i++){
        int u,v1;
        cin>>u>>v1;
        edges.push_back(make_pair(u,v1));
        adj[u].push_back(v1);
        adj[v1].push_back(u);
    }
    vector<int> d(v,0);
    vector<int> low(v,0);
    art(0,-1,d,low,adj);
    for(int i=0;i<e;i++){

        if(d[edges[i].first] <= low[edges[i].first]){
            cout<<edges[i].first<<" is A.P"<<endl;
        }
    }
    return 0;
}