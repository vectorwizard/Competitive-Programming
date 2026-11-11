#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,q,k;
    cin>>n>>q>>k;
    vector<ll> a(n+2);
    a[0] = -1;
    for(ll i=1;i<=n;i++) cin>>a[i];
    a[n+1] = k+1;
    map<ll,ll> pref;
    pref[0] = 0;
    for(ll i=1;i<=n;i++){
        pref[i] = a[i+1] - a[i-1] - 2;
    }
    for(ll i=1;i<=n;i++){
        pref[i] = pref[i-1]+pref[i];
    }
    ll ans = 0;
    while(q--){
        ll l,r;
        cin>>l>>r;
        ans = pref[r] - pref[l-1];
        ans+=a[l-1];
        ans+=(k+1-a[r+1]);
        cout<<ans<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}