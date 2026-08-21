#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const ll mod = 998244353;

ll power(ll a,ll b){
    if(b==0) return 1;
    ll x = power(a,b/2)%mod;
    x = (x*x)%mod;
    if(b%2==1) x= (x*a)%mod;
    return x%mod;
}

void solve() {
    ll w,h;
    cin>>w>>h;
    ll ans = (power(2,w-1) * power(2,h-1) * 4)%mod;
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}