#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll dfs(ll node,ll parent,vector<set<ll>> &adj,vector<ll> &vis){
    vis[node] = 1;
    ll ans = 0;
    for(auto it:adj[node]){
        if(it==parent) continue;
        else if(vis[it]==1){
            ans=1;
        } 
        else ans=ans|dfs(it,node,adj,vis);
    }
    return ans;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    vector<set<ll>> adj(n+1);
    for(ll i=1;i<=n;i++){
        adj[i].insert(a[i]);
        adj[a[i]].insert(i);
    }
    ll cycles = 0;
    ll lines = 0;
    vector<ll> vis(n+1,0);
    for(ll i=1;i<=n;i++){
        if(vis[i]!=1){
            if(dfs(i,-1,adj,vis)==1){
                cycles++;
            }
            else lines++;
        }
    }
    if(lines>0) cout<<(cycles+1)<<" ";
    else cout<<cycles<<" ";
    cout<<(cycles+lines)<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
