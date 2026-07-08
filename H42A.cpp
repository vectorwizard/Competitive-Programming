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
    unordered_map<ll,ll> mpp;
    ll cnt = 0;
    ll ans = 0;
    mpp[0] = 1;
    for(ll i=0;i<n;i++){
        if(s[i]=='1') cnt++;
        else cnt--;
        ll x=0;
        if(mpp.find(cnt)!=mpp.end()){
            x = mpp[cnt];
        }
        ans += (i-x+1);
        ans+=(x*2);
        mpp[cnt]++;
    }
    cout<<ans<<endl;
}  

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
