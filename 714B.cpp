#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const ll mod = 1e9 + 7;
vector<ll> dp;
void fact(ll n){
    dp[0] = 1;
    dp[1] = 1;
    for(ll i=2;i<=n;i++){
        dp[i] = (dp[i-1] * i)%mod;
    }
}
void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
     ll total = a[0];
     for(ll i=1;i<n;i++) total = total&a[i];
     ll cnt = 0;
     for(ll i=0;i<n;i++){
        if(a[i]==total) cnt++;
     }
     ll x = (cnt*(cnt-1))%mod;
     cout<<(x*dp[n-2])%mod<<endl;
}   

int main() {
    dp.resize(2e5+3,0);
    fact(2e5+1);
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
