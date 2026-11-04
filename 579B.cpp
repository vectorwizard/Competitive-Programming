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
    vector<ll> a(4*n);
    for(ll i=0;i<4*n;i++) cin>>a[i];
    map<ll,ll> mpp;
    for(auto it:a) mpp[it]++;
    ll target = mpp.begin()->first * mpp.rbegin()->first;
    for(auto it:mpp){
        if(target%it.first!=0){
            cout<<"NO"<<endl;
            return;
        }
        int b = target/it.first;
        if(it.second%2==1 || mpp[b]%2==1){
            cout<<"NO"<<endl;
            return;
        }
        if(it.second!=mpp[b]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}