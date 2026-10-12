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
    ll ans = 1e9;
    for(ll j=0;j<=2e5;j++){
        ll x = j;
        vector<ll> temp;
        for(ll i=0;i<n;i++){
            if(a[i]<x) continue;
            ll cnt = 0;
            ll y = a[i];
            while(y>x){
                y/=2;
                cnt++;
            }
            if(y==x) temp.push_back(cnt);
            sort(temp.begin(),temp.end());
            if(temp.size()<k) continue;
            ll xy = 0;
            for(ll l=0;l<k;l++){
                xy+=temp[l];
            }
            ans = min(ans,xy);
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
