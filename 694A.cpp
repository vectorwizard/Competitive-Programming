#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<ll> k(n);
    vector<ll> c(m+1);
    for(ll i=0;i<n;i++) cin>>k[i];
    for(ll i=1;i<=m;i++) cin>>c[i];
    sort(k.rbegin(),k.rend());
    ll l = 0;
    ll r = 1;
    ll total = 0;
    while(l<n){
        if(r<k[l]){
            total+=c[r];
            r++;
        }
        else if(r==k[l]){
            total+=c[r];
        }
        else{
            total+=c[k[l]];
        }
        l++;
    }
    cout<<total<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
