#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k,q;
    cin>>n>>k>>q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll ans = 0;
    ll len = 0;
    for(ll i=0;i<n;i++){
        if(a[i]<=q) {
            len++;
            if(len>=k) ans+=(len-k+1);
        }
        else len = 0;
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
