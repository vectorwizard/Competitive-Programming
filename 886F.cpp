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
        mpp[a[i]]++;
    }
    vector<ll> freq(n+1,0);
    for(auto it:mpp){
        ll x = it.first;
        for(ll j=x;j<=n;j+=x){
            freq[j]+=it.second;
        }
    }
    ll maxi = 0;
    for(auto it:freq){
        maxi = max(maxi,it);
    }
    cout<<maxi<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
