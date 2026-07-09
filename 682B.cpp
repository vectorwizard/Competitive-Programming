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
    vector<ll> b(n);
    for(ll i=0;i<n;i++) cin>>b[i];
    map<ll,ll> mpp;
    for(ll i=0;i<n;i++){
        mpp[b[i]]++;
        if(mpp[b[i]]>=2){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
