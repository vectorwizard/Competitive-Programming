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
    vector<pair<ll,ll>> vec;
    for(ll i=0;i<n;i++){
        vec.push_back({a[i],i+1});
    }
    sort(vec.begin(),vec.end());
    ll ans = 0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            if((vec[i].first*vec[j].first)>2*n) break;
            if((vec[i].first*vec[j].first)==(vec[i].second + vec[j].second)) ans++;
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
