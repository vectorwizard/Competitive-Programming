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
    int target = a[n-1];
    int ans = 0;
    int i = n-2;
    while(i>=0){
        if(a[i]!=target){
            ans++;
            i-=(n-i-1);
        }
        else i--;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
