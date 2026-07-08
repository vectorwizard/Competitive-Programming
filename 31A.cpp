#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int l,a,b;
    cin>>l; cin>>a ; cin>>b;
    int ans = 0;
    int pos = a;
    for(int i=1;i<=l;i++){
        pos = (a+i*b)%l;
        ans = max(ans,pos);
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
