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
    ll cnt = 1;
    for(ll i=1;i<n;i++){
        if(s[i]!=s[i-1]) cnt++;
    }
    bool fl = false;
    ll x = 0;
    for(ll i=1;i<n-1;i++){
        if((s[i-1]==s[i+1]) && (s[i-1]!=s[i]) && (s[i+1]!=s[i])){
            fl = true;
            x = 2;
            break;
        } 
        else if(s[i-1]!=s[i] && s[i]!=s[i+1] && s[i-1]!=s[i+1]) x = 1;
    }
    cout<<(cnt-x)<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
