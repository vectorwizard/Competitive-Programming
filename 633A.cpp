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
    ll maxi = -(1e9+2);
    vector<ll> vec;
    for(ll i=0;i<n;i++){
        if(a[i]<maxi){
            vec.push_back(abs(maxi-a[i]));
        }
        else maxi = max(maxi,a[i]);
    }
    ll ans = 0;
    for(ll i=0;i<vec.size();i++){
        ll cnt = __builtin_clzll(vec[i]);
        ans = max(ans,64-cnt);
    }
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}