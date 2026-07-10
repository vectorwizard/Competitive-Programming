#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll x,y,k;
    cin>>x>>y>>k;
    ll a = k*y + k -1;
    ll b = x-1;
    ll c = (a+b-1)/b;
    cout<<(c+k)<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
