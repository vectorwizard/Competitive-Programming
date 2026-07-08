#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const ll mod = 1e9 + 7;
ll func(ll ind,ll prev,ll n,ll k,vector<vector<ll>> &dp){
    if(ind==k) return 1;
    ll ans = 0;
    if(dp[ind][prev]!=-1) return dp[ind][prev];
    for(ll j = 1;j*prev<=n;j++){
        ll num = j*prev;
        ans=(ans+func(ind+1,num,n,k,dp))%mod;
    }
    return dp[ind][prev]=ans%mod;
}
void solve() {
    ll n,k;
    cin>>n>>k;
    ll ans = 0;
    vector<vector<ll>> dp(k+1,vector<ll>(n+1,-1));
    for(ll i=1;i<=n;i++){
        ans=(ans+func(1,i,n,k,dp))%mod;
    }
    cout<<(ans%mod)<<endl;
}   

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
