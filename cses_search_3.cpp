#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int l = 0;
    int r = n-1;
    int ans = 0;
    sort(a.begin(),a.end());
    while(l<r){
        if(a[l]+a[r]<=x){
            ans++;
            l++;
            r--;
        }
        else{
            r--;
            ans++;
        }
    }
    if(l==r) ans++;
    cout<<ans<<endl;
}  

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
