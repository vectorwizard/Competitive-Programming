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
    string t = "";
    ll ans = 0;
    for(ll i=0;i<n;i+=2){
        string sub = s.substr(i,2);
        if(sub=="bb" || sub=="aa"){
            ans++;
            t+="ab";
        }
        else t+=sub;
    }
    cout<<ans<<endl;
    cout<<t<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}