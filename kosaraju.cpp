#include<bits/stdc++.h>
using namespace std;



void dfs1(int v, vector<int> adj[], stack<int>& s, vector<bool>& visited){
    visited[v] = true;
    for(int u : adj[v]){
        if(!visited[u]){
            dfs1(u, adj, s, visited);
        }
    }
    s.push(v);
}

void dfs2(int v, vector<int> adj[], vector<bool>& visited, vector<int>& component){
    visited[v] = true;
    component.push_back(v);
    for(int u : adj[v]){
        if(!visited[u]){
            dfs2(u, adj, visited, component);
        }
    }
}

vector<vector<int>> kosaraju(int V, vector<int> adj[]){
    vector<vector<int>> components;
    vector<bool> visited(V, false);
    stack<int> s;

    for(int v = 0; v < V; v++){
        if(!visited[v]){
            dfs1(v, adj, s, visited);
        }
    }

    vector<int> transpose[V];
    for(int v = 0; v < V; v++){
        for(int u : adj[v]){
            transpose[u].push_back(v);
        }
    }

    visited.assign(V, false);

    while(!s.empty()){
        int v = s.top();
        s.pop();
        if(!visited[v]){
            vector<int> component;
            dfs2(v, transpose, visited, component);
            components.push_back(component);
        }
    }

    return components;
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<vector<int>> components = kosaraju(V, adj);
    for(auto component : components){
        for(int v : component){
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
