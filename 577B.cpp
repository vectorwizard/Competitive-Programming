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
    ll maxi = *max_element(a.begin(),a.end());
    ll total = accumulate(a.begin(),a.end(),0LL);
    if(total%2!=0){
        cout<<"NO"<<endl;
        return;
    }
    if(maxi>(total-maxi)){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}