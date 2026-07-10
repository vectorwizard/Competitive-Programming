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
    ll cnt = 0;
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='('){
            cnt++;
        }
        else {
            cnt--;
            if(cnt<0){
                cnt = 0;
                ans++;
            }
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
