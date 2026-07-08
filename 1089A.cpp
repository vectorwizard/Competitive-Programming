#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 676767677;
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin>>n;
    for(int i=n;i>=1;i--){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}