#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<pair<ll,ll>> post;
vector<ll> parent;
void dfs(ll node,ll par,ll depth,vector<vector<ll>> &adj){
    parent[node] = par;
    for(auto it:adj[node]){
        if(it==par) continue;
        dfs(it,node,depth+1,adj);
    }
    post.push_back({node,depth});
}

void solve() {
    ll n,k;
    cin>>n;
    post.clear();
    parent.assign(n+1,-1);
    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1,0,adj);
    vector<ll> covered(n+1,0);
    ll ans = 0;
    for(ll i=0;i<post.size();i++){
        auto it = post[i];
        ll node = it.first;
        ll depth = it.second;
        if(depth>2 && covered[node]==0){
            ans++;
            covered[parent[node]] = 1;
            for(auto it:adj[parent[node]]){
                covered[it] = 1;
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}