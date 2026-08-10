#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k;
    cin>>n>>k;
    if(n%2==1 && k%2==0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
