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
    string ans = "";
    for(ll i=0;i<n;i++) ans+='z';
    int ansk=-1;
    for(ll k=1;k<=n;k++){
        string prefix = s.substr(0,k-1);
        string suffix = s.substr(k-1);
        if((n-k)%2==0) reverse(prefix.begin(),prefix.end());
        string temp =suffix + prefix;
        if(temp<ans){
            ans = temp;
            ansk = k;
        }
    }
    cout<<ans<<endl;
    cout<<ansk<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}