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
    bool poss = false;
    vector<int> vis(n+1,0);
    vector<int> par(n+1,-1);
    queue<pair<int,int>> q;
    q.push({1,1});
    vis[1] = 1;
    int ans = -1;
    while(!q.empty()){
        auto it = q.front();
        int node = it.first;
        int step = it.second;
        q.pop();
        if(node==n){
            poss = true;
            ans = step;
            break;
        }
        for(auto adj_node: adj[node]){
            if(vis[adj_node]==0){
                q.push({adj_node,step+1});
                vis[adj_node] = 1;
                par[adj_node] = node;
            }
        }
    }
    if(poss==false){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<ans<<endl;
    int curr = n;
    vector<int> anss;
    while(curr!=-1){
        anss.push_back(curr);
        curr = par[curr];
    }
    reverse(anss.begin(),anss.end());
    for(int i=0;i<anss.size();i++){
        cout<<anss[i]<<" ";
    }
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
