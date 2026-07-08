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
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll ans = 0;
    ll l = 0;
    ll x = 1;
    ll last = -1;
    for(ll r=1;r<=k;r++){
        ll prev = a[r-1];
        ll curr = a[r] * 2;
        if(curr<=prev) last = r-1;
    }
    if(last==-1) ans++;
    for(ll r=k+1;r<n;r++){
        ll curr = a[r]*2;
        ll prev = a[r-1];
        ll l = r-k;
        if(curr<=prev) last = r-1;
        else if(last<l) ans++;
    }
    cout<<ans<<endl;
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
