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
    vector<vector<ll>> dist(n + 1, vector<ll>(2, LLONG_MAX));
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
    pq.push({0,1,0}); //dist,node,used/notused
    dist[1][0] = 0;
    while(!pq.empty()){
        auto it = pq.top();
        ll distance = it[0];
        ll node = it[1];
        ll fl = it[2];
        pq.pop();
        if(distance>dist[node][fl]) continue;
        for(auto it1:adj[node]){
            ll adj_node = it1.first;
            ll wt = it1.second;
            if(dist[adj_node][fl]>distance+wt){
                dist[adj_node][fl]=distance+wt;
                pq.push({dist[adj_node][fl],adj_node,fl});
            }
            if(fl==0){
                if(dist[adj_node][1]>distance+(wt/2)){
                    dist[adj_node][1]=distance+(wt/2);
                    pq.push({dist[adj_node][1],adj_node,1});
                }
            }
        }
    }
    cout<<dist[n][1]<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
