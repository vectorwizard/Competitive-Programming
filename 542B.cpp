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
    vector<ll> a(2*n);
    for(ll i=0;i<2*n;i++) cin>>a[i];
    map<ll,ll> mpp1;
    map<ll,ll> mpp2;
    for(ll i=0;i<2*n;i++){
        if(mpp1.count(a[i])){
            mpp2[a[i]] = i;
        }
        else mpp1[a[i]] = i;
    }
    ll ans = 0;
    ll curr = 0;
    for(auto it:mpp1){
        ans+=abs(it.second-curr);
        curr = it.second;
    }
    curr = 0;
    for(auto it:mpp2){
        ans+=abs(it.second-curr);
        curr = it.second;
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