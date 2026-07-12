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
    map<ll,ll> mpp1;
    map<ll,ll> mpp2;
    map<ll,ll> mpp3;
    map<ll,ll> mpp4;
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        mpp1[x]++;
        mpp2[y]++;
        mpp3[x-y]++;
        mpp4[x+y]++;
    }
    ll ans = 0;
    for(auto it:mpp1){
        ans+=(it.second*(it.second-1));
    }
    for(auto it:mpp2){
        ans+=(it.second*(it.second-1));
    }
    for(auto it:mpp3){
        ans+=(it.second*(it.second-1));
    }
    for(auto it:mpp4){
        ans+=(it.second*(it.second-1));
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
