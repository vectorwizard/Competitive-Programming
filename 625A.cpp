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
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    map<ll,ll> mpp;
    for(ll i=1;i<=n;i++){
        ll x = (a[i]-i);
        mpp[x]+=a[i];
    }
    ll maxi = 0;
    for(auto it:mpp){
        maxi = max(maxi,it.second);
    }
    cout<<maxi<<endl;
}   

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
