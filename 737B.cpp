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
    vector<ll> sorted = a;
    sort(sorted.begin(),sorted.end());
    map<ll,ll> mpp;
    for(ll i=0;i<n-1;i++){
        mpp[sorted[i]]=sorted[i+1];
    }
    mpp[sorted[n-1]] = -2e9;
    ll cnt = 0;
    for(ll i=1;i<n;i++){
        if(mpp[a[i-1]]!=a[i]) cnt++;
    }
    cnt++;
    if(cnt<=k) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
