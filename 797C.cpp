
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
    vector<ll> s(n);
    vector<ll> f(n);
    for(ll i=0;i<n;i++) cin>>s[i];
    for(ll i=0;i<n;i++) cin>>f[i];
    vector<ll> ans(n);
    ans[0] = f[0] - max(0LL,s[0]);
    for(ll i=1;i<n;i++){
        ll start = max(s[i],f[i-1]);
        ll end = f[i];
        ans[i] = (end-start);
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int32_t main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}