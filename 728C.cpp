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
    vector<ll> d(n);
    for(ll i=0;i<n;i++) cin>>d[i];
    sort(d.begin(),d.end());
    ll ans = 0;
    ll pref = d[0];
    for(ll i=1;i<n;i++){
        ll x = (d[i]*i);
        ans+=(pref-x);
        pref+=d[i];
    }
    ans+=d[n-1];
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
