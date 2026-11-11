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
    ll ans = 1;
    ll cnt = 1;
    for(ll i=1;i<n;i++){
        if(a[i]>(a[i-1]*2LL)){
            ans = max(ans,cnt);
            cnt = 1;
        }
        else cnt++;
    }
    ans = max(ans,cnt);
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}