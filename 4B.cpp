#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    string s;
    cin>>s;
    ll n = s.size();
    ll w = 0;
    vector<ll> prefix(n,0);
    vector<ll> suffix(n,0);
    for(ll i=1;i<n;i++){
        if(s[i]=='v' && s[i-1]=='v'){
            w++;
        }
        prefix[i] = w;
    }
    w=0;
    for(ll i=n-2;i>=0;i--){
        if(s[i]=='v' && s[i+1]=='v'){
            w++;
        }
        suffix[i] = w;
    }
    ll ans = 0;
    for(ll i=1;i<n-1;i++){
        if(s[i]=='o'){
            ans+=(prefix[i]*suffix[i]);
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
