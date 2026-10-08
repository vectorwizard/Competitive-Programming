
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
    vector<ll> x(n+1);
    for(ll i=1;i<=n;i++) cin>>x[i];
    ll l = 1,r = 1;
    ll maxi = 1;
    map<ll,vector<ll>> mpp;
    for(ll i=1;i<=n;i++){
        mpp[x[i]].push_back(i);
    }
    ll a = x[1]; 
    for(auto it:mpp){
        ll num = it.first;
        vector<ll> temp = it.second;
        if(temp.size()==1) continue;
        ll mini = -temp[0];
        ll left = temp[0];
        for(ll i=1;i<temp.size();i++){
            ll val = 2*i - temp[i];
            if(val<mini){
                mini = val;
                left = temp[i];
            }
            ll comp = val - mini + 1;
            if(comp>maxi){
                maxi = comp;
                l = left;
                r = temp[i];
                a = num;
            }
        }
    }
    cout<<a<<" "<<l<<" "<<r<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}