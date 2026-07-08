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
    if(n==1) cout<<1<<endl;
    else if(n==2) cout<<2<<" "<<2<<endl;
    else{
        for(int i=0;i<n;i++) cout<<2<<" ";
        cout<<endl;
    }
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}