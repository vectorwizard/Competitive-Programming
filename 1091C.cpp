#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if(__gcd(n,a)==1 && __gcd(m,b)==1 && 2>=__gcd(n,m)){
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
