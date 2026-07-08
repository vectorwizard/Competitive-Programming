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
    vector<pair<ll,ll>> vec(n);
    map<ll,ll> mpp;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        vec[i] = {a,b};
        mpp[a]++;
        mpp[b+1]--;
    }
    ll ans = 0;
    for(auto it:mpp){
        ans+=it.second;
        if(ans>2){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
