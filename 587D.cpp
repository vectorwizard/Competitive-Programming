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
    vector<ll> bads;
    for(ll i=0;i<n;i++){
        ll diff = maxi - a[i];
        if(diff!=0) bads.push_back(diff); 
    }
    if(bads.size()==0){
        cout<<0<<" "<<0<<endl;
        return;
    }
    ll gcdd = bads[0];
    ll total = accumulate(bads.begin(),bads.end(),0LL);
    for(ll i=1;i<bads.size();i++) gcdd = __gcd(gcdd,bads[i]);
    cout<<total/gcdd<<" "<<gcdd<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}