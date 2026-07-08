#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const ll  mod = 1e9 + 7;
void solve() {
    ll n;
    cin>>n;
    ll ans = n % mod;
    ans = (ans * ((n + 1) % mod)) % mod;
    ans = (ans * ((n-1) % mod)) % mod;
    ans = (ans * 674) % mod;
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
