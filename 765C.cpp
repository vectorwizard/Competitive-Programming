#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(ll ind,ll k,vector<ll> &d,vector<ll> &a,ll l,vector<vector<ll>> &dp){
    ll n = d.size();
    if(ind==n){
        return 0;
    }
    ll mini = 1e18;
    if(dp[ind][k]!=-1) return dp[ind][k];
    for(ll i=ind+1;i<=n;i++){
        if(i>(ind+k+1)) break;
        if(i==n){
            ll cost = a[ind] * (l-d[ind]);
            mini = min(mini,cost+func(n,k,d,a,l,dp));
        }
        else{
            ll cost = a[ind] * (d[i]-d[ind]);
            ll rem = (i-ind-1);
            mini = min(mini,cost + func(i,k-rem,d,a,l,dp));
        }
    }
    return dp[ind][k] = mini;
}

void solve() {
    ll n,l,k;
    cin>>n>>l>>k;
    vector<ll> d(n);
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>d[i];
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
    ll ans = func(0,k,d,a,l,dp);
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}