#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,x,y,z;
    cin>>n>>x>>y>>z;
    ll ans = (n+(x+y-1))/(x+y);
    ll temp = x+10*y;
    ll cost = ((n-z*x)+(temp-1))/temp;
    ans = min(ans,(z+cost));
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
