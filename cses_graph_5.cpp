#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<int> color;
bool dfs(int node,int color_code,vector<int> &vis,vector<vector<int>> &adj){
    vis[node] = 1;
    color[node] = color_code;
    for(auto adj_node:adj[node]){
        if(color[adj_node]==color_code) return false;
        if(vis[adj_node]==0){
            if(dfs(adj_node,!color_code,vis,adj)==false) return false;
        }
    }
    return true;
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
    color.resize(n+1,-1);
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            if(dfs(i,1,vis,adj)==false){
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(color[i]==1) cout<<1<<" ";
        else cout<<2<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
