#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int ans = 0;
int dfs(int node,int par,vector<vector<int>> &adj){
    int sz = 1;
    for(auto it:adj[node]){
        if(it!=par){
            sz+=dfs(it,node,adj);
        }
    }
    if(sz%2==0 && par!=-1) ans++;
    return sz;
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n%2==1){
        cout<<-1<<endl;
        return;
    }
    dfs(1,-1,adj);
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
