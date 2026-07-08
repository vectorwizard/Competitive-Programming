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
    ll ans = (1LL<<32)-1;
    for(ll i=0;i<n;i++){
        if(sorted[i]!=a[i]){
            ans = ans & a[i];
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
