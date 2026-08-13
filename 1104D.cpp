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
    ll ones = 0;
    ll zeros = 0;
    vector<ll> cnt = {1,0,0};
    ll ans = 0;
    for(ll i=0;i<n;i++){
        if(s[i]=='1') ones++;
        else zeros++;
        ll x = ((ones - zeros)%3 + 3)%3;
        ans+=(i+1);
        ans-=cnt[x];
        cnt[x]++;
    }
    ll len = 1;
    for(ll i=1;i<=n;i++){
        if(i<n && s[i]!=s[i-1]){
            len++;
        }
        else{
            ll even = (len+1)/2;
            ll odd = len - even;
            ans -= ((odd*(odd-1)/2)+(even*(even-1)/2));
            len = 1;
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
