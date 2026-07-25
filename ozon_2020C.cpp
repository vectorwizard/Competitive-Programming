#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    if(n>m){
        cout<<0<<endl;
        return;
    }
    map<ll,ll> mpp;
    for(ll i=0;i<n;i++){
        mpp[a[i]%m]++;
        if(mpp[a[i]%m]>1){
            cout<<0<<endl;
            return;
        }
    }
    ll ans = 1;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            ll x = (abs(a[i]-a[j]))%m;
            ans = (ans*x)%m;
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
