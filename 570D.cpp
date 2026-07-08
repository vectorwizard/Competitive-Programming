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
    unordered_map<ll,ll> mpp;
    for(ll i=0;i<n;i++){
        mpp[a[i]]++;
    }
    vector<ll> vec;
    for(auto it:mpp) vec.push_back(it.second);
    sort(vec.rbegin(),vec.rend());
    ll last = 1e18;
    ll ans = 0;
    for(ll i=0;i<vec.size();i++){
        ll take = min(last,vec[i]);
        if(take>0) ans+=take;
        last=take-1;
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
