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
    for(int i=0;i<n;i++){
        int target = a[i];
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]){
                a[j] = a[i];
                break;
            }
        }
    }
    int ans = accumulate(a.begin(),a.end(),0);
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
