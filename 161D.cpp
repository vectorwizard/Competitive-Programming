#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<ll> depth;
vector<ll> parent;
ll stuck;
ll source;
void dfs(ll node,ll dep,vector<ll> &vis,vector<vector<ll>> &adj){
    vis[node] = true;
    depth[node] = dep;
    bool fl = false;
    for(auto it:adj[node]){
        if(vis[it]==0){
            parent[it] = node;
            dfs(it,dep+1,vis,adj);
            fl = true;
        } 
    }
    if(!fl) stuck = node;
    return;
}

void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>> adj(n+1);
    parent.assign(n+1,-1);
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    depth.assign(n+1,0);
    vector<ll> vis(n+1,0);
    dfs(1,0,vis,adj);
    ll mini = 1e9;
    ll node = -1;
    for(auto it:adj[stuck]){
        if(depth[it]<mini){
            mini = depth[it];
            node = it;
        }
    }
    source = node;
    ll temp = stuck;
    vector<ll> ans;
    while(temp!=source){
        ans.push_back(temp);
        temp = parent[temp];
    }
    ans.push_back(source);
    cout<<ans.size()<<endl;
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
