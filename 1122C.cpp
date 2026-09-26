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
    ll total_zeros = 0;
    for(ll i=0;i<n;i++){
        if(s[i]=='0') total_zeros++;
    }
    if(s[0]=='1'){
        ll ans = 0;
        for(ll i=1;i<n;i++){
            if(s[i]!='1') ans++;
        }
        cout<<ans<<endl;
    }
    else{
        ll ans = 1e9;
        ll first_one = -1;
        for(ll i=0;i<n;i++){
            if(s[i]=='1'){
                first_one = i;
                break;
            }
        }
        if(first_one==-1){
            cout<<0<<endl;
            return;
        }
        ll ones = 0;
        ll zeros = total_zeros - first_one;
        ans = ones + zeros;
        for(ll i = first_one;i<n;i++){
            if(s[i]=='1') ones++;
            else{
                zeros--;
            }
            ans = min(ans,ones+zeros);
        }
        cout<<ans<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
