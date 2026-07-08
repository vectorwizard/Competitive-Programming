#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int mod = 998244353;
void solve() {
    ll n,x;
    cin>>n>>x;
    n++;
    ll a = x/4;
    ll rem1 = x%4;
    ll n1 = a, n3 = a;
    if(rem1>=2) n1++;
    ll rem_total = n%4;
    ll total1=n/4,total3 = n/4;
    if(rem_total>=2) total1++;
    ll m1 = total1-n1;
    ll m3 = total3-n3;
    m1 = (m1%mod);
    m3 = (m3%mod);
    n1 = (n1%mod);
    n3 = (n3%mod);
    ll ans = (n1*m1)%mod;
    ans = (ans+(n3*m3)%mod)%mod;
    ans=(ans+m3)%mod;
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
