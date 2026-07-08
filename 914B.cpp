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
        vec.push_back({a[i],i});
    }
    sort(vec.begin(),vec.end());
    map<ll,ll> mpp;
    mpp[-1] = 0;
    for(ll i=0;i<n;i++){
        mpp[i] = mpp[i-1] + vec[i].first;
    }
    vector<ll> blocker;
    vector<ll> ans(n);
    for(ll i=1;i<n;i++){
        if(vec[i].first>mpp[i-1]) blocker.push_back(i);
    }
    for(ll i=0;i<n;i++){
        ll ind = upper_bound(blocker.begin(),blocker.end(),i)-blocker.begin();
        if(ind==blocker.size()){
            ans[vec[i].second] = n-1;
        }
        else ans[vec[i].second] = blocker[ind]-1;
    }
    for(ll i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
