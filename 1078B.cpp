#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> prefix(n);
    ll sum = 0;
    for(int i=0;i<n;i++){
        prefix[i] = a[i]/x;
        sum+=prefix[i];
    }
    ll maxi = LLONG_MIN;
    for(int i=0;i<n;i++){
        ll cost = (sum-prefix[i]);
        maxi = max(maxi,(1LL*y*cost)+a[i]);
    }
    cout<<maxi<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}