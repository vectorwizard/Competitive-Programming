#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll l = a[0] - x;
    ll r = a[0] + x;
    ll ans = 0;
    for(ll i=1;i<n;i++){
        ll left = a[i]-x;
        ll right = a[i]+x;
        if(right<l || left>r) {
            ans++;
            l = left;
            r = right;
        }
        else{
            l = max(l,left);
            r = min(r,right);
        }
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
