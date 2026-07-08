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
    vector<ll> pref(n);
    pref[0] = a[0];
    for(ll i=1;i<n;i++){
        pref[i] = pref[i-1] + a[i];
    }
    ll ans = 0;
    for(ll k=1;k*k<=n;k++){
        if(n%k!=0) continue;
        ll a = k;
        ll b = n/k;
        ll i = a-1;
        ll maxi = 0;
        ll mini = 1e18;
        while(i<n){
            ll x = 0;
            if((i-a)>=0) x = pref[i-a];
            maxi = max(maxi,pref[i]-x);
            mini = min(mini,pref[i]-x);
            i+=a;
        }
        ans = max(ans,(maxi-mini));
        i = b-1;
        maxi = 0;
        mini = 1e18;
        while(i<n){
            ll x = 0;
            if((i-b)>=0) x = pref[i-b];
            maxi = max(maxi,pref[i]-x);
            mini = min(mini,pref[i]-x);
            i+=b;
        }
        ans = max(ans,(maxi-mini));
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
