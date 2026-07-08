#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const ll mod = 676767677;
void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll ans = 0;
    bool ones = false;
    for(ll i=0;i<n;i++){
        if(a[i]==1) ones = true;
        if(a[i]!=1){
            ans=(ans+a[i])%mod;
        }
    }
    if(ones && a[n-1]==1) ans++;
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
