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
    vector<ll> sorted = a;
    sort(sorted.begin(),sorted.end());
    ll carry = 0;
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ll have = (carry+a[i]);
        ll move = (have-sorted[i]);
        carry = move;
        ans+=move;
    }
    ll temp = ans;
    for(ll i=1;i<n;i++){
        ll h = a[i];
        ll ind = lower_bound(sorted.begin(),sorted.end(),h)-sorted.begin();
        ans=max(ans,temp+(i-ind));
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
