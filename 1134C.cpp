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
    map<ll,ll> mpp;
    for(ll i=0;i<n;i++) mpp[a[i]]++;
    ll ans = 0;
    vector<ll> temp1;
    vector<ll> temp2;
    for(auto it:mpp){
        ans++;
        mpp[it.first]--;
        temp1.push_back(it.first);
    }
    for(auto it:mpp){
        if(it.second==0) continue;
        ans++;
        mpp[it.first]--;
        temp2.push_back(it.first);
    }
    cout<<ans<<endl;
    for(auto it:mpp){
        if(it.second==0) continue;
        for(ll i=0;i<it.second;i++){
            temp1.push_back(it.first);
        }
    }
    reverse(temp2.begin(),temp2.end());
    for(auto it:temp2){
        temp1.push_back(it);
    }
    for(auto it:temp1){
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