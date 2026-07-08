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
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    map<ll,ll> mpp;
    map<ll,ll> pref;
    mpp[0] = 0;
    pref[0] = 0;
    for(ll i=1;i<=n;i++){
        ll x = 0;
        if((i-k-1)>=1){
            x = mpp[i-k-1];
        }
        mpp[i] = x + a[i];
        pref[i] = pref[i-1] + a[i];
    }
    for(ll i=1;i<=n;i++){
        ll x = 0;
        if((i-k)>=1){
            x = mpp[i-k];
        }
        cout<<(pref[i]-x)<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
