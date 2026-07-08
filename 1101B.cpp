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
    ll ans = a[0];
    cout<<ans<<" ";
    ll total = a[0];
    for(ll i=1;i<n;i++){
        total+=a[i];
        ans = min(ans,(total)/(i+1));
        cout<<ans<<" ";
    }
    cout<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}