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
    vector<ll> parity(n,0);
    for(ll i=0;i<n;i++){
        if(abs(a[i])%2==0) parity[i] = 0;
        else parity[i] = 1;
    }
    ll l = 0;
    vector<ll> prefix(n,0);
    prefix[0] = a[0];
    for(ll i=1;i<n;i++){
        prefix[i] = prefix[i-1] + a[i];
    }
    ll mini = min(0LL,a[0]);
    ll ans = a[0];
    for(ll r=1;r<n;r++){
        if(parity[r]!=parity[r-1]){
           ll x = prefix[r] - mini; 
           ans = max(ans,x);
           mini = min(mini,prefix[r]);
        }
        else{
            mini = min(prefix[r],prefix[r-1]);
            ans = max(ans,a[r]);
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
