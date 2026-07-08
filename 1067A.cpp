#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int y,r,n;
    cin >> n;
    cin >> y >> r;
    if((y/2 + r)<n) cout<< (y/2+r)<<endl;
    else cout<< n<<endl;;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}