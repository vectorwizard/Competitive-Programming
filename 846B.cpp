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
    ll ans = 0;
    ll total = accumulate(a.begin(),a.end(),0LL);
    ll sum = 0;
    for(ll i=0;i<n-1;i++){
        sum+=a[i];
        ll b = total-sum;
        ans = max(ans,__gcd(sum,b));
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
