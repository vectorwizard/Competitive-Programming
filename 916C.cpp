#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int maxi = 0;
    vector<int> prefix(n,0);
    vector<int> prefixmax(n,0);
    prefix[0] = a[0];
    prefixmax[0] = b[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1] + a[i];
        prefixmax[i] = max(prefixmax[i-1],b[i]);
    }
    int lim = min(n,k);
    for(int i=0;i<lim;i++){
        int x = prefix[i];
        int rem = (k-i-1);
        x+=(rem*prefixmax[i]);
        maxi = max(maxi,x);
    }
    cout<<maxi<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
