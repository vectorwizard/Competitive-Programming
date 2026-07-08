#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,d;
    cin>>n>>d;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll r = n-1;
    ll l = 0;
    ll ans = 0;
    while(l<r){
        if(a[r]>d){
            ans++;
            r--;
        }
        else{
            ll cnt = a[r];
            ll x = a[r];
            while(l<r && cnt<=d){
                cnt+=x;
                l++;
            }
            if(cnt>d) ans++;
            r--;
        }
    }
    if((l==r) && (a[l]>d)) ans++;
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
