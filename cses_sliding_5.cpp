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
    for(int i=0;i<n;i++) cin>>a[i];
    map<ll,ll> mpp;
    for(int i=0;i<k;i++) mpp[a[i]]++;
    cout<<mpp.size()<<" ";
    ll l = 0;
    for(ll r=k;r<n;r++){
        mpp[a[r]]++;
        mpp[a[l]]--;
        if(mpp[a[l]]==0) mpp.erase(a[l]);
        l++;
        cout<<mpp.size()<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
