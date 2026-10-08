
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll ind,ll sum,map<ll,ll> &mpp){
    if(ind==3){
        ll digit = sum%10;
        if(digit==3) return true;
        return false;
    }
    for(ll i=0;i<10;i++){
        if(mpp.count(i)==0) continue;
        mpp[i]--;
        if(mpp[i]==0) mpp.erase(i);
        if(func(ind+1,sum+i,mpp)) return true;
        mpp[i]++;
    }
    return false;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    map<ll,ll> mpp;
    for(ll i=0;i<n;i++){
        ll x = a[i];
        ll digit = x%10;
        mpp[digit]++;
    }
    bool ans = func(0,0,mpp);
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}