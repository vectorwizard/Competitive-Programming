#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(ll ind,ll prev,vector<ll> &a,vector<ll> &b,vector<vector<ll>> &dp){
    ll n = a.size();
    if(ind==n) return 0;
    ll ans = 0;
    if(dp[ind][prev]!=-1) return dp[ind][prev];
    if(prev==0){
        ans = max(ans,b[ind]+func(ind+1,1,a,b,dp));
    }
    else ans = max(ans,a[ind]+func(ind+1,0,a,b,dp));
    ans = max(ans,func(ind+1,prev,a,b,dp));
    ans = max(ans,func(ind+1,prev,a,b,dp));
    return dp[ind][prev]=ans;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    ll maxi = 0;
    vector<vector<ll>> dp(n+1,vector<ll>(2,-1));
    maxi = max(maxi,func(0,0,a,b,dp));
    maxi = max(maxi,func(0,1,a,b,dp));
    cout<<maxi<<endl;
}   

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
