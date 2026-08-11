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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<=256;i++){
        int xorr = a[0]^i;
        for(int j=1;j<n;j++){
            xorr^=(a[j]^i);
        }
        if(xorr==0){
            cout<<i<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
