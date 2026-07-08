#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 676767677;
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int ans = 0;
    for(int i=1;i<n-1;i++){
        int gcd_1 = gcd(a[i-1],a[i]);
        int gcd_2 = gcd(a[i],a[i+1]);
        int lcmm = lcm(gcd_1,gcd_2);
        if(lcmm<a[i]) ans++;
    }
    if(gcd(a[0],a[1])<a[0]) ans++;
    if(gcd(a[n-2],a[n-1])<a[n-1]) ans++;
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}