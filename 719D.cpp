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
    unordered_map<ll,ll> mpp;
    ll ans = 0;
    for(ll i=0;i<n;i++){
        mpp[a[i]-i]++;
    }
    for(auto it:mpp){
        ll x = it.second;
        ans+=((x*(x-1))/2);
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
