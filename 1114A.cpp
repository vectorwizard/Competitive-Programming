#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    vector<int> a(3);
    cin>>a[0]>>a[1]>>a[2];
    sort(a.begin(),a.end());
    int ans = (a[2]-a[1]);
    ans = min(ans,a[1]-a[0]);
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
