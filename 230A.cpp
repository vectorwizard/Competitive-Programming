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
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.rbegin(),a.rend());
    int ans = 0;
    for(int i=0;i<n;i++){
        if(k>0){
            if(a[i]<=5) break;
            ans += (a[i]-5);
            k--;
        }
        else{
            if(a[i]<=10) break;
            ans += (a[i]-10);
        }
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
