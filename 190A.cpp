#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,a,b;
    cin>>n>>a>>b;
    ll ans = 1e18;
    ll total3 = 1e18;
    ll total1 = n*a;
    ll x = n/3;
    ll total2 = x*b + (n%3)*a;
    if((n%3)!=0) total3 = x*b + b;
    ans = min(total1,min(total2,total3));
    cout<<ans<<endl;
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
