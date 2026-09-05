#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> leaf;
ll func(ll node,ll par,vector<vector<ll>> &adj){
    if(adj[node].size()==1 && adj[node][0]==par){
        leaf[node] = 1;
        return 1;
    } 
    ll total = 0;
    for(auto it:adj[node]){
        if(it==par) continue;
        total+=func(it,node,adj);
    }
    leaf[node] = total;
    return total;
}

void solve() {
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll q;
    cin>>q;
    vector<pair<ll,ll>> queries(q);
    for(ll i=0;i<q;i++){
        ll x,y;
        cin>>x>>y;
        queries[i] = {x,y};
    }
    leaf.assign(n+1,0);
    func(1,-1,adj);
    for(ll i=0;i<q;i++){
        ll x = queries[i].first;
        ll y = queries[i].second;
        ll fir = leaf[x];
        ll sec = leaf[y];
        cout<<(fir*sec)<<endl;
    }
}
 
int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
