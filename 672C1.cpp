#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(ll ind,ll op,vector<ll> &a,vector<vector<ll>> &dp){
    ll n = a.size();
    if(ind==n) return 0;
    if(dp[ind][op]!=-1) return dp[ind][op];
    ll take = 0;
    ll nottake = func(ind+1,op,a,dp);
    if(op==0) take = a[ind] + func(ind+1,1,a,dp);
    else take = -a[ind] + func(ind+1,0,a,dp);
    return dp[ind][op]=max(take,nottake);
}

void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<vector<ll>> dp(n+1,vector<ll>(2,-1));
    ll ans = func(0,0,a,dp);
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}