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
    vector<ll> vec;
    for(ll i=0;i<n;i++){
        vec.push_back(abs(a[i]));
    }
    sort(vec.begin(),vec.end());
    ll cnt = 0;
    for(ll i=0;i<n;i++){
        ll ubb = upper_bound(vec.begin(),vec.end(),2*vec[i]) - vec.begin();
        ubb--;
        ll d = ubb - i;
        cnt+=d;
    }
    cout<<cnt<<endl;
} 

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
