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
    vector<ll> b(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    if(a[n-1]!=b[n-1]){
        cout<<"NO"<<endl;
        return;
    }
    vector<ll> temp = a;
    for(ll i=0;i<n-1;i++){
        if(a[i]==b[i]) continue;
        if((a[i]^b[i+1])==b[i]) continue;
        if((a[i]^a[i+1])==b[i]) continue;
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}