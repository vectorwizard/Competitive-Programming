#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<int> dp;
void dfs(int par,int node,vector<vector<int>> &adj,map<pair<int,int>,int> &mpp){
    for(auto it:adj[node]){
        if(it==par) continue;
        if(mpp[{node,it}]<mpp[{par,node}]) dp[it] = dp[node] + 1;
        else dp[it] = dp[node];
        dfs(node,it,adj,mpp);
    }
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    map<pair<int,int>,int> mpp;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mpp[{u,v}] = i;
        mpp[{v,u}] = i;
    }
    dp.assign(n,0);
    dp[0] = 1;
    mpp[{-1,0}] = -1;
    dfs(-1,0,adj,mpp);
    int ans = *max_element(dp.begin(),dp.end());
    cout<<ans<<endl;
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
