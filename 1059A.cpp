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
    int maxi = 0;
    for(int i=0;i<n;i++){
        int total = 0;
        for(int j=i;j<n;j++){
            total+=a[j];
            maxi = max(maxi,(total/(j-i+1)));
        }
    }
    cout<<maxi<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}

