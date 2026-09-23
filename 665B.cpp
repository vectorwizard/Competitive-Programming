#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


void solve() {
    ll x1,y1,z1;
    cin>>x1>>y1>>z1;
    ll x2,y2,z2;
    cin>>x2>>y2>>z2;
    ll ans = min(z1,y2);
    z1-=ans;
    y2-=ans;
    ans = ans*2;
    if(y1>(x2+y2)){
        ans -= (2*(y1-(x2+y2)));
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
