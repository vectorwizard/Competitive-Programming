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
    sort(a.begin(),a.end());
    vector<ll> pref(n,0);
    for(ll i=0;i<n;i++){
        ll prev_ind = i - m;
        ll prev = 0;
        if(prev_ind>=0) prev = pref[prev_ind];
        pref[i] = prev + a[i];
    }
    ll total = 0;
    for(ll i=0;i<n;i++){
        total+=pref[i];
        cout<<total<<" ";
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
