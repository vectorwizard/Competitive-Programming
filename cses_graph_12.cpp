#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> edges;
    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }
    vector<ll> dist(n+1,0);
    vector<ll> par(n+1,-1);
    dist[1] = 0;
    for(ll i=0;i<n-1;i++){
        for(auto it:edges){
            ll u = it[0];
            ll v = it[1];
            ll w = it[2];
            if(dist[u]+w<dist[v]){
                dist[v] = dist[u] + w;
                par[v] = u;
            }
        }
    }
    ll node = -1;
    for(auto it:edges){
        ll u = it[0];
        ll v = it[1];
        ll w = it[2];
        if(dist[u]+w<dist[v]){
            dist[v] = dist[u] + w;
            par[v] = u;
            node = v;
        }
    }
    if(node==-1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    vector<ll> cycle;
    for(ll i=0;i<n;i++){
        node = par[node];
    }
    ll curr = node;
    while(true){
        cycle.push_back(curr);
        if(cycle.size()>1 && curr==node) break;
        curr = par[curr];
    }
    reverse(cycle.begin(),cycle.end());
    for(auto it:cycle) cout<<it<<" ";
    cout<<endl;
}  

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
