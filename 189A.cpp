#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll x,y;
    cin>>x>>y;
    ll ans = y/x;
    if(ans>=3){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
