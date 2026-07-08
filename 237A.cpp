#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int x,y,z;
    vector<int> a(3);
    for(int i=0;i<3;i++) cin>>a[i];
    sort(a.begin(),a.end());
    if((a[0]+a[1])>a[2]){
        cout<<0<<endl;
        return;
    }
    cout<<(a[2]-(a[0]+a[1])+1)<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
