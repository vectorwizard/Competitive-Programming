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
    vector<ll> num = {4,8,15,16,23,42};
    map<ll,ll> mpp;
    mpp[4] = 0;
    mpp[8] = 1;
    mpp[15] = 2;
    mpp[16] = 3;
    mpp[23] = 4;
    mpp[42] = 5;
    vector<ll> ans(6);
    for(ll i=0;i<n;i++){
        if(a[i]==num[0]){
            ans[0]++;
        }
        else if(ans[mpp[a[i]]]<ans[mpp[a[i]]-1]){
            ans[mpp[a[i]]]++;
        }
    }
    cout<<(n-ans[5]*6)<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
