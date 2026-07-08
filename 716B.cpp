#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const ll mod = 1e9 + 7;
ll power(ll n,ll k){
    if(k==0) return 1;
    ll ans = 0;
    ll x = (power(n,k/2))%mod;
    ans+=((x*x)%mod);
    if(k%2==1) ans=(ans*n)%mod;
    return (ans)%mod;
}
void solve() {
    ll n,k;
    cin>>n>>k;
    ll ans = (power(n,k))%mod;
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
