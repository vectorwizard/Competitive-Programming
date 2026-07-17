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
    ll m = n*k;
    vector<ll> a(m);
    for(ll i=0;i<m;i++) cin>>a[i];
    ll total = 0;
    ll gap = (n/2)+1;
    ll ind = n*k-gap;
    ll cnt = k;
    while(cnt>0){
        total+=a[ind];
        ind-=gap;
        cnt--;
    }
    cout<<total<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
