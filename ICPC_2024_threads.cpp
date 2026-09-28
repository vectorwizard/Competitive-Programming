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
    vector<int> x(n);
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<pair<int,int>> vec(n);
    for(int i=0;i<n;i++){
        vec[i] = {x[i],a[i]};
    }
    sort(vec.begin(),vec.end());
    
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}