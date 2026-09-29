#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k;
    cin>>n>>k;
    ll ans = 0;
    ll cnt = 2;
    for(ll i=0;i<n-k;i++){
        ans+=(cnt);
        cnt = cnt*2;
    }
    ans+=(k*2);
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}