#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
ll ans = 0;
void dfs(ll node,ll par,vector<vector<ll>> &adj,ll k,vector<vector<ll>> &dp){
    dp[node][0] = 1;
    for(auto it:adj[node]){
        if(it==par) continue;
        dfs(it,node,adj,k,dp);
        for(ll i=1;i<=k;i++){
            ans+=(dp[node][k-i] * dp[it][i-1]);
        }
        for(ll i=1;i<=k;i++){
            dp[node][i] += dp[it][i-1];
        }
    }
} 
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));
    dfs(1,-1,adj,k,dp);
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
