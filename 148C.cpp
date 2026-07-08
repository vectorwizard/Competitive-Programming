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
    a.erase(unique(a.begin(),a.end()),a.end());
    int ans = 2;
    n = a.size();
    if(n==1){
        cout<<1<<endl;
        return;
    }
    for(int i=1;i<n-1;i++){
        if(((a[i]>a[i-1]) && (a[i]>a[i+1])) || ((a[i]<a[i-1]) && (a[i]<a[i+1]) )) ans++;
    }
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
