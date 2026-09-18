#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll dfs(ll node,ll par,ll op,vector<vector<ll>> &adj,vector<pair<ll,ll>> &vec,vector<vector<ll>> &dp){
    ll ans = 0;
    if(dp[node][op]!=-1) return dp[node][op];
    if(op==0){
        for(auto it:adj[node]){
            if(it==par) continue;
            ans+=max(abs(vec[node].first-vec[it].first)+dfs(it,node,0,adj,vec,dp),abs(vec[node].first-vec[it].second)+dfs(it,node,1,adj,vec,dp));
        }
    }
    else{
        for(auto it:adj[node]){
            if(it==par) continue;
            ans+=max(abs(vec[node].second-vec[it].first)+dfs(it,node,0,adj,vec,dp),abs(vec[node].second-vec[it].second)+dfs(it,node,1,adj,vec,dp));
        }
    }
    return dp[node][op] = ans;
}

void solve() {
    ll n;
    cin>>n;
    vector<pair<ll,ll>> vec(n+1);
    for(ll i=1;i<=n;i++){
        ll l,r;
        cin>>l>>r;
        vec[i] = {l,r};
    }
    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<ll>> dp(n+1,vector<ll>(2,-1));
    ll ans = max(dfs(1,-1,0,adj,vec,dp),dfs(1,-1,1,adj,vec,dp));   //0->l , 1->r
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}