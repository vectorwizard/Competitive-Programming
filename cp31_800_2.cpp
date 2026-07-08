#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,x;
    cin>>n; cin>>x;
    vector<int> a;
    a.push_back(0);
    for(int i=0;i<n;i++){
        int y;
        cin>>y;
        a.push_back(y);
    }
    a.push_back(x);
    int maxi = 0;
    for(int i=1;i<=n;i++){
        maxi = max(maxi,a[i]-a[i-1]);
    }
    maxi = max(maxi,2*(a[n+1]-a[n]));
    cout<<maxi<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
