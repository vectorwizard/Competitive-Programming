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
    ll ans = 0;
    vector<ll> a(n+1,0);
    for(ll i=1;i<=n;i++){
        for(ll j=1;j*j<=i;j++){
            if(i%j==0) a[j]++;
            if(i%j==0 && i/j!=j){
                a[i/j]++;
            }
        }
    }
    for(ll i=1;i<=n;i++){
        ans+=(a[i]*a[i]);
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
