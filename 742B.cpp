#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll get_xor(ll n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

void solve() {
    ll a,b;
    cin>>a>>b;
    ll xorr = get_xor(a-1);
    if(xorr==b){
        cout<<a<<endl;
        return;
    }
    if((xorr^b)==a){
        cout<<(a+2)<<endl;
    }
    else cout<<(a+1)<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
