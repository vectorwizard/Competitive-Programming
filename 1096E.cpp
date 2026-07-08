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
    ll total = 0;
    for(ll i=0;i<n;i++) {
        cin>>a[i];
        total+=a[i];
    }
    vector<ll> suffix(n);
    suffix[n-1] = a[n-1];
    ll fixed = a[n-1];
    ll ans;
    for(ll i=n-2;i>=0;i--){
        suffix[i] = min(a[i],suffix[i+1]);
        fixed+=suffix[i];
    }
    ll x = (total-fixed);
    ans = (total-fixed);
    unordered_map<ll,ll> mpp;
    for(ll i=0;i<n;i++){
        mpp[suffix[i]]++;
        ll y = x+(mpp[a[i]]);
        ans = max(ans,y-1);
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
