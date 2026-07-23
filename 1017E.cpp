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
    vector<ll> sett(30,0);
    for(ll i=0;i<n;i++){
        ll num = a[i];
        for(ll j=0;j<30;j++){
            if(a[i]&(1<<j)) sett[j]++;
        }
    }
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ll num = a[i];
        ll cnt = 0;
        for(ll j=0;j<30;j++){
            ll x = (1<<j);
            if(a[i]&(1<<j)){
                cnt+=(x*(n-sett[j]));
            }
            else{
                cnt+=(x*sett[j]);
            }
        }
        ans = max(ans,cnt);
    }
    cout<<ans<<endl;
}   

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
