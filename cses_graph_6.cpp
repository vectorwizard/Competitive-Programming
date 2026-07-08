#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<int> vis;
vector<int> par;
int start_node=-1;
int end_node=-1;
bool dfs(int node,int parent,vector<vector<int>> &adj){
    vis[node] = 1;
    for(auto adj_node: adj[node]){
        if(adj_node==parent) continue;
        if(vis[adj_node]) {
            start_node = adj_node;
            end_node = node;
            return true;
        }
        par[adj_node] = node;
        if(dfs(adj_node,node,adj)) return true;
    }
    return false;
}
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis.resize(n+1,0);
    par.resize(n+1,-1);
    vector<int> anss;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(dfs(i,-1,adj)){
            int curr = end_node;
            anss.push_back(start_node);
            while(curr!=start_node){
                anss.push_back(curr);
                curr = par[curr];
            }
            anss.push_back(start_node);
            cout<<anss.size()<<endl;
            for(int i=0;i<anss.size();i++){
                cout<<anss[i]<<" ";
            }
            cout<<endl;
            return;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
