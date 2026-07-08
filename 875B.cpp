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
    vector<ll> b(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    map<ll,ll> mpp1;
    map<ll,ll> mpp2;
    mpp1[a[0]]++;
    ll len = 1;
    for(ll i=1;i<n;i++){
        if(a[i]==a[i-1]){
            len++;
            mpp1[a[i]] = max(mpp1[a[i]],len);
        }
        else{
            len = 1;
            mpp1[a[i]] = max(mpp1[a[i]],len);
        }
    }
    len = 1;
    mpp2[b[0]]++;
    for(ll i=1;i<n;i++){
        if(b[i]==b[i-1]){
            len++;
            mpp2[b[i]] = max(mpp2[b[i]],len);
        }
        else{
            len = 1;
            mpp2[b[i]] = max(mpp2[b[i]],len);
        }
    }
    ll maxi = 1;
    for(auto it:mpp1){
        ll x = 0;
        if(mpp2.find(it.first)!=mpp2.end()) x = mpp2[it.first];
        maxi = max(maxi,it.second+x);
    }
    for(auto it:mpp2){
        ll x = 0;
        if(mpp1.find(it.first)!=mpp1.end()) x = mpp1[it.first];
        maxi = max(maxi,it.second+x);
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
