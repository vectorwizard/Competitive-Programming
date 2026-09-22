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
    vector<ll> primes = {2,3,5,7,11,13,17,19,23,29,31};
    map<ll,vector<ll>> mpp;
    for(ll i=0;i<n;i++){
        ll num = a[i];
        for(ll j=0;j<11;j++){
            if(num%primes[j]==0){
                mpp[j].push_back(i);
                break;
            }
        }
    }
    ll cnt = 1;
    vector<ll> ans(n);
    for(auto it:mpp){
        for(ll i=0;i<it.second.size();i++){
            ans[it.second[i]] = cnt;
        }
        cnt++;
    }
    cout<<cnt-1<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}