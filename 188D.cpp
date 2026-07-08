#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<int> ta;
vector<int> tb;
vector<int> color;
vector<int> vis;
bool dfs(int node,int color_code,vector<vector<int>> &adj){
    vis[node] = 1;
    color[node] = color_code;
    if(color_code==1) ta.push_back(node);
    else tb.push_back(node);
    bool fl = true;
    for(auto it:adj[node]){
        if(color[it]==color_code) fl = false;
        if(vis[it]) continue;
        if(color_code==1){
            if(dfs(it,2,adj)==false) fl = false;
        }
        else{
            if(dfs(it,1,adj)==false) fl = false;
        } 
    }
    return fl;
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
    vis.assign(n+1,0);
    int ans = 0;
    color.assign(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        ta.clear();
        tb.clear();
        if(dfs(i,1,adj)){
            int maxi = max(ta.size(),tb.size());
            ans+=maxi;
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}