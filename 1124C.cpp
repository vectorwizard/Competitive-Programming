#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    ll cnt = 0;
    ll ans = 0;
    ll l = k;
    ll r = (n-k+1);
    if(l<=r){
        for(ll i=l;i<=r;i++){
            ans+=a[i];
            cnt++;
        }
        l = n-k+2;
        r = k-1;
    }
    while((n-cnt)>=k){
        if(a[l]>=a[r]){
            cnt++;
            ans+=a[l];
            l++;
            r--;
        }
        else{
            cnt++;
            ans+=a[r];
            r--;
            l++;
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}