#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll a,b,k;
    cin>>a>>b>>k;
    vector<pair<ll,ll>> vec(k);
    for(ll i=0;i<k;i++){
        ll x;
        cin>>x;
        vec[i].first = x;
    }
    for(ll i=0;i<k;i++){
        ll x;
        cin>>x;
        vec[i].second = x;
    }
    map<ll,ll> boys;
    map<ll,ll> girls;
    for(ll i=0;i<k;i++){
        boys[vec[i].first]++;
        girls[vec[i].second]++;
    }
    ll ans = 0;
    for(ll i=0;i<k;i++){
        ll boy = vec[i].first;
        ll girl = vec[i].second;
        ans = ans+ k - boys[boy] - girls[girl] + 1;
    }
    cout<<(ans/2)<<endl;
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
