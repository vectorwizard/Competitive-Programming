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
    mpp[0] = -1;
    ll maxi = -1;
    ll sum = 0;
    ll ans = 0;
    for(ll i=0;i<n;i++){
        sum+=a[i];
        if(mpp.find(sum)!=mpp.end()){
            maxi = max(maxi,mpp[sum]+1);
        }
        ans = ans+(i-maxi);
        mpp[sum] = i;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}

