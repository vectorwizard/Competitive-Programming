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
    ll maxi = 0;
    ll ele = -1;
    for(ll i=0;i<n;i++){
        mpp[a[i]]++;
        if(mpp[a[i]]>maxi){
            maxi = mpp[a[i]];
            ele = a[i];
        }
    }
    if(maxi<=(n/2+1)){
        cout<<accumulate(a.begin(),a.end(),0)<<endl;
        return;
    }
    ll ans = 0;
    ll cnt = 0;
    for(auto it:mpp){
        if(it.first==ele) continue;
        ans+=(it.second*it.first);
        cnt+=it.second;
    }
    ans+=((cnt+2)*ele);
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
