#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dfs(ll node,ll coor,vector<vector<pair<ll,ll>>> &adj,vector<ll> &vis,vector<ll> &coord){
    vis[node] = 1;
    coord[node] = coor;
    for(auto it:adj[node]){
        if(vis[it.first]==0){
            dfs(it.first,coor+it.second,adj,vis,coord);
        }
    }
}

void solve() {  
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    vector<vector<ll>> conditions(m);
    for(ll i=0;i<m;i++){
        ll a,b,d;
        cin>>a>>b>>d;
        if(d<0) swap(a,b);
        d = abs(d);
        adj[a].push_back({b,d});
        adj[b].push_back({a,-d});
        conditions[i] = {a,b,d};
    }
    vector<ll> coord(n+1,-1);
    vector<ll> vis(n+1,0);
    for(ll i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,0,adj,vis,coord);
        }
    }
    for(ll i=0;i<m;i++){
        ll a = conditions[i][0];
        ll b = conditions[i][1];
        ll d = conditions[i][2];
        if((coord[b]-coord[a])!=d){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
