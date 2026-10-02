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
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    map<ll,ll> mpp;
    for(ll i=1;i<=n;i++){
        mpp[i*a[i]]++;
        mpp[i*(a[i]+1)]--;
    }
    ll poss = 0;
    vector<ll> ans;
    for(ll i=0;i<n;i++){
        if(mpp.count(i)) poss+=mpp[i];
        if(poss<=0){
            ans.push_back(i);
        }
    } 
    cout<<ans.size()<<endl;
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