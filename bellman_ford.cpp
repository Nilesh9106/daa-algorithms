#include<bits/stdc++.h>
using namespace std;
bool relax(int u,int v,int w,vector<int> &d,vector<int> &p){
    if(d[v] > d[u]+w){
        d[v] = d[u]+w;
        p[v] = u;
        return true;
    }
    return false;
}

void bellman(){
    int v;
    cout<<"enter No of vertices"<<endl;
    cin>>v;
    int e;
    cout<<"enter Number of Edges"<<endl;
    cin>>e;
    vector<pair<pair<int,int>, int> > edges;
    vector<int> d(v,INT_MAX);
    vector<int> p(v,-1);
    d[0]=0;
    for(int i=0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(make_pair(make_pair(u,v),w));
    }
    for(int i=0; i<v-1;i++){
        for(int j=0;j<e;j++){
            pair<pair<int,int>, int> a = edges[j];
            relax(a.first.first , a.first.second,a.second,d,p);
        }
    }
    for(int i=0;i<e;i++){
        pair<pair<int,int>, int> a = edges[i];
        if(relax(a.first.first , a.first.second,a.second,d,p)){
            cout<<"Negative cycle detected "<<endl;
            break;
        }
    }
    cout<<"Parent\tdistance"<<endl;
    for(int i=0;i<v;i++){
        cout<<p[i]<<"\t"<<d[i]<<endl;
    }
}
int main(){
    bellman();
    return 0;
}