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
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<pair<ll,ll>> vec(n);
    for(ll i=0;i<n;i++) vec[i] = {a[i],i};
    sort(vec.rbegin(),vec.rend());
    ll cnt = 0;
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ll x = cnt * vec[i].first + 1;
        ans+=x;
        cnt++;
    }
    cout<<ans<<endl;
    for(ll i=0;i<n;i++){
        cout<<vec[i].second+1<<" ";

    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}