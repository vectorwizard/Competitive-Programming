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
    ll k;
    cin>>k;
    ll maxi = 0;
    vector<ll> v1(k);
    for(ll i=0;i<k;i++) cin>>v1[i];
    maxi = max(maxi,(v1[k-1]-v1[0])*h);
    cin>>k;
    vector<ll> v2(k);
    for(ll i=0;i<k;i++) cin>>v2[i];
    maxi = max(maxi,(v2[k-1]-v2[0])*h);
    cin>>k;
    vector<ll> v3(k);
    for(ll i=0;i<k;i++) cin>>v3[i];
    maxi = max(maxi,(v3[k-1]-v3[0])*w);
    cin>>k;
    vector<ll> v4(k);
    for(ll i=0;i<k;i++) cin>>v4[i];
    maxi = max(maxi,(v4[k-1]-v4[0])*w);
    cout<<maxi<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
