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
    ll gcd1 = a[0];
    ll gcd2 = a[1];
    for(ll i=2;i<n;i+=2){
        gcd1 = __gcd(gcd1,a[i]);
    }
    for(ll i=3;i<n;i+=2){
        gcd2 = __gcd(gcd2,a[i]);
    }
    if(gcd1==gcd2){
        cout<<0<<endl;
        return;
    }
    bool fl = true;
    for(ll i=1;i<n;i+=2){
        if(a[i]%gcd1==0){
            fl = false;
            break;
        }
    }
    if(fl) {
        cout<<gcd1<<endl;
        return;
    }
    fl = true;
    for(ll i=0;i<n;i+=2){
        if(a[i]%gcd2==0){
            fl = false;
            break;
        }
    }
    if(fl) cout<<gcd2<<endl;
    else cout<<0<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
