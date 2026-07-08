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
    ll l = 0;
    ll r = n-1;
    sort(a.rbegin(),a.rend());
    map<ll,ll> prefix;
    prefix[-1] = 0;
    for(ll i=0;i<n;i++) prefix[i] = prefix[i-1] + a[i];
    ll ans = 0;
    for(ll i=0;i<=k;i++){
        ll left = i;
        ll right = (k-i)*2;
        ll sum = prefix[n-1-right];
        sum = sum-prefix[left-1];
        ans = max(ans,sum);
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
