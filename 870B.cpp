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
    if(n==1){
        cout<<0<<endl;
        return;
    }
    ll ans = abs(a[0]-a[n-1]);
    ll l = 1;
    ll r = n-2;
    while(l<r){
        ll x = (abs(a[l]-a[r]));
        ans = gcd(ans,x);
        l++;
        r--;
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
