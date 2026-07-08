#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int farthest = 0;
int farthest_node = 1;
int ans;
void dfs(int node,int dist,vector<vector<int>> &adj,vector<int> &vis){
    if(dist>farthest){
        farthest = dist;
        farthest_node = node;
    }
    vis[node] = 1;
    for(auto it:adj[node]){
        if(vis[it]==0) dfs(it,dist+1,adj,vis);
    }
}
void dfs1(int node,int dist,vector<vector<int>> &adj,vector<int> &vis){
    if(dist>ans){
        ans = dist;
    }
    vis[node] = 1;
    for(auto it:adj[node]){
        if(vis[it]==0) dfs1(it,dist+1,adj,vis);
    }
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n+1,0);
    vis[1] = 1;
    dfs(1,0,adj,vis);
    ans = farthest;
    vis.assign(n+1,0);
    vis[farthest_node]=1;
    dfs1(farthest_node,0,adj,vis);
    cout<<ans<<endl;
}   

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
