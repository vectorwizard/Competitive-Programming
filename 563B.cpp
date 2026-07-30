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
    bool odd = false;
    bool even = false;
    for(ll i=0;i<n;i++){
        if(a[i]%2==0) even = true;
        else odd = true;
    }
    if(odd && even) sort(a.begin(),a.end());
    for(auto it:a){
        cout<<it<<" ";
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
