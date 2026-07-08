#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
void dfs(ll node,ll col,vector<vector<ll>> &adj,vector<ll> &vis,vector<ll> &color){
    vis[node] = 1;
    color[node] = col;
    for(auto it:adj[node]){
        if(vis[it]==0){
            dfs(it,!col,adj,vis,color);
        }
    }
}
void solve() {
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> color(n,-1);
    vector<ll> vis(n,0);
    dfs(0,0,adj,vis,color);
    ll x=0,y=0;
    for(ll i=0;i<n;i++){
        if(color[i]==0) x++;
        else y++;
    }
    cout<<((x*y)-(n-1))<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
