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
    int zero = 0;
    int one = 0;
    for(int i=0;i<n;i++){
        if(a[i]==0) zero++;
        else one++;
    }
    if(zero<=one){
        cout<<"Bessie"<<endl;
    }
    else cout<<"Elsie"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}