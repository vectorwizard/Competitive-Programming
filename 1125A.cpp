
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll x,y,r;
    cin>>x>>y>>r;
    for(ll i = -35;i<=35;i++){
        for(ll j = -35;j<=35;j++){
            ll disx = abs(x-i);
            ll disy = abs(y-j);
            ll temp = disx*disx + disy*disy;
            if(temp==(r*r)){
                cout<<i<<" "<<j<<endl;
                return;
            }
        }
    }
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}