#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    vector<int> a(7);
    for(int i=0;i<7;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int total = 0;
    for(int i=0;i<6;i++){
        total = total - a[i];
    }
    total+=a[6];
    cout<<total<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}