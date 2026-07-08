#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int x,y;
    cin>>x>>y;
    if(x%2==1 && y%2==1){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
