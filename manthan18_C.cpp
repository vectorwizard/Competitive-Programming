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
    string a,b;
    cin>>a>>b;
    int ans = 0;
    int i = 0;
    while(i<n){
        if(a[i]!=b[i]){
            if(i<n-1 && a[i+1]!=b[i+1] && a[i]!=a[i+1]){
                ans++;
                i+=2;
            }
            else{
                ans++;
                i++;
            }
        }
        else i++;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}