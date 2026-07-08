#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin>>n;
    int l = n/2;
    int r = l+1;
    while(l>=1 && r<=n){
        cout<<r<<" ";
        cout<<l<<" ";
        r++; l--;
    }
    while(r<=n) {
        cout<<r<<" ";
        r++;
    }
    cout<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}