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
    vector<vector<ll>> a(m,vector<ll>(n));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++ ){
            cin>>a[j][i];
        }
    }
    ll ans = 0;
    for(ll j=0;j<m;j++){
        sort(a[j].begin(),a[j].end());
        ll prefix = 0;
        for(ll i=0;i<n;i++){
            ans+=((i*a[j][i])- prefix);
            prefix+=a[j][i];
        }
    }
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
