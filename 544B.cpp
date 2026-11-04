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
    map<ll,ll> mpp;
    for(ll i=0;i<n;i++) mpp[a[i]%k]++;
    ll ans = (mpp[0]/2)*2;
    for(ll i=1;i<k;i++){
        if(mpp.count(i)==0 || mpp.count(k-i)==0) continue;
        if(i==(k-i)){
            int cnt = mpp[i];
            ans+=((mpp[i]/2)*2);
        }
        else{
            ll cnt1 = mpp[i];
            ll cnt2 = mpp[k-i];
            ll mini = min(cnt1,cnt2);
            mpp.erase(i);
            mpp.erase(k-i);
            ans+=(2*mini);
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}