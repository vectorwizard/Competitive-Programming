#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int a,b,n;
    cin>>a; cin>>b; cin>>n;
    if(b!=a && 1LL*b*n>a) cout<<2<<endl;
    else cout<<1<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
