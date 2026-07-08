#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const ll mod = 1e9 + 7;
void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend());
    ll ans = 1;
    for(ll i=0;i<n;i++){
        ll x = b[i];
        ll ind = upper_bound(a.begin(),a.end(),x) - a.begin();
        ll take = (n-ind);
        ll avail = (take-i);
        if(avail<=0){
            cout<<0<<endl;
            return;
        }
        else{
            ans = (ans*avail)%mod;
        }
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
