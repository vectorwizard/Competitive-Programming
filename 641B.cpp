#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(ll ind,vector<ll> &s,ll n,vector<ll> &dp){
    if(ind==n+1){
        return 0;
    }
    if(dp[ind]!=-1) return dp[ind];
    ll ans = 1;
    for(ll i=2;i*ind<=n;i++){
        ll y = ind*i;
        if(y>1e9) break;
        if(s[y]>s[ind]) ans = max(ans,1+func(y,s,n,dp));
    }
    return dp[ind]=ans;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> s(n+1);
    vector<ll> dp(n+2,-1);
    for(ll i=1;i<=n;i++) cin>>s[i];
    ll ans = 1;
    for(ll i=1;i<=n;i++){
        ans = max(ans,func(i,s,n,dp));
    }
    cout<<max(ans,1LL)<<endl;
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
