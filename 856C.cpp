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
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    ll l = 1;
    for(ll r=1;r<=n;r++){
        ll len = r-l+1;
        while(a[l]<len){
            l++;
            len=r-l+1;
        }
        len=r-l+1;
        cout<<len<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}

