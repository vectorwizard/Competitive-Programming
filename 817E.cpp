#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,q;
    cin>>n>>q;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        int h,w;
        cin>>h>>w;
        a[i] = {h,w};
    }
    
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
