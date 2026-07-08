#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    map<ll,ll> mpp;
    for(ll i=0;i<n;i++){
        ll divisor = (a[i]/k);
        ll rem = (a[i]%k);
        if(rem==0) continue;
        rem = (k*(divisor+1)) - a[i];
        mpp[rem]++;
    }
    ll ans = 0;
    for(auto it:mpp){
        ll cnt = it.second;
        ll rem = it.first;
        ll steps = (cnt-1)*k + rem+1;
        ans = max(ans,steps);
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
