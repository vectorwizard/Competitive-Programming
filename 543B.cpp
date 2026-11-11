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
    map<ll,ll> mpp;
    for(ll i=0;i<n;i++){
        for(ll j = 0;j<n;j++){
            if(i==j) continue;
            mpp[a[i]+a[j]]++;
        }
    }
    for(auto it:mpp){
        mpp[it.first]/=2;
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
    // cin>>t;
    while (t--) solve();
    return 0;
}