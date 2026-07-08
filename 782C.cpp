#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll> vec(n);
    for(ll i=0;i<n;i++) cin>>vec[i];
    unordered_map<ll,ll> mpp;
    mpp[n] = 0;
    for(ll i=n-1;i>=0;i--){
        mpp[i] = mpp[i+1]+vec[i];
    }
     ll ans = b*mpp[0];
    for(ll i=0;i<n;i++){
        ll cost = a*vec[i];
        cost+=(b*vec[i]);
        cost+=(b*(mpp[i+1]-((n-i-1)*vec[i])));
        ans = min(ans,cost);
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
