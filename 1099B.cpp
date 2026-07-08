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
    for(ll i=1;i<n;i++){
        if(a[i]<a[i-1]){
            maxi = max(maxi,(a[i-1]-a[i]));
        }
    }
    for(ll i=1;i<n;i++){
        if(a[i]<a[i-1]){
            a[i] = a[i] + maxi;
        }
    }
    bool fl = true;
    for(ll i=1;i<n;i++){
        if(a[i]<a[i-1]){
            fl= false;
            break;
        }
    }
    if(fl) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
