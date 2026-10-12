#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(ll n,ll a,ll b,ll c,vector<ll> &dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    ll ans = -1e9;
    if(n>=a) ans = max(ans,1+func(n-a,a,b,c,dp));
    if(n>=b) ans = max(ans,1+func(n-b,a,b,c,dp));
    if(n>=c) ans = max(ans,1+func(n-c,a,b,c,dp));
    return dp[n]=ans;
}

void solve() {
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    vector<ll> dp(n+1,-1);
    ll ans = func(n,a,b,c,dp);
    cout<<ans<<endl;
}   

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
