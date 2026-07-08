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
    int msb = 32 - __builtin_clz(n-1);
    msb--;
    int num = (1<<msb);
    for(int i=num-1;i>=0;i--){
        cout<<i<<" ";
    }
    for(int i=num;i<=n-1;i++){
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
