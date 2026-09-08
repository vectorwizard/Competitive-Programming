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
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll l = 0;
    ll r = k;
    ll ans = 1e9;
    ll poll = -1;
    ll dist = (a[r]-a[l]+1)/2;
    if(dist<ans){
        ans = dist;
        poll = a[l] + dist;
    }
    r++;
    l++;
    while(r<n){
        ll dist = (a[r]-a[l]+1)/2;
        if(dist<ans){
            ans = dist;
            poll = a[l] + dist;
        }
        l++;
        r++;
    }
    cout<<poll<<endl;
} 
 
int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
