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
    for(ll i = 0;i<n;i++) cin>>a[i];
    map<ll,ll> mpp;
    for(ll i=0;i<n-4;i++){
        mpp[a[i]+a[i+2]-a[i+4]]++;
    }
    ll ans = 0;
    for(ll i=0;i<n-4;i++){
        ll x = a[i] + a[i+2] - a[i+4];
        mpp[x]--;
        ll n1 = i + 2;
        ll n2 = i + 4;
        if(i+6<n) mpp[a[i+2]+a[i+4]-a[i+6]]--;
        if(i+8<n) mpp[a[i+4]+a[i+6]-a[i+8]]--;
        ans+=mpp[x];
        if(i+6<n) mpp[a[i+2]+a[i+4]-a[i+6]]++;
        if(i+8<n) mpp[a[i+4]+a[i+6]-a[i+8]]++;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}