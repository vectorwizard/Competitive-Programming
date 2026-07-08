#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll a,b,c,m;
    cin>>a>>b>>c>>m;
    ll a_alone = m/a;
    ll b_alone = m/b;
    ll c_alone = m/c;
    ll lcm_ab = m/lcm(a,b);
    ll lcm_bc = m/lcm(b,c);
    ll lcm_ca = m/lcm(c,a);
    ll lcm_abc = m/(lcm(lcm(a,b),c));
    ll ans_a = 6*a_alone - 3*lcm_ab - 3*lcm_ca + 2*lcm_abc;
    ll ans_b = 6*b_alone - 3*lcm_bc - 3*lcm_ab + 2*lcm_abc;
    ll ans_c = 6*c_alone - 3*lcm_ca - 3*lcm_bc + 2*lcm_abc;
    cout<<ans_a<<" "<<ans_b<<" "<<ans_c<<endl;
}

int main() {
    fastio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}