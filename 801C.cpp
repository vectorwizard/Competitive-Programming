#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> func(ll i,ll j,vector<vector<ll>> &a,vector<vector<vector<ll>>> &dp,vector<vector<ll>> &vis){
    ll n = a.size();
    ll m = a[0].size();
    if(i==n-1 && j==m-1) return {a[i][j],a[i][j]};
    ll maxi = -1e9;
    ll mini = 1e9;
    if(vis[i][j]==1) return dp[i][j];
    vis[i][j] = 1;
    if(i<n-1){
        auto x = func(i+1,j,a,dp,vis);
        maxi = max(maxi,x[1]);
        mini = min(mini,x[0]);
    }
    if(j<m-1){
        auto x = func(i,j+1,a,dp,vis);
        maxi = max(maxi,x[1]);
        mini = min(mini,x[0]);
    }
    return dp[i][j] = {a[i][j]+mini,a[i][j]+maxi};
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> a(n,vector<ll>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    if((n+m)%2==0){
        cout<<"NO"<<endl;
        return;
    }
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(m,vector<ll>(2)));
    vector<vector<ll>> vis(n,vector<ll>(m,0));
    vector<ll> ans = func(0,0,a,dp,vis);
    if(ans[0]<=0 && ans[1]>=0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
