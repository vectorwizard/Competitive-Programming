#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n;
    cin>>n;
    ll ans = 0;
    for(ll i=0;i<=60;i++){
        ll x = (1LL<<i);
        ans+=(n/x);
    }
    cout<<ans<<endl;
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
