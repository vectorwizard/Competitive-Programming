#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll x,y;
    cin>>x>>y;
    ll ans = 0;
    for(ll k=1;k*k<=x;k++){
        ll max_b = min(y, x / k - 1);
        if (max_b >= k + 1) {
            ans += (max_b - k); 
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}