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
    ll cnt = a[0];
    for(ll i=1;i<n;i++){
        if(a[i]<cnt){
            cnt+=a[i];
        }
        else{
            ans = max(ans,cnt);
            cnt = a[i];
        }
    }
    ans = max(ans,cnt);
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
