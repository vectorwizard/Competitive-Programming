#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const ll mod = 1e9 + 7;
ll dp[1002][1002][2];
ll func(ll ind,ll k,ll dir,ll n){
    if(ind==n+1 || ind==0) return 1;
    ll ans = 0;
    if(dp[ind][k][dir]!=-1) return dp[ind][k][dir];
    if(dir==1){
        ans = (ans+func(ind+1,k,1,n))%mod;
        if(k>1) ans = (ans+func(ind-1,k-1,0,n))%mod;
    }
    else{
        ans = (ans+func(ind-1,k,0,n))%mod;
        if(k>1) ans = (ans+func(ind+1,k-1,1,n))%mod;
    }
    return dp[ind][k][dir]=ans%mod;
}
void solve() {
    ll n,k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    ll ans = func(1,k,1,n); 
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}