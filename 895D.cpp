#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,x,y;
    cin>>n>>x>>y;
    ll cnt_x = n/x;
    ll cnt_y = n/y;
    ll temp = (1LL*x*y)/__gcd(x,y);
    ll cnt_com = n/temp;
    ll ans = 0;
    x = cnt_x - cnt_com;
    ll ap_n = (n*(n+1))/2;
    ll ap_nx = ((n-x)*(n-x+1))/2;
    y = cnt_y - cnt_com;
    ll ap_y = (y*(y+1))/2;
    ans = (ap_n-ap_nx) - ap_y;
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
