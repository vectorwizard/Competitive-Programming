#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    map<ll,ll> mpp;
    for(ll i=0;i<n;i++){
        mpp[a[i]]++;
    }
    bool ans = false;
    ll bad_min = 1e18;
    for (auto it = mpp.rbegin();it != mpp.rend();it++) {
        bool poss = false;
        if((it->first+k)>=bad_min) poss=true;
        else{
            if(it->second%2==0) poss = true;
            else poss = false;
        }
        if(poss){
            ans = true;
            cout<<"YES"<<endl;
            return;
        }
        else bad_min = it->first;
    }
    cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
