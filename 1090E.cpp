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
    ll maxi = 0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i==j) continue;
            maxi = max(maxi,(a[i]^a[j]));
        }
    }
    cout<<maxi<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}