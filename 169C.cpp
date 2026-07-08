#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.rbegin(),a.rend());
    vector<pair<ll,ll>> queries(q);
    for(ll i=0;i<q;i++){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        queries[i] = {u,v};
    }
    map<ll,ll> mpp;
    for(auto it:queries){
        mpp[it.first]++;
        mpp[it.second+1]--;
    }
    vector<pair<ll,ll>> diff(n);
    ll cnt = 0;
    for(ll i=0;i<n;i++){
        cnt+=mpp[i];
        diff[i] = {cnt,i};
    }
    sort(diff.rbegin(),diff.rend());
    ll i = 0;
    ll j = 0;
    vector<ll> ans(n);
    while(i<n){
        ans[diff[i].second] = a[j];
        i++;
        j++;
    }
    map<ll,ll> pref;
    pref[-1] = 0;
    for(ll i=0;i<n;i++){
        pref[i] = pref[i-1] + ans[i];
    }
    ll final = 0;
    for(auto it:queries){
        final+=(pref[it.second]-pref[it.first-1]);
    }
    cout<<final<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
