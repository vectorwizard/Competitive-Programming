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
    ll gcdd = a[0];
    for(ll i=1;i<n;i++) gcdd = __gcd(gcdd,a[i]);
    ll ans = 0;
    for(ll i = 1;i*i<=gcdd;i++){
        if((gcdd%i)==0){
            if((gcdd/i)==i) ans++;
            else ans+=2;
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