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
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        if(x%2==0) a[i] = 0;
        else a[i] = 1;
    }
    ll ans = 0;
    for(ll i=1;i<n;i++){
        if(a[i]==a[i-1]) ans++;
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