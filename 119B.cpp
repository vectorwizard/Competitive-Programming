#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll w,h;
    cin>>w>>h;
    ll ans = 0;
    for(ll i = 2;i<=h;i+=2){
        for(ll j = 2;j<=w;j+=2){
            ans+=((w-j+1) * (h-i+1));
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
