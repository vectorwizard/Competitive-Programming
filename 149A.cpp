#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int x,k;
    cin>>x>>k;
    if(x%k!=0){
        cout<<1<<endl;
        cout<<x<<endl;
        return;
    }
    cout<<2<<endl;
    cout<<x-1<<" "<<1<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
