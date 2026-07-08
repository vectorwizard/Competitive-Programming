#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    vector<ll> degree(n+1,0);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    if(n<=2){
        cout<<0<<endl;
        return;
    }
    vector<ll> leafnodes;
    for(ll i=1;i<=n;i++){
        if(degree[i]==1) leafnodes.push_back(i);
    }
    unordered_map<ll,ll> mpp;
    for(auto it:leafnodes){
        for(auto adj_node:adj[it]){
            mpp[adj_node]++;
        }
    }
    ll maxi = -1;
    ll node = -1;
    for(auto it: mpp){
        if(it.second>maxi){
            maxi = it.second;
            node = it.first;
        }
    }
    ll cnt = 0;
    for(auto it:adj[node]){
        if(degree[it]==1) cnt++;
    }
    cout<<leafnodes.size()-cnt<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
