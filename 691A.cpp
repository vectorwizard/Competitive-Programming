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
    vector<ll> b(m);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<m;i++) cin>>b[i];
    sort(a.begin(),a.end());
    if(n==1){
        for(ll i=0;i<m;i++) cout<<a[0]+b[i]<<" ";
        cout<<endl;
        return;
    }
    ll gcdd = a[1]-a[0];
    for(ll i=2;i<n;i++) gcdd = __gcd(gcdd,a[i]-a[0]);
    for(ll i=0;i<m;i++){
        ll ans = gcdd;
        ans = __gcd(ans,a[0]+b[i]);
        cout<<ans<<" ";
    }
    cout<<endl;
} 

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
