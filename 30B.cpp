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
    string s;
    cin>>s;
    map<ll,ll> mpp;
    mpp[0] = -1;
    ll cnt = 0;
    ll ans = 0;
    for(ll i=0;i<n;i++){
        if(s[i]=='1') cnt++;
        else cnt--;
        if(mpp.count(cnt)){
            ans = max(ans,i-mpp[cnt]);
        }
        else mpp[cnt] = i;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
