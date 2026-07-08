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
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<ll> dist(n+1,-1e18);
    dist[1] = 0;
    for(ll i=0;i<n-1;i++){
        for(ll node = 1;node<=n;node++){
            for(auto it:adj[node]){
                ll adj_node = it.first;
                ll wt = it.second;
                if(dist[node]!=-1e18 && dist[adj_node]<dist[node]+wt){
                    dist[adj_node]=dist[node]+wt;
                }
            }
        }
    }
    queue<ll> q;
    vector<ll> vis(n+1,0);
        for(ll node = 1;node<=n;node++){
            for(auto it:adj[node]){
                ll adj_node = it.first;
                ll wt = it.second;
                if(dist[node]!=-1e18 && dist[adj_node]<dist[node]+wt){
                    q.push(adj_node);
                    vis[adj_node] = 1;
                    dist[adj_node]=dist[node]+wt;
                }
            }
        }
    if(q.empty()){
        cout<<dist[n]<<endl;
        return;
    }
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        if(node==n){
            cout<<-1<<endl;
            return;
        }
        for(auto it:adj[node]){
            if(!vis[it.first]){
                q.push(it.first);
                vis[it.first] = 1;
            }
        }
    }
    cout<<dist[n]<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
