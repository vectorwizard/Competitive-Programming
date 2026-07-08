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
    int ans = 0;
    for(int i=0;i<n;i++) cin>>a[i];
    int maxi = -1;
    for(int i=0;i<n;i++){
        maxi = max(maxi,a[i]);
    }
    for(int i=0;i<n;i++){
        if(a[i]==maxi) ans++;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}
