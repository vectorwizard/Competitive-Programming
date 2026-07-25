#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<pair<ll,ll>> vec; // {children , node}

ll dfs(ll node,ll parent,vector<vector<ll>> &adj,ll depth){
    ll child = 0;
    for(auto it: adj[node]){
        if(it==parent) continue;
        child += dfs(it,node,adj,depth+1);
    }
    vec.push_back({depth-child,node});
    return child+1;
}


void solve() {  
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1,adj,0);
    sort(vec.rbegin(),vec.rend());
    ll ans = 0;
    for(ll i=0;i<k;i++){
        ans+=vec[i].first;
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
