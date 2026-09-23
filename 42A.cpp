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
    ll total = accumulate(a.begin(),a.end(),0LL);
    ll sum = 0;
    ll target = (total+1)/2;
    for(ll i=0;i<n;i++){
        sum+=a[i];
        if(sum>=target){
            cout<<i+1<<endl;
            return;
        }
    }
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
