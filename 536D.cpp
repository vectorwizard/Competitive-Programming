#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> vis(n+1,0);
    vis[1] = 1;
    pq.push(1);
    while(!pq.empty()){
        int node = pq.top();
        pq.pop();
        cout<<node<<" ";
        for(auto it:adj[node]){
            if(vis[it]==1) continue;
            vis[it] = 1;
            pq.push(it);
        }
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
