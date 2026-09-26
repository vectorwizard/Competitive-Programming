#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll a,b,c;
    cin>>a>>b>>c;
    ll diff = abs(a-b);
    if(abs(a+c-b)>diff){
        cout<<abs(a+c-b)<<endl;
    }
    else cout<<diff<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
