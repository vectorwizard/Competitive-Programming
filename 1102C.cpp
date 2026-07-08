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
    for(ll i=0;i<n;i++){
        vector<ll> temp(n,0);
        ll maxi = 0;
        for(ll j=1;j<n;j++){
            ll ind = (i + j)%n;
            maxi = max(maxi,a[(i+j-1)%n]);
            temp[ind] = max(temp[ind],maxi);
        }
        maxi = 0;
        for(ll j=1;j<n;j++){
            ll ind = (i - j + n)%n;
            maxi = max(maxi,a[ind]);
            temp[ind] = min(temp[ind],maxi);
        }
        ll ans = 0;
        for(ll k=0;k<n;k++) ans+=temp[k];
        cout<<ans<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
