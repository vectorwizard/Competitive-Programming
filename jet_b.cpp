#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    vector<ll> pref(n+1,0);
    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1] + a[i];
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<pref[v]-pref[u-1]<<endl;
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