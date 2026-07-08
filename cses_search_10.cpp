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
    sort(a.begin(),a.end());
    ll s = 0;
    for(ll i=0;i<n;i++){
        if(a[i]>(s+1)) break;
        s += a[i];
    }
    cout<<(s+1)<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}