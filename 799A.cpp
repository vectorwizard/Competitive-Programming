
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans = 0;
    if(b>a) ans++;
    if(c>a) ans++;
    if(d>a) ans++;
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}