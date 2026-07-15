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
    ll ones = 0;
    for(ll i=0;i<n;i++){
        if(a[i]==1) ones++; 
    }
    if(ones==0){
        cout<<0<<endl;
        return;
    }
    ll zeros = 0;
    for(ll i=0;i<n;i++){
        if(a[i]==0) zeros++; 
    }
    ll x = (1LL<<zeros);
    cout<<(ones*x)<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
