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
    ll x = 0;
    for(ll i=1;i<=n-3;i++){
        cout<<i<<" ";
        x^=i;
    }
    cout<<n-1<<" ";
    x^=(n-1);
    ll a = 1LL<<29;
    ll b = (a^x);
    cout<<a<<" "<<b<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
