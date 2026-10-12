#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<ll> pref(10,0);
    for(ll i=1;i<10;i++){
        pref[i] = (m*i)%10;
    }
    for(ll i=1;i<10;i++) pref[i]+=pref[i-1];
    ll res = (n/m)/10;
    ll rem = (n/m)%10;
    ll ans = res * pref[9];
    ans+=pref[rem];
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
