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
    vector<ll> w(n);
    for(ll i=0;i<n;i++) cin>>w[i];
    vector<vector<ll>> adj(n);
    vector<ll> nodes;
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(ll i=0;i<n;i++){
        if(adj[i].size()>1){
            for(int j=0;j<(adj[i].size()-1);j++){
                nodes.push_back(w[i]);
            }
        }
    }
    sort(nodes.rbegin(),nodes.rend());
    ll total = accumulate(w.begin(),w.end(),0LL);
    vector<ll> prefix(nodes.size(),0);
    if(nodes.size()>0) prefix[0] = nodes[0];
    for(ll i=1;i<nodes.size();i++){
        prefix[i] = prefix[i-1] + nodes[i];
    }
    cout<<total<<" ";
    ll j = 0;
    for(ll i=0;i<n-2;i++){
        if(j==prefix.size()) cout<<total+prefix[j-1]<<" ";
        else {
            cout<<total+prefix[j]<<" ";
            j++;
        }
    }
    cout<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}