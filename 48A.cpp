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
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll curr = 0;
    for(ll i=0;i<n;i++){
        ll next = curr + a[i];
        if(next<m){
            curr+=a[i];
            cout<<0<<" ";
        }
        else{
            ll temp = curr+a[i];
            ll turn = (temp/m);
            curr=(curr+a[i])%m;
            cout<<turn<<" ";
        }
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
