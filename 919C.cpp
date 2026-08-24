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
    ll ans = 0;
    for(ll k=1;k*k<=n;k++){
        if(n%k!=0) continue;
        ll x = k;
        ll y = n/x;
        ll gcdd = 0;
        for(ll i=0;i<n-x;i++){
            gcdd = __gcd(gcdd,abs(a[i] - a[i+x]));
        }
        if(gcdd!=1) ans++;
        if(y!=x){
            gcdd = 0;
            for(ll i=0;i<n-y;i++){
                gcdd = __gcd(gcdd,abs(a[i] - a[i+y]));
            }
            if(gcdd!=1) ans++;
        }
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
