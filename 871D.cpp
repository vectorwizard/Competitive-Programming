#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(int n,int m){
    if(n==m) return true;
    if(n<m || n%3!=0) return false;
    return func(n/3,m) | func(n-(n/3),m);
}

void solve() {
    int n,m;
    cin>>n>>m;
    bool ans = func(n,m);
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
