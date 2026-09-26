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
    vector<ll> ans;
    for(ll i=0;i<n;i++){
        mpp[a[i]]++;
    }
    while(ans.size()<n){
        vector<int> to_erase;
        for(auto it=mpp.rbegin();it!=mpp.rend();it++){
            ans.push_back(it->first);
            it->second--;
            if(it->second==0) to_erase.push_back(it->first);
        }
        for(auto it:to_erase) mpp.erase(it);
    }
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
