#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll a,b,n;
    cin>>a>>b>>n;
    vector<ll> vec(n);
    for(ll i=0;i<n;i++) cin>>vec[i];
    sort(vec.begin(),vec.end());
    ll ans = (b-1);
    for(ll i=0;i<n;i++){
        ll x = min(1+vec[i],a);
        ans += (x-1);
    }
    cout<<ans+1<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
